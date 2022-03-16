#pragma once

#include <assert.h>
#include <bits/stdint-uintn.h>
#include <type_traits>
#include <mutex>

#include "../common/spinlock.h"

#include "intrusive_queue.h"
#include "tslist.h"

namespace rco {

	// TS Thread Safe
	template <typename T, bool TSFlag = true>
		class TSQueue {

			static_assert(std::is_base_of<Intrusive_queue, T>::value, "template type must inherit Intrusive_queue");

			public:
			using lock_t = typename std::conditional<TSFlag, Spink_lock, Virtual_lock>;
			using lock_guard = std::lock_guard<lock_t>;

			TSQueue()
				: head(new Intrusive_queue)
				  , tail(head)
				  , count(0)
				  , lock(own_lock){
				  }

			~TSQueue() {
				lock_guard scope_lock(*lock);
				while(head != tail) {
					Intrusive_queue* pre = tail->prev;
					DecrementRef((T*)tail);
					tail = pre;
				}
				delete head;
				head = tail = nullptr;
			}

			void set_lock(lock_t* plock) {
				lock = plock;
			}

			RCO_INLINE lock_t& lock_ref() {
				return *lock;
			}

			RCO_INLINE T* front() {
				lock_guard scope_lock(*lock);
				T* out = (T*)head->next;
				if(out) {
				}
				return out;
			}

			RCO_INLINE T* next(T* ptr) {
				lock_guard scope_lock(*lock);
				return nolock_next(ptr);
			}

			RCO_INLINE T* nolock_next(T* ptr) {
				T* out = ptr->next;
				return out;
			}

			RCO_INLINE bool ts_empty() {
				lock_guard scope_lock(*lock);
				return !count;
			}

			RCO_INLINE bool empty() {
				return !count;
			}

			RCO_INLINE std::size_t size() {
				lock_guard scope_lock(*lock);
				return count;
			}

			RCO_INLINE T* pop() {
				// 头部等于尾部说明队列为空
				if(head == tail) return nullptr;
				lock_guard scope_lock(*lock);
				if(head == tail) return nullptr;

				// 如果只有一个元素
				Intrusive_queue* ptr = head->next;
				if(ptr == tail) tail = head;

				head->next = ptr->next;

				if(ptr->next) ptr->next->prev = head;
				ptr->prev = ptr->next = nullptr;

				--count;

				DecrementRef((T*)ptr);

				return (T*)ptr;
			}


			RCO_INLINE void push(TSList<T> && elements) {
				if(elements.empty()) return;
				lock_guard scope_lock(*lock);
				nolock_push(elements);
			}

			RCO_INLINE void nolock_push(TSList<T>&& elements) {
				if(elements.empty()) return;
				assert(elements.list_head->prev == nullptr);
				assert(elements.list_tail->next == nullptr);

				Intrusive_queue* list_head = elements.list_head;

				count += elements.size();
				tail->link(list_head);

				tail = elements.list_tail;
				elements.stealed();
			}

			RCO_INLINE size_t push(T* element) {
				lock_guard scope_lock(*lock);
				return nolock_push(element);
			}

			RCO_INLINE size_t nolock_push(T* element, bool ref_count = true) {
				Intrusive_queue* elem = static_cast<Intrusive_queue*>(element);
				assert(elem->prev == nullptr);
				assert(elem->next == nullptr);

				tail->link(elem);
				tail = elem;

				elem->next = nullptr;

				++count;

				if(ref_count) {
					IncrementRef(element);
				}

				return count;
			}

			RCO_INLINE TSList<T>&& trunc_front(uint32_t n) {
				if(head == tail) return TSList<T>();
				lock_guard scope_lock(*lock);
				if(head == tail) return TSList<T>();
				if(n > count) return TSList<T>(head->next, tail, count);

				Intrusive_queue* first = head->next;
				Intrusive_queue* last = first;
				uint32_t cnt = 1;

				// 遍历到第n个元素
				for(; cnt < n && last->next; ++cnt) {
					last = last->next;
				}

				if(last == tail) tail = head;
				head->next = last->next;

				if(last->next) last->next->prev = head;
				first->prev = last->next = nullptr;
				count -= cnt;

				return std::move(TSList<T>(first, last, cnt));
			}

			RCO_INLINE TSList<T>&& trunc_back(uint32_t n) {
				if(head == tail) return TSList<T>();

				return nolock_trunc_back(n);
			}

			RCO_INLINE TSList<T>&& nolock_trunc_back(uint32_t n) {
				if(head == tail) return TSList<T>();
				if(n > count) return TSList<T>(head->next, tail, count);

				Intrusive_queue* last = tail;
				Intrusive_queue* first = last;
				uint32_t cnt = 1;

				for(; cnt < n && first->prev != head; ++cnt) {
					assert(first->prev != nullptr);
					first = first->prev;
				}

				tail = first->prev;
				first->prev = tail->next = nullptr;
				count -= cnt;
				return std::move(TSList<T>(first, last, cnt));
			}

			RCO_INLINE TSList<T>&& pop_all() {
				if(head == tail) return TSList<T>();
				lock_guard scope_lock(*lock);
				return nolock_pop_all();
			}

			RCO_INLINE TSList<T>&& nolock_pop_all() {
				if(head == tail) return TSList<T>();
				Intrusive_queue* first = head->next;
				Intrusive_queue* last = tail;

				tail = head;

				head->next = nullptr;
				first->prev = last->prev = nullptr;

				size_t cnt = count;
				count = 0;

				return std::move(TSList<T>(first, last, cnt));
			}

			RCO_INLINE bool erase(T* element) {
				lock_guard scope_lock(*lock);

			}

			RCO_INLINE bool nolock_erase(T* element, bool ref_count = true) {
				assert(element->prev != nullptr);
				assert(element == tail || element->next != nullptr);

				if(element->prev) element->prev->next = element->next;
			}

			private:

			lock_t	own_lock;
			lock_t* lock;
			Intrusive_queue* head;
			Intrusive_queue* tail;

			std::size_t count;
		};

}
