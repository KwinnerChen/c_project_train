//
//  movies_list.c
//  movies_list
//
//  Created by hafu on 2020/5/14.
//  Copyright © 2020 hafu. All rights reserved.
//

#include <stdio.h>
#include "movies_list.h"
#include <stdlib.h>                                              // 提供malloc和free函数

static void CopyToNode(Item item, Node * pnode);                 // 局部函数原型，函数静态存储类型，文件作用域，无链接

/* 局部函数 */
void CopyToNode(Item item, Node * pnode)
{
    pnode -> item = item;
}

/* 接口函数 */
// 初始化链表，把链表置为空
void InitializeList(List * plist)
{
    *plist = NULL;                                               // 指针指向一个空值
}

// 如果链表为空返回true
bool ListIsEmpty(const List * plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}

// 若果链表已满返回true
bool ListIsFull(const List * plist)
{
    Node * pt;                                                  // 虽然函数不会改变plist指向的链表的值
    bool full;                                                  // 但是会改变plist的值，造成链表首地址丢失
                                                                // 所以函数内需要plist的副本
    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    
    return full;
}

// 返回节点数量
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pt = *plist;
    
    while (pt != NULL) {
        ++count;
        pt = pt -> next;
    }
    
    return count;
}

// 创建存储项的节点，并将其添加至plist指向的链表的结尾（较慢的实现）
bool AddItem(Item item, List * plist)
{
    Node * newnd;
    Node * scan = *plist;
    
    newnd = (Node *) malloc(sizeof(Node));
    if (newnd == NULL)
        return false;
    
    CopyToNode(item, newnd);                                    // newnd -> item = item;
    newnd -> next = NULL;
    
    if (scan == NULL)
        *plist = newnd;
    else
    {
        while (scan->next != NULL) {
            scan = scan -> next;
        }
        scan -> next = newnd;
    }
    
    return true;
}

// 为每个节点执行pfun函数
void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = *plist;
    
    while (pnode != NULL) {
        (*pfun)(pnode -> item);
        pnode = pnode -> next;
    }
}

// 释放malloc分配的内存
void EmptyTheList(List * plist)
{
    Node * psave;
    
    while (*plist != NULL) {
        psave = (*plist) -> next;
        free(*plist);
        *plist = psave;
    }
}
