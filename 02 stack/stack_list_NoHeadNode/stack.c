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
    *ls = NULL;
    return true;
}
bool push(LiStack *ls,elemtype e){
    if((*ls) == NULL){
        linknode* temp = (linknode *)malloc(sizeof(linknode));
        temp->data = e;
        temp->next = NULL;
        (*ls) = temp;
        return true;
    }
    else{
        LiStack s = *ls;
        linknode* temp = (linknode *)malloc(sizeof(linknode));
        temp->data = e;
        temp->next = s;
        *ls = temp;
        return true;
    }
}
bool empty(LiStack *ls){
    if((*ls) == NULL){
        return true;
    }
    return false;
}
bool pop(LiStack *ls, elemtype *e){
    if(empty(ls)){
        *e = (*ls)->data;
        (*ls) = NULL;
        printf("%d\n",*e);
        return true;
    }
    else{
        linknode *temp = (*ls);
        *e = temp->data;
        (*ls) = (*ls)->next;
        free(temp);
        printf("%d\n",*e);
        return true;
    }
}


int main(){
    LiStack ls;
    InitStack(&ls);
    elemtype temp;
    for (int i = 0; i < 10; i++)
    {
        push(&ls,i);
    }
    for (int i = 0; i < 10; i++)
    {
        pop(&ls,&temp);
    }
    
    
    system("pause");
}