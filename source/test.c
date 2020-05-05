// 这是一个用于测试的源码文件

#include <stdio.h>
#include <string.h>
#include <math.h>
#define SLEN 20

int main (void)
{
    // double response;
    // int status;

    // printf("随意输入一个浮点数(q退出):");
    // status = scanf("%lf", &response);

    // while (status == 1)
    // {
    //     printf("fabs(response - 3.14159)的值是：%lf", fabs(response - 3.14159));
    //     printf("随意输入一个浮点数(q退出):");
    //     status = scanf("%lf", &response);
    //     // printf("fabs(response - 3.14159)的值是：%lf", fabs(response - 3.14159));
    // }
    char * msg = "你好世界，hello world!";
    // fgets(msg, SLEN, stdin);
    printf("%s\n", msg);
    printf("输入了%lu个字符\n", strlen(msg));   // 中文编码占三个字节

    return 0;
}