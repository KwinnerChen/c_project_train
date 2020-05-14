//
//  main.c
//  movies_list
//
//  Created by hafu on 2020/5/14.
//  Copyright © 2020 hafu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movies_list.h"

char * s_gets(char *, int);
void showmovies(Item);

char * s_gets(char * input, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(input, n, stdin);
    if (ret_val)
    {
        find = strchr(input, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    
    return ret_val;
}

void showmovies(Item item)
{
    printf("电影：%s 评分：%d\n", item.title, item.rating);
}

int main(int argc, const char * argv[]) {
    List movies;
    Item temp;
    
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "没有多余内存！");
        exit(1);
    }
    
    // 获取用户输入
    printf("输入电影名（空行退出）：");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        printf("输入评分<1-10>：");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') {
            continue;
        }
        
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "添加出错，可能是内存分派错误");
            break;
        }
        if (ListIsFull(&movies))
        {
            fprintf(stderr, "内存已满，没有位置继续添加");
            break;
        }
        printf("输入电影名（空行退出）：");
    }
    
    // 显示输入内容
    if (ListIsEmpty(&movies))
    {
        printf("还没有数据\n");
    }
    else
    {
        printf("电影清单：\n");
        Traverse(&movies, showmovies);
        printf("总共有电影：%d\n", ListItemCount(&movies));
    }
    
    // 清空所有malloc内存
    EmptyTheList(&movies);
    
    return 0;
}
