#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;

void reverse();
void reverse(elemtype a[]){
    elemtype temp;
    for (int i = 0; i < 10/2; i++)
    {
        temp = a[i];
        a[i] = a[10 - 1 - i];
        a[10 - 1 - i] = temp;
    }
}
3
int main(){
    elemtype a[11];
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    reverse(&a);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t",a[i]);
    }
    system("pause");
}