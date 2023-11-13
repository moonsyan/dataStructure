#include<stdio.h>
#include<stdlib.h>


typedef int elemtype;
typedef struct LNode
{
    elemtype data;
    struct LNode *next;
}LNode,*LinkList;

typedef enum bool{
    false,true
}bool;

bool InitList(LinkList *L);                  //初始化不带头结点的指针
bool empty(LinkList L);                     //判断链表是否为空
bool ListInsert(LinkList *l,int i,elemtype e);   //插入元素
void Listprint(LinkList l);                 //打印链表

bool InitList(LinkList *L){
    *L = NULL;
    return true;
}

bool empty(LinkList L){
    if (L == NULL)
    {
       return true;
       
    }
    return false;
} 
bool ListInsert(LinkList *l,int i,elemtype e){
    if (i < 1)
    {
        return false;
    }
    if(i == 1){
        LNode *temp = (LNode *)malloc(sizeof(LNode));
        temp->data  = e;
        temp->next = *l;
        (*l) = temp;
        return true;
    }
    LNode *p = *l;
    int j = 1;
    while (p !=NULL && j < i - 1)
    {
        p = p->next;
        j ++;
    }
    if(p == NULL){
        return false;
    }
    LNode * temp = (LNode *)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    return true;
}

void Listprint(LinkList l){
    if (l == NULL)
    {
        printf("链表为空！\n");
    }
    else{
        LNode * p = l;
        while (p->next != NULL)
        {
           printf("%d --> ",p->data);
           p = p->next;
        }
        printf("%d\n",p->data);
        
    }
    
}
int main(){

    LinkList L;
    InitList(&L);

    ListInsert(&L,1,30);
    ListInsert(&L,1,50);
    ListInsert(&L,2,1000);
    ListInsert(&L,4,40000);
    ListInsert(&L,5,50000);
    Listprint(L);
    system("pause");
}