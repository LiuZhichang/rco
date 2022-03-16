#pragma once

#include <assert.h>

#include "../common/internal.h"

namespace rco {

	/**
	 * @brief 侵入式队列基类，一个对象代表队列中的一个节点
	 */
	class Intrusive_queue {
		public:
			Intrusive_queue* prev;	// 前驱元
			Intrusive_queue* next;	// 后继元
			void*check = nullptr;

			Intrusive_queue()
				: prev(nullptr)
				  , next(nullptr) {

				  }

			/**
			 * @brief 将一个节点链接到本节点之后
			 *
			 * @param[in] next_queue 目标节点
			 *
			 * @return void
			 */
			RCO_INLINE void link(Intrusive_queue* next_queue) {
				// 本节点后继元必须为空
				assert(next == nullptr);
				// 链接目标的前驱元必须为空
				assert(next_queue->prev == nullptr);

				// 链接
				next = next_queue;
				next_queue->prev = this;
			}

			/**
			 * @brief 将本节点链接的节点断开
			 *
			 * @param[in] next_queue 本节点链接的节点
			 *
			 * @return void
			 */
			RCO_INLINE void unlink(Intrusive_queue* next_queue) {
				// 必须是本节点链接的节点
				assert(next == next_queue);
				// 目标节点的前驱元必须是本节点
				assert(next_queue->prev == this);

				next = nullptr;
				next_queue->prev = nullptr;
			}

	};

}
