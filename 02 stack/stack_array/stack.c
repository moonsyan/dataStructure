#include<stdio.h>
#include<stdlib.h>

#define MAXSize 10
typedef char elemtype;
typedef struct {
    elemtype * data;    
    int top;
}SqSrack;        //栈的结构定义

typedef enum bool{
    false, true
}bool;

void InitStack(SqSrack * s){
    s->data = (elemtype*)malloc(sizeof(elemtype)*MAXSize);
    s->top = -1;
}
bool empty(SqSrack s){
    if(s.top == -1){
        return true;
    }
    return false;
}
bool push(SqSrack *s,elemtype e){
    if(s->top == MAXSize -1){
        return false;
    }
    s->top ++;
    s->data[s->top] = e;
    return true;
}
bool pop(SqSrack *s,elemtype *x){
    if(!empty){
        return false;
    }
    *x = s->data[s->top];
    s->top --;
     printf("%d\n",*x);
    return true;
}
bool GetTop(SqSrack s,elemtype *e){
    if(!empty){
        return false;
    }
    *e = s.data[s.top];
    return true;
}
int main(){
    SqSrack s;
    InitStack(&s);
    elemtype temp;
    for (int i = 0; i < 10; i++)
    {
        push(&s,i);
    }
    for (int i = 0; i < 10; i++)
    {
        pop(&s,&temp);
    }
    
    
    system("pause");
}