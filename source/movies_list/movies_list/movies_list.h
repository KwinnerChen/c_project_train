//
//  movies_list.h
//  movies_list
//
//  Created by hafu on 2020/5/14.
//  Copyright © 2020 hafu. All rights reserved.
//

#ifndef movies_list_h
#define movies_list_h

#include <stdbool.h>                        // 提供bool，true，false支持
#define TSIZE 45

typedef struct film {                       // 电影信息的基本结构
    char title[TSIZE];
    int rating;
} Item;

typedef struct node {                       // 链表中的节点
    Item item;
    struct node * next;
} Node;

typedef Node * List;                        // 指向链表的第一个节点

//typedef struct list {
//    Node * head;
//    Node * end;
//    unsigned int count;
//} List;

/* 函数原型定义 */


// 操作：初始化一个链表
// 前提条件：plist指向一个链表
// 后置条件：链表初始化为空
void InitializeList(List * plist);


// 操作：确认链表是否为空，plist指向一个已初始化链表
// 后置条件：如果链表为空则返回true，否则返回false
bool ListIsEmpty(const List * plist);


// 操作：确认链表是否已满，plist指向一个已初始化链表
// 后置操作：如果链表已满则返回true，否则返回false
bool ListIsFull(const List * plist);


// 操作：确定链表中的项数，plist指向一个已初始化的链表
// 后置操作：返回链表中的项数
unsigned int ListItemCount(const List * plist);


// 操作：在链表末尾添加项
// 前提条件：item是一个待添加至链表的项（结构），plist指向一个初始化的链表
// 后置条件：如果可以，该函数在链表末尾添加一个项，并返回true或者false
bool AddItem(Item item, List * plist);


// 操作：把函数作用于链表的每一项
//      plist指向一个初始化的链表
//      pfun指向一个函数，接受一个Item类型参数，且没有返回值
// 后置条件：pfun作用于链表的每一项
void Traverse(const List * plist, void (*pfun) (Item item));


// 操作：释放已分配的内存（如果有的话）
//      plist指向一个初始化的链表
// 后置条件：释放为链表分配的内存，链表置为空
void EmptyTheList(List * plist);


#endif /* movies_list_h */
