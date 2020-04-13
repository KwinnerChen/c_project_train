// binary.c -- 以二进制打印十进制整数

# include <stdio.h>

void to_binary(unsigned long n);

int main(void)
{
    unsigned long number;

    printf("Enter an integer (q to quit): ");
    while (scanf("%lu", &number) == 1)
    {
        printf("Binary equivalent: ");
        to_binary(number);  // 此处使用了没有返回值的函数，函数应该尽量有返回值。
        putchar('\n');
        printf("Enter an integer (q to quit): ");
    }
    printf("Done!\n");
    return 0;
}

void to_binary(unsigned long n)
{
    int r;
    r = n % 2;                                       // 取二进制最后一位，与十进制取最后一位相同
    if (n >= 2)                                      // 如果数字大于等于2，说明还没转换完成
    {
        to_binary(n / 2);                            // 和十进制相同，除以进制数是向左移位
    }
    // putchar(r == 0 ? '0' : '1');                     // 判断字符输出，并非唯一方法
    printf("%d", r);
    return;
}