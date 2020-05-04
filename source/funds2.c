// funds2.c -- 结构的指针作为参数传递

#include <stdio.h>
#define FUNDLEN 50

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds *);  // 不可改变结构体内的值

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94,
    };  // 有分号，因为不是代码块，而是语句的一部分

    printf("Stan has a total of $%.2f.\n", sum(&stan));

    return 0;
}

double sum(const struct funds * stan)
{
    return (stan->bankfund + stan->savefund);
}
