//
//  queue.c
//  queue
//
//  Created by hafu on 2020/5/20.
//  Copyright © 2020 hafu. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"
#define MAXQUEUE 10

// 内部函数函数原型
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * nodep, Item * pitem);

// 初始化队列
void init(Queue * pq) {
    pq -> front = pq -> rear = NULL;
    pq -> count = 0;
}

// 判断队列是否为空
bool QueueIsEmpty(const Queue * pq) {
    return pq -> count == 0;
}

// 判断队列是否已满
bool QueueIsFull(const Queue * pq) {
    if (MAXQUEUE)
        return pq -> count == MAXQUEUE;
    else {
        Node * ptmp;
        ptmp = (Node *) malloc(sizeof(Node));
        if (ptmp != NULL)
            return true;
        else
            return false;
    }
}

// 内部方法，拷贝元素到指定位置
static void CopyToNode(Item item, Node * pn) {
    pn -> item = item;
}

// 添加新节点到队尾
bool EnQueue(Item item, Queue * pq) {
    Node * newitemp;
    
    newitemp = (Node *) malloc(sizeof(Node));
    if (newitemp == NULL) {
        fprintf(stderr, "没有足够的内存进行分配！");
        exit(1);
    }
    
    CopyToNode(item, newitemp);
    newitemp -> next = NULL;
    
    if (QueueIsEmpty(pq)) {
        pq -> front = newitemp;
    }
    else {
        pq -> rear -> next = newitemp;                                        // 原队尾节点的下一节点指向新节点
    }
    pq -> rear = newitemp;
    pq -> count++;
    
    return true;
}

// 内部方法，将项目由节点拷贝到指定位置
static void CopyToItem(Node * nodep, Item * pitem) {
    *pitem = nodep -> item;
}

// 获取队列首项
bool DeQueue(Item * pitem, Queue * pq) {
    Node * tp;
    
    if (QueueIsEmpty(pq)) {
        return false;
    }
    
    CopyToItem(pq -> front, pitem);                                            // 由节点拷贝到pitem指向的item
    tp = pq -> front;
    pq -> front = pq -> front -> next;                                         // 移动头部指针到下一节点
    free(tp);                                                                  // 释放内存
    pq -> count--;                                                             // 项数相应减少
    
    if (pq -> count == 0) {
        pq -> rear = NULL;                                                     // 当队列归零
    }
    
    return true;
}

// 清空队列到初始态
void PurgeQueue(Queue * pq) {
    Item temp;
    
    while (pq -> count != 0) {
        DeQueue(&temp, pq);
    }
}
