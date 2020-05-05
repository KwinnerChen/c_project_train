// booksave.c -- 在文件中保存结构中的内容

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "self_gets.h"
#define MAXTITLE 40
#define MAXAUTL 40
#define MAXBKS 10

struct book
{
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];                               // 存放book结构的数组
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL)           // 是否成功打开文件
    {
        printf("无法打开book.dat文件\n");
        exit(1);
    }

    rewind(pbooks);                                            // 确保文件指针在起始位置
    
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)  // 尝试读取文件，每次一个结构空间
    {
        if (count == 0)
            puts("当前book.dat内容是：");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }

    filecount = count;

    if (count == MAXBKS)
    {
        fputs("book.dat已经达到预定容量！", stderr);
        exit(2);
    }

    puts("下面添加新书，在新行中键入回车退出。");
    printf("标题：");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITLE) != NULL
           && library[count].title[0] != '\0')
    {
        printf("作者：");
        s_gets(library[count].author, MAXAUTL);
        printf("价格：");
        scanf("%f", &library[count++].value);                 // 使用后自增

        while (getchar() != '\n')
        {
            continue;
        }

        if (count < MAXBKS)        
            printf("标题：");
    }

    if (count > 0)
    {
        puts("下面是书的清单：");

        for (index=0; index<count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }

    else
    {
        puts("无书");
    }

    puts("再见");
    fclose(pbooks);

    return 0;  
}
