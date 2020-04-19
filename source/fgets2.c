// fgets2.c -- 使用fgets()和fputs()

#include <stdio.h>
#define STLEN 10

int main(void)
{
    char words [STLEN];  // 定义一个字符数组，存储字符串

    puts("输入一个字符串（空行退出）：");

    while (fgets(words, STLEN, stdin)!=NULL && words[0]!='\n')  // 迭代从输入缓冲中读取字符存入字符数组
    {                                                           // 每次读取STLEN-1个字符，没有遇到换行符时截断并自动添加空字符\0
        fputs(words, stdout);                                   // 遇到换行符后保持换行符的同时添加一个空字符，停止迭代缓冲。
    }
    puts("完成！");

    return 0;
}