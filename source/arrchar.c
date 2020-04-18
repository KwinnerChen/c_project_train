// arrchar.c -- 指针数组字符串数组

#include <stdio.h>
#define SLEN 40
#define LIM 5

int main(void)
{
    const char *mytalents[] = {                    //多维数组的第一个长度可以省略，[]优先级高于*
        "adding numbers swiftly",
        "multiplying accurately",
        "stashing data",
        "following instructions to the letter",
        "understanding the C language"
    };

    char yourtalents[][SLEN] = {
        "walking in a staight line",
        "sleeping",
        "watching television",
        "mailing letters",
        "reading email"
    };

    puts("\nlet's compare talents.\n");
    printf("%-36s %-25s\n\n", "my talents", "your talents");

    for (int i=0; i<LIM; i++)
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);            //指针表示*(mytalents+i), *(yourtalents+i)

    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n\n",
           sizeof mytalents, sizeof yourtalents);
    
    return 0;
}