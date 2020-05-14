#include <stdio.h>
#include <stdlib.h>
#include "movies_list.h"

void init(List * plist) {
    plist -> head = NULL;
    plist -> end = NULL;
    plist -> count = 0;
}

bool listisempty(const List * plist) {
    if (plist -> count == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool listisfull(const List * plist) {
    Node * pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));

    if (pt == NULL) {
        full = true;
    }
    else {
        full = false;
    }

    free(pt);
    return full;
}

unsigned int listitemcount(const List * plist) {
    return plist -> count;
}

bool additem(Item item, List * plist) {
    Node * newndp;
    Node * endndp;

    newndp = (Node *) malloc(sizeof(Node));
    if (newndp == NULL) {
        return false;
    }
    newndp -> item = item;
    newndp -> next = NULL;

    if (plist -> head == NULL) {
        plist -> head = newndp;
    }
    else {
        endndp = plist -> end;
        endndp -> next = newndp;
    }
    plist -> end = newndp;
    plist -> count = plist -> count + 1;
    return true;
}

void traverse(const List * plist, void (*func)(Item item)) {
    Node * pt = plist -> head;
    while (pt != NULL)
    {
        (*func)(pt -> item);
        pt = pt -> next;
    }
}

void emptythelist(List * plist) {
    Node * pt;
    while (plist -> head != NULL)
    {
        pt = plist -> head;
        plist -> head = plist->head->next;
        free(pt);
    }
    
}