#pragma once

#include "intrusive_queue.h"
#include <type_traits>
#include <utility>

namespace rco {

	/**
	 * @brief 侵入式双向链表
	 *
	 * @tparam T 必须为继承了Intrusive_queue的类型
	 */
	template <typename T>
		class TSList {
			// 静态断言
			static_assert(std::is_base_of<Intrusive_queue, T>::value, "T must inherit Intrusive_queue");
			public:

			/**
			 * @brief 迭代器
			 */
			struct iterator
			{
				T* ptr;		// 元素指针
				T* prev;	// 前驱元
				T* next;	// 后继元

				/**
				 * @brief 迭代器无参构造
				 */
				iterator() : ptr(nullptr), prev(nullptr), next(nullptr) {

				}
				iterator(T* p) {
					reset(p);
				}
				void reset(T* p) {
					ptr = p;
					next = ptr ? (T*)ptr->next : nullptr;
					prev = ptr ? (T*)ptr->prev : nullptr;
				}

				/**
				 * @brief 符号重载
				 */

				//
				friend bool operator==(iterator const& lhs, iterator const& rhs) {
					return lhs.ptr == rhs.ptr;
				}
				friend bool operator!=(iterator const& lhs, iterator const& rhs) {
					return !(lhs.ptr == rhs.ptr);
				}

				iterator& operator++() {
					reset(next); return *this;
				}
				iterator operator++(int) {
					iterator ret = *this; ++(*this); return ret;
				}
				iterator& operator--() {
					reset(prev); return *this;
				}
				iterator operator--(int) {
					iterator ret = *this; --(*this); return ret;
				}
				T& operator*() {
					return *(T*)ptr;
				}
				T* operator->() {
					return (T*)ptr;
				}
			};


			TSList() : list_head(nullptr), list_tail(nullptr), element_count(0) {

			}

			/**
			 * @brief list构造函数
			 *
			 * @param[in] h 头元素
			 * @param[in] t 尾元素
			 * @param[in] element_count 元素个数
			 */
			TSList(Intrusive_queue* h, Intrusive_queue* t, std::size_t count)
				: list_head((T*)h), list_tail((T*)t), element_count(count) {

				}

			TSList(TSList const&) = delete;
			TSList& operator=(TSList const&) = delete;

			/**
			 * @brief 移动构造
			 *
			 * @param[in] other list对象
			 */
			TSList(TSList<T> && other) {
				list_head = other.list_head;
				list_tail = other.list_tail;
				element_count = other.element_count;
				other.stealed();
			}

			/**
			 * @brief 赋值构造 
			 *
			 * @param[in] other list对象
			 *
			 * @return
			 */
			TSList& operator=(TSList<T> && other) {
				clear();
				list_head = other.list_head;
				list_tail = other.list_tail;
				element_count = other.element_count;
				other.stealed();
				return *this;
			}

			/**
			 * @brief
			 *
			 * @param[in] other
			 */
			void append(TSList<T> && other) {
				if (other.empty())
					return ;

				if (empty()) {
					*this = std::move(other);
					return ;
				}

				list_tail->link(other.list_head);
				list_tail = other.list_tail;
				element_count += other.element_count;
				other.stealed();
			}

			/**
			 * @brief
			 *
			 * @param[in] n
			 *
			 * @return
			 */
			TSList<T> cut(std::size_t n) {
				if (empty()) return TSList<T>();

				if (n >= size()) {
					TSList<T> o(std::move(*this));
					return o;
				}

				if (n == 0) {
					return TSList<T>();
				}

				TSList<T> o;
				auto pos = list_head;
				for (std::size_t i = 1; i < n; ++i)
					pos = (T*)pos->next;
				o.list_head = list_head;
				o.list_tail = pos;
				o.element_count = n;

				element_count -= n;
				list_head = (T*)pos->next;
				pos->unlink(list_head);
				return o;
			}

			~TSList() {
				assert(element_count == 0);
			}

			iterator begin() {
				return iterator{list_head};
			}
			iterator end() {
				return iterator();
			}

			RCO_INLINE bool empty() const {
				return list_head == nullptr;
			}

			/**
			 * @brief
			 *
			 * @param[in] it
			 *
			 * @return
			 */
			iterator erase(iterator it) {
				T* ptr = (it++).ptr;
				erase(ptr);
				return it;
			}

			/**
			 * @brief
			 *
			 * @param[in] ptr
			 * @param[in] check
			 *
			 * @return
			 */
			bool erase(T* ptr, void *check) {
				if (ptr->check_ != check) return false;
				erase(ptr);
				return true;
			}

			/**
			 * @brief
			 *
			 * @param[in] ptr
			 */
			void erase(T* ptr) {
				if (ptr->prev) ptr->prev->next = ptr->next;
				else list_head = (T*)list_head->next;
				if (ptr->next) ptr->next->prev = ptr->prev;
				else list_tail = (T*)list_tail->prev;
				ptr->prev = ptr->next = nullptr;
				-- element_count;
				DecrementRef(ptr);
			}

			/**
			 * @brief
			 *
			 * @return
			 */
			std::size_t size() const {
				return element_count;
			}

			/**
			 * @brief
			 */
			void clear() {
				auto it = begin();
				while (it != end())
					it = erase(it);
				stealed();
			}

			/**
			 * @brief
			 */
			void stealed() {
				list_head = list_tail = nullptr;
				element_count = 0;
			}

			RCO_INLINE Intrusive_queue* head() {
				return list_head;
			}
			RCO_INLINE Intrusive_queue* tail() {
				return list_tail;
			}

			T* list_head;
			T* list_tail;
			std::size_t element_count;
		};

}
