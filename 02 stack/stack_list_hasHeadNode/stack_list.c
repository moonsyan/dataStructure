#include<stdio.h>
#include<stdlib.h>

#define MAXSize 10
typedef int elemtype;
typedef struct linknode{
    elemtype data;    
    struct linknode *next;
}linknode,*LiStack;        //栈的结构定义

typedef enum bool{
    false, true
}bool;

bool InitStack(LiStack* ls){
    *ls = (linknode *)malloc(sizeof(linknode));
    if (*ls == NULL)
    {
        return false;
    }
    (*ls)->next = NULL;
    return true;
}
bool push(LiStack ls,elemtype e){
    LiStack s = ls;
    linknode* temp = (linknode *)malloc(sizeof(linknode));
    temp->data = e;
    temp->next = s->next;
    s->next = temp;
}
bool empty(LiStack ls){
    if(ls->next == NULL){
        return true;
    }
    return false;
}
bool pop(LiStack ls,elemtype *e){
    if(!empty){
        return false;
    }
    linknode* temp = ls->next;
    *e = temp->data;
    ls->next = temp->next;
    free(temp);
    printf("%d\n",*e);
    return true;
}
int main(){
    LiStack ls;
    InitStack(&ls);
    elemtype temp;
    for (int i = 0; i < 10; i++)
    {
        push(ls,i);
    }
    for (int i = 0; i < 10; i++)
    {
        pop(ls,&temp);
    }
    
    
    system("pause");
}