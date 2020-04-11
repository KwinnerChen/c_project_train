// lethead1.c


# include <stdio.h>
# define NAME "gigathik, ing."
# define ADDRESS "101 megabuck plaza"
# define PLACE "megapolis, ca 94904"
# define WIDTH 40


void startbar(void);


int main(void)
{
    startbar();
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", PLACE);
    startbar();

    return 0;
}

void startbar(void)
{
    for (int count=1; count<=WIDTH; count++)
    {
        printf("*");  // 和使用putchar效果相同，只是putchar是字符，而非字符串
    }
    printf("\n");
}