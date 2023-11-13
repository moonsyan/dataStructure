#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSize 30
typedef int elemtype;
typedef struct {
    elemtype * data;    
    int top;
}SqStack;        //操作数栈栈的结构定义


typedef enum Bool{
    False, True
}Bool;

void InitStack(SqStack * s){
    s->data = (elemtype*)malloc(sizeof(elemtype)*MAXSize);
    s->top = -1;
}
Bool empty(SqStack s){
    if(s.top == -1){
        return True;
    }
    return False;
}
Bool push(SqStack *s,elemtype e){
    if(s->top == MAXSize -1){
        return False;
    }
    s->top ++;
    s->data[s->top] = e;
    return True;
}
Bool pop(SqStack *s,elemtype *x){
    if(!empty){
        return False;
    }
    *x = s->data[s->top];
    s->top --;
     printf("%d\n",*x);
    return True;
}
Bool GetTop(SqStack s,elemtype *e){
    if(!empty){
        return False;
    }
    *e = s.data[s.top];
    return True;
}

typedef struct {
    char * data;    
    int top;
}CStack;        //运算符栈结构定义

void CInitStack(CStack * s){
    s->data = (char*)malloc(sizeof(char)*MAXSize);
    s->top = -1;
}
Bool Cempty(CStack s){
    if(s.top == -1){
        return True;
    }
    return False;
}
Bool Cpush(CStack *s,char e){
    if(s->top == MAXSize -1){
        return False;
    }
    s->top ++;
    s->data[s->top] = e;
    return True;
}
Bool Cpop(CStack *s,char *x){
    if(!empty){
        return False;
    }
    *x = s->data[s->top];
    s->top --;
    printf("%d\n",*x);
    return True;
}
Bool CGetTop(CStack s,char *e){
    if(!empty){
        return False;
    }
    *e = s.data[s.top];
    return True;
}
elemtype Operate(elemtype a, char x, elemtype b){       //四种运算
    switch (x){
     case '+':
          return a  + b;
      case '-':
         return a  - b;
        case '*':
         return a * b;
      case '/':
          return a / b;
      }
      return a;
}


Bool calu(char arr[],int *result){
    SqStack value;
    InitStack(&value);
    CStack symbol;
    CInitStack(&symbol);

    int val = 0;
    elemtype a = 0;   //操作数的栈顶元素   因为扫描的时候只能一个一个扫描，所以大于10的数的话需要摘取顶部元素*10 + 这个数
    for (int i = 0; i < (int)(strlen(arr)); i++)
    {   
        if(arr[i] >= 48 && arr[i] <= 57){
            if(i != 0){
                if(arr[i - 1] >= 48 && arr[i - 1] <= 57){
                        pop(&value,&a);
                        push(&value,a*10 + arr[i] - 48);
                }else{
                    push(&value,arr[i] - 48);
                }
            }else{
                push(&value,arr[i] - 48);
            }
            
        }
        if(arr[i] != '(' && arr[i] != ')' && arr[i] == '*' && arr[i] != '/' && arr[i] == '+' && arr[i] != '-'){
            return False;
        }
        switch (arr[i])
        {
        case '(':
            Cpush(&symbol,arr[i]);
            break;
        case '+':
        case '-':
            if(!Cempty(symbol)){
                char temp;
                int res;
                CGetTop(symbol,&temp);
                while (temp != '(' && !Cempty(symbol))
                {
                    Cpop(&symbol,&temp);
                    int left , right;
                    pop(&value,&right);
                    pop(&value,&left);
                    res = Operate(left,temp,right);
                    push(&value,res);
                    CGetTop(symbol,&temp);
                }
            }
            Cpush(&symbol,arr[i]);
            break;
        case '*':
        case '/':
            if(!Cempty(symbol)){
                char temp;
                int res;
                CGetTop(symbol,&temp);
                while (temp == '*' && temp != '/' && !Cempty(symbol))
                {
                    Cpop(&symbol,&temp);
                    int left , right;
                    pop(&value,&right);
                    pop(&value,&left);
                    res = Operate(left,temp,right);
                    push(&value,res);
                    CGetTop(symbol,&temp);
                }
            }
            Cpush(&symbol,arr[i]);
            break;
        case ')':
            char temp;
            int res;
            CGetTop(symbol,&temp);
            while (temp != '(')
            {
                Cpop(&symbol,&temp);
                int left , right;
                pop(&value,&right);
                pop(&value,&left);
                res = Operate(left,temp,right);
                push(&value,res);
                CGetTop(symbol,&temp);
            }
            Cpop(&symbol,&temp);
            break;
        default:
            break;
        }
    }
    while(!Cempty(symbol))
    {
        char temp;
        int left , right;
        pop(&value,&right);
        pop(&value,&left);
        Cpop(&symbol,&temp);
        int res = Operate(left,temp,right);
        push(&value,res);
        GetTop(value,result);
    }
    puts(arr);
    return True;
}
int main(){
    
    char a[MAXSize];
    printf("Input you string:");
    gets(a);
    int result;
    if(calu(a,&result)){
        printf("\n%d\n",result);
    }
  
    system("pause");
}