#include <stdio.h>
#include <stdbool.h>
#include "movies_list.h"
#include <string.h>
#include <stdlib.h>

char * s_gets(char * input, int n) {
    char * ret_val;
    char * find;

    ret_val = fgets(input, TSIZE, stdin);
    if (ret_val) {
        find = strchr(input, '\n');
        if (find) {
            *find = '\0';
        }
        else {
            while (getchar() != '\n')
            {
                continue;
            }  
        }
    }
    return ret_val;
}

void showmovies(Item item) {
    printf("电影：%s 评分：%d\n", item.title, item.rating);
}

int main(void) {
    List movies;
    Item temp;

    init(&movies);
    if (listisfull(&movies)) {
        fprintf(stderr, "没有多余内存");
        exit(1);
    }

    printf("输入电影名（空行退出）：");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
         printf("输入评分<1-10>：");
         scanf("%d", &temp.rating);
         while (getchar() != '\n')
         {
             continue;
         }

         if (additem(temp, &movies) == false) {
             fprintf(stderr, "添加出错，可能内存分派错误");
             break;
         }
         if(listisfull(&movies)) {
             fprintf(stderr, "内存已满");
             break;
         }
         printf("输入电影名字（空行退出）：");     
    }

    if (listisempty(&movies)) {
        printf("还没有数据");
    }
    else {
        printf("电影清单：\n");
        traverse(&movies, showmovies);
        printf("总共有电影：%d\n", listitemcount(&movies));
    }

    emptythelist(&movies);
    return 0;
}
