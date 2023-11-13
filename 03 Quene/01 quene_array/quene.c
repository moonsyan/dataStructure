#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef int elemtype;

typedef struct{
    elemtype *data;
    int front,rear;
}SqQuene;

typedef enum bool{
    false,true
}bool;

void InitQuene(SqQuene *s){
    s->data = (elemtype *)malloc(sizeof(elemtype)*MaxSize);
    s->front = s->rear = 0;             
}
bool full(SqQuene *s){
    if((s->rear + 1)%MaxSize == s->front){
        return true;
    }
    return false;
}
bool empty(SqQuene *s){
    if(s->front == s->rear){
        return true;
    }
    return false;
}
bool enQueue(SqQuene *s,elemtype e){
    if(full(s)){
        return false;
    }
    s->data[s->rear] = e;
    s->rear  = (s->rear + 1) % MaxSize;
    printf("enQuene is -------------------%d\n",e);
    return true;
} 
bool deQuene(SqQuene *s, elemtype *e){
    if(empty(s)){
        return false;
    }
    *e = s->data[s->front];
    s->front = (s->front + 1) % MaxSize;
    printf("DeQuene is -------------------%d\n",*e);
    return true;
}
int length(SqQuene s){
    return (s.rear - s.front + MaxSize)% MaxSize;
}

int main(){
    SqQuene quene;
    InitQuene(&quene);
    elemtype temp;
    for (int i = 0; i < 11; i++)
    {
        if(!enQueue(&quene,i)){
            printf("Quene is full! \n");
        }
        
    }
    printf("%d \n ",length(quene));
    printf("---------------------------\n");
    for (int i = 0; i < 3; i++)
    {
        if(!deQuene(&quene,&temp)){
            printf("Quene is empty! \n");
        }
    }
    printf("%d \n ",length(quene));
     for (int i = 100; i < 104; i++)
    {
        if(!enQueue(&quene,i)){
            printf("Quene is full! \n");
        }
    } 
    printf("%d \n ",length(quene));
     for (int i = 0; i < 10; i++)
    {
        if(!deQuene(&quene,&temp)){
            printf("Quene is empty! \n");
        }
    }
    printf("%d \n ",length(quene));
    system("pause");
}