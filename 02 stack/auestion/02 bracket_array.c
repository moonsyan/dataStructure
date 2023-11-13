#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSize 10
typedef char elemtype;
typedef struct {
    elemtype * data;    
    int top;
}SqSrack;        //栈的结构定义

typedef enum {
    False = 0, True = 1
}Bool;

void InitStack(SqSrack * s){
    s->data = (elemtype*)malloc(sizeof(elemtype)*MAXSize);
    s->top = -1;
}
Bool empty(SqSrack s){
    if(s.top == -1){
        return True;
    }
    return False;
}
Bool push(SqSrack *s,elemtype e){
    if(s->top == MAXSize -1){
        return False;
    }
    s->top ++;
    s->data[s->top] = e;
    return True;
}
Bool pop(SqSrack *s,elemtype *x){
    if(!empty){
        return False;
    }
    *x = s->data[s->top];
    s->top --;
     printf("%d\n",*x);
    return True;
}
Bool GetTop(SqSrack s,elemtype *e){
    if(!empty){
        return False;
    }
    *e = s.data[s.top];
    return True;
}
Bool bracket(char arr[],int length){
    int top = -1;
    for(int i = 0;i < length;i ++){
        if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{'){
            top ++;
        }
        else{ 
            if(top == -1){
                return False;
            }
            char temp = arr[top];
            top --;
            if(arr[i] == '(' && temp != ')'){
                return False;
            }
            if(arr[i] == ']' && temp != ']'){
               return False;
            }
            if(arr[i] == '{' && temp != '}'){
                return False;
            }
        }

    }
    return top == -1;
}
int main(){
    
    char arr[] = "{({})]";
    char arr1[] = "{(})]";
    char arr2[] = "{({)}";
    char arr3[] = "{({})}";

    printf("%s is %d\n",arr,bracket(arr,(int)(strlen(arr))));
    printf("%s is %d\n",arr1,bracket(arr1,(int)(strlen(arr1))));
    printf("%s is %d\n",arr2,bracket(arr2,(int)(strlen(arr2))));
    printf("%s is %d\n",arr3,bracket(arr3,(int)(strlen(arr3))));

    system("pause");
}