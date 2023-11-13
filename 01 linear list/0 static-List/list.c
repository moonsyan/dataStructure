#include<stdio.h>
#include<stdlib.h>
 
#define Maxsize 10

typedef struct 
{
    int data[Maxsize];
    int length;
}SqList;

void InitList(SqList *L);

void InitList(SqList *L){
    for (int i = 0; i < Maxsize; i++)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}
int main(){

    SqList l;   
    InitList(&l);
    for (int i = 0; i < Maxsize; i++)
    {
        if(i != Maxsize - 1) printf("%d->",l.data[i]);
        else printf("%d \n",l.data[i]);     
    }
    
    system("pause");
}