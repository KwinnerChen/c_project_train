#ifndef MOVIES_LIST
#define MOVIES_LIST
#include <stdbool.h>
#define TSIZE 45

typedef struct film {
    char title[TSIZE];
    int rating;
} Item;

typedef struct node
{
    Item item;
    struct node * next;    
} Node;

typedef struct list {
    Node * head;
    Node * end;
    unsigned int count;
} List;

void init(List *);

bool listisempty(const List *);

bool listisfull(const List *);

unsigned int listitemcount(const List *);

bool additem(Item, List *);

void traverse(const List *, void (*pfunc)(Item));

void emptythelist(List *);

#endif
