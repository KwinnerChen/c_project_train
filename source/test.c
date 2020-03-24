// 这是一个用于测试的源码文件

#include <stdio.h>
#include <math.h>

int main (void)
{
    double response;
    int status;

    printf("随意输入一个浮点数(q退出):");
    status = scanf("%lf", &response);

    while (status == 1)
    {
        printf("fabs(response - 3.14159)的值是：%lf", fabs(response - 3.14159));
        printf("随意输入一个浮点数(q退出):");
        status = scanf("%lf", &response);
        // printf("fabs(response - 3.14159)的值是：%lf", fabs(response - 3.14159));
    }

    return 0;
}