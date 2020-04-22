// copy3.c -- 使用strncpy()

#include <stdio.h>
#include <string.h>
#include "self_gets.h"
#define SIZE 40
#define TARGSIZE 7
#define LIM 5

int main(void)
{
    char qwords[LIM][TARGSIZE];
    char temp[SIZE];
    int i = 0;

    printf("输入%d个q开头的单词：\n", LIM);

    while (i< LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'q')
        {
            printf("%s不是且开头的单词。\n", temp);
        }
        else
        {
            strncpy(qwords[i], temp, TARGSIZE-1);
            qwords[i][TARGSIZE-1] = '\0';
            i++;
        }       
    }

    puts("下面是接受到的单词：");
    for (i=0; i<LIM; i++)
        puts(qwords[i]);

    return 0;
}
    