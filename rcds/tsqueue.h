#pragma once

#include <assert.h>
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
					Intrusive_queue* pre = tail->pre;
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

				if(ptr->next) ptr->next->pre = head;
				ptr->pre = ptr->next = nullptr;

				--count;


				return (T*)ptr;
			}

			private:

			lock_t	own_lock;
			lock_t* lock;
			Intrusive_queue* head;
			Intrusive_queue* tail;

			std::size_t count;
		};

}
