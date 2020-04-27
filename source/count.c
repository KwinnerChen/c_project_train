// count.c -- 使用标准I/O

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int ch;                                                   // 用于接受读取的字符(为什么是整型？？？使用char类型测试也可以)
    FILE * fp;                                                // 声明一个文件指针
    unsigned long count = 0;                                  // 声明一个字符计数器

    if (argc != 2)                                            // 如果参数没有包含文件路径
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)                     // 打开文件失败
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)                            // 循环读取文件字符
    {
        putc(ch, stdout);
        count++;
    }
    
    fclose(fp);                                               // 关闭文件指针
    printf("\nFile %s has %lu characters\n", argv[1], count);
    
    return 0;
}