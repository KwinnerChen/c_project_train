// funds3.c -- 直接将结构体作为函数参数，但旧的编辑器可能不支持

#include <stdio.h>
#define FUNDLEN 50

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds);

int main(void)
{
    struct funds stan = 
    {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };

    printf("Stan has a total of $%.2f.\n", sum(stan));

    return 0;
}

double sum(const struct funds stan)
{
    return (stan.bankfund + stan.savefund);
}
