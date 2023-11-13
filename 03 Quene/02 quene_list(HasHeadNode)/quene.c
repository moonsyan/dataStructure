#include<stdlib.h>
#include<stdio.h>

typedef int elemtype;
typedef struct linknode{
    elemtype data;
    struct linknode * next;
}LNode;

typedef struct{
    LNode *front,*rear;
    int length;
}LQuene;

typedef enum bool{
    false,true
}bool;

void InitQuene(LQuene *Lq){
    Lq->front = Lq->rear = (LNode *)malloc(sizeof(LNode));
    Lq->length = 0; 
}
bool empty(LQuene *lq){
    if(lq->front == lq->rear){
        return true;
    }
    return false;
}
bool enQuene(LQuene *lq, elemtype e){
    LNode * temp = (LNode *)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = NULL;
    lq->rear->next = temp;
    lq->rear = temp;
    lq->length ++;
    printf("enQuene is %d\n",e);
    return true;
}
bool deQuene(LQuene *lq,elemtype *e){
    if(empty(lq)){
        return false;
    }
    LNode *temp = lq->front->next;
    lq->front->next = temp->next;
    *e = temp->data;
    if(lq->rear == temp){
        lq->rear = lq->front;
    }
    printf("deQuene is %d\n",*e);
    free(temp);
    lq->length --;
    return true;
}
int main(){
    LQuene quene;
    elemtype temp;
    InitQuene(&quene);
    for (int i = 0; i < 5; i++)
    {
        enQuene(&quene,i);
    }
    printf("%d \n ",quene.length);
    printf("---------------------------\n");
    for (int i = 0; i < 9; i++)
    {
        if(!deQuene(&quene,&temp)){
            printf("Quene is empty! \n");
        }
    }
    printf("%d \n ",quene.length);
    for (int i = 100; i < 104; i++)
    {
        enQuene(&quene,i);

    } 
    printf("%d \n ",quene.length);
    for (int i = 0; i < 10; i++)
    {
        if(!deQuene(&quene,&temp)){
            printf("Quene is empty! \n");
        }
    }
    printf("%d \n ",quene.length);
    system("pause");
}