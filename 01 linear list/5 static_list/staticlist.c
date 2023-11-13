#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef int elemtype;
typedef struct node
{   
    elemtype data;
   int next;
}node;
typedef struct testnode
{   
    elemtype data;
    int next;
}Slist[MAXSIZE];

void Init(Slist s){
    s->next = -1;
}
int main(){
    node a[MAXSIZE];
    printf("%d\n",sizeof(a));
    Slist b;
    printf("%d\n",sizeof(b));
    Init(b);

    printf("%d",b->next);
    system("pause");
}