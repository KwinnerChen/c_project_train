#include <math.h>
#include <stdio.h>

int main(void)
{
    const double ANSWER = 3.14159;  //限定符定义一个只读常量
    double response;

    printf("What is the value of pi? \n");
    scanf("%lf", &response);
    while (fabs(response - ANSWER) > 0.0001)  //math库中包含的函数，取绝对值
    {
        printf("Try again!\n");
        scanf("%lf", &response);
    }
    printf("Close enough!\n");

    return 0;
}