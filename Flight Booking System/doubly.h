#ifndef DOUBLY_H_INCLUDED
#define DOUBLY_H_INCLUDED

#include "header.h"


typedef Client StackEntry;

typedef struct stacknode{
    StackEntry entry;
    struct stacknode *next;
    struct stacknode *prev;
}StackNode;

typedef struct stack{
    StackNode *top;
    int size;
}Stack;

#endif // DOUBLY_H_INCLUDED
