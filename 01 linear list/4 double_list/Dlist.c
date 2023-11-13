#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct Dnode
{   
    elemtype data;
    struct Dnode *pre,*next;
    
}Dnode,*Dlist;

typedef enum bool{
    false,true
}bool;

bool InitDlinkList(Dlist *l){
    *l = (Dnode *)malloc(sizeof(Dnode));
    if( *l == NULL){
        return false;
    }
    (*l)->pre = (*l)->next = NULL;
}

bool InsertNextNode(Dnode * p,Dnode *temp){
    if(p == NULL || temp == NULL){
        return false;
    }
    temp->next = p->next;
    if(p->next != NULL){
        p->next->pre = temp;
    }
    temp->pre = p;
    p->next = temp;
    return true;
}
bool DeleteNextNode(Dnode *p){
    if(p == NULL) return false;
    Dnode *  temp = p->next;
    if(temp == NULL) return false;
    p->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->pre = p;
    }
    free(temp);
    return true;
}
void DestoryList(Dlist l){
    while (l->next != NULL)
    {
        DeleteNextNode(l);
    }
    free(l);
    l = NULL;
}

int main(){
    Dlist l;
    InitDlinkList(&l);

 
    system("pause");
}