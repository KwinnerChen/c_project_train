// 这是一个用于测试的源码文件

#include <stdio.h>
#include <string.h>
#include <math.h>
#define SLEN 22

char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);

    if (result)
    {
        find = strchr(string, '\n');

        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }

    return result;
}

void iter_string(char * string, int n)
{
    char zhstring[4];
    char * tmp_pt;

    for (int i=0; i<n; i+=3)
    {
        strncpy(zhstring, string, 3);
        if (zhstring[0] == '\0')
        {
            break;
        }
        zhstring[3] = '\0';
        printf("%s\n", zhstring);
        string += 3;
    }
}

int main (void)
{
    char input_string[SLEN];
    
    printf("输入一段话，后边将迭代显示（空行退出）：");

    while (s_gets(input_string, SLEN))
    {
        iter_string(input_string, SLEN);
        if (input_string[0] == '\0')
        {
            break;
        }
        printf("输入一段话，后边将迭代显示（空行退出）：");
    }

    printf("再见！\n");
    
    return 0;
}