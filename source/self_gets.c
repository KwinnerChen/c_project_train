// s_gets.c -- 自定义输入源码

#include <stdio.h>
#include <string.h>
#include "self_gets.h"

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);                // 由stdin读取n-1个字符，合并空字符赋值给数组st。返回该数组地址

    if (ret_val)
    {
        find = strchr(st, '\n');    // 检查字符读取字符是否完整（有无换行符），且最终字符索引指向换行符或空字符位置
          
        if (find)                        // 不保留换行符
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')             // 如果读取字符不完整，则舍弃其他字符
            {
                continue;
            }
        }
    }

    return ret_val;
}