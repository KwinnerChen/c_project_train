// scanf1.c -- 使用scanf获取汉子输入

#include <stdio.h>
#define LEN 10

int main(void)
{
    char words [LEN];

    while (fgets(words, LEN, stdin) && words[0] != '\n')  // fgets(words, LEN, stdin) != NULL
    {
        // printf("%s\n", words);
        printf("%s", words);
    }

    printf("完成\n");

    return 0;
    
}