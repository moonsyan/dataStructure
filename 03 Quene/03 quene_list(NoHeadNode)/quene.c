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

void InitQuene(LQuene *lq){
    lq->front = lq->rear = NULL;
    lq->length = 0;
}
bool empty(LQuene *lq){
    return lq->front == NULL;
}
bool enQuene(LQuene *lq,elemtype e){
    // if(empty(lq)){
    //    lq->front = lq->rear = (LNode *)malloc(sizeof(LNode));
    //    lq->rear->data = e;
    //    lq->rear->next = NULL;
    // }
    // else{
    //     LNode* temp = (LNode*)malloc(sizeof(LNode));
    //     temp->data = e;
    //     lq->rear->next = temp;
    //     lq->rear = temp;
    // }

    LNode* temp = (LNode*)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = NULL;

    if(empty(lq)){
        lq->front = lq->rear = temp;
    }else{
        lq->rear->next = temp;
        lq->rear = temp;
    }

    printf("enQuene is %d\n",e);
    lq->length ++;
    return true;
}
bool deQuene(LQuene *lq,elemtype *e){
    if(empty(lq)){
        return false;
    }
    LNode* temp = lq->front;
    lq->front = temp->next;
    *e = temp->data;
    printf("deQuene is %d\n",*e);
    if(lq->rear == temp)
    {
        lq->front = lq->rear = NULL;
    }
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