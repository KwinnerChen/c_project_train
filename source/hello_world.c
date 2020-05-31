// hello_world.c -- 第一个c程序

#include <stdio.h>
#include <string.h>

int main(void)
{
	char * hello;
	hello = "hello world!";
	printf("%lu\n", strlen(hello));
	printf("%zd\n", sizeof(*hello));
	for (int i = 0; i<strlen(hello); i++)
	        printf("%d: %c\n", i, hello[i]);
	puts(hello);
        
	return 0;
}
