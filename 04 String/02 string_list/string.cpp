#include<stdio.h>
#include<stdlib.h>

typedef char elemtype;

typedef struct stringNode{
    char data[4];
    struct stringNode *next; 
}StringNode, *String;