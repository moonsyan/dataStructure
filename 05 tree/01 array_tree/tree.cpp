#include<stdio.h>
#include<stdlib.h>


#define MaxSize 255
typedef int elemtype;
typedef enum{
    False,True
} Bool;

typedef struct TreeNode{
    elemtype value;
    Bool empty;
}TreeNode;

InitTree(TreeNode *t){
    for (int i = 1; i < MaxSize; i++)
    {
        t[i].empty = True;
    }
    
}

int main(){
    TreeNode T[MaxSize];
    InitTree(T);
    for (int i = 1; i < MaxSize; i++)
    {
        printf("%d",T[i].empty);
    }
    system("pause");
}
