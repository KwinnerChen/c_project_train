// names1.c -- 使用指向结构的指针

#include <stdio.h>
#include <string.h>
#include "self_gets.h"
#define NLEN 30

struct namect
{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);

int main(void)
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);

    return 0;
}

void getinfo(struct namect * person)
{
    printf("Please enter your first name: ");
    s_gets(person -> fname, NLEN);
    printf("Please enter your last name: ");
    s_gets(person -> lname, NLEN);
}

void makeinfo(struct namect * person)
{
    person -> letters = strlen(person -> fname) + strlen(person -> lname);
}

void showinfo(const struct namect * person)
{
    printf("%s %s, your name contains %d letters.\n", 
           person -> fname, person -> lname, person -> letters);
}
