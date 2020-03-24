/*summing.c -- 根据用户键入的整数求和*/
#include <stdio.h>

int main(void) 
{
    long num;
    long sum = 0;  //声明并初始化
    int status;

    printf("Please enter an integer to be summed");
    printf("(q to quit): ");
    
    status = scanf("%ld", &num);
    while (status == 1)
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);

    return 0;    
}

/* 相同功能使用python实现
def main():
    sum = 0
    num = input("Please enter an integer (q to quit): ")
    while num and isinstance(num, int):
        sum = sum + num
        print("Those integers sum to %d" % sum)
        num = input("Please enter an integer (q to quit): ")
*/