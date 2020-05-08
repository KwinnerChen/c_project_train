// enum.c -- 使用枚举类型

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "self_gets.h"
#define LEN 30

enum spectrum {red, orange, yellow, green, blue, violet};
const char * colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

int main(void)
{
    char choice[LEN];
    enum spectrum color;
    bool color_is_find = false;

    puts("Enter a color (empty line to quit): ");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++)
        {
            if (strcmp(choice, colors[color]) == 0)  // string.h的函数
            {
                color_is_find = true;
                break;
            }
        }

        if (color_is_find)
        {
            switch (color)
            {
            case red:
                puts("Rose are red.");
                break;
            case orange:
                puts("Poppies are orange.");
                break;
            case yellow:
                puts("sunflowers are yellow.");
                break;
            case green:
                puts("Grass is green.");
                break;
            case blue:
                puts("Bluebells are blue.");
                break;
            case violet:
                puts("violets are violet.");
                break;
            }
        }
        else
        {
            printf("I don't know about the color %s.\n", choice);
        }

        color_is_find = false;
        puts("Next color, please (empty line to quit):");
    }

    puts("Goodbye!");
    return 0;    
}