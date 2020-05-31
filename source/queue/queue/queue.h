//
//  queue.h
//  queue
//
//  Created by hafu on 2020/5/20.
//  Copyright © 2020 hafu. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include <stdbool.h>

// 队列元素，内容
typedef int Item;

// 队列节点
typedef struct node {
    Item item;
    struct node * next;
} Node;

// 队列结构，指向开始结尾，队列节点数量
typedef struct queue {
    Node * front;
    Node * rear;
    unsigned int count;
} Queue;

/* 操作：初始化队列
 * 前提条件：pq指向一个队列
 * 后置条件：队列背出话为空
 */
void init(Queue * pq);

/* 操作：查询队列是否已满
 * 潜质条件：pq指向已初始化的队列
 * 后置条件：更具查询结果返回真假值
 */
bool QueueIsFull(const Queue * pq);

/* 操作：查询队列是否为空
 * 前置条件：pq指向已初始化的队列
 * 后置条件：根据查询结果返回真假值
 */
bool QueueIsEmpty(const Queue * pq);

/* 操作：查询队列中的项数
 * 前置条件：pq指向已初始化队列
 * 后置条件：返回查询结果，无符号整型
 */
unsigned int QueueCount(const Queue * pq);

/* 操作：入队，在队尾添加项
 * 前置条件：pq指向已初始化的队列
           item是Item实例
 * 后置条件：返回插入结果真假值
 */
bool EnQueue(Item item, Queue * pq);

/* 操作：FIFO队列，从队首获取元素
 * 前置条件：pq指向已初始化的队列
 * 后置条件：如果队列不为空，队首元素拷贝到*pitem
           队列中删除释放内存，返回true
           如果该操作使队列为空，重制队列为空
           如果是空队列返回false
 */
bool DeQueue(Item *pitem, Queue *pq);

/* 操作：清空队列
 * 前置条件：pq指向初始化的队列
 * 后置条件：队列被清空
 */
void PurgeQueue(Queue * pq);

#endif /* queue_h */
