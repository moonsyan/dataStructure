#include<stdio.h>
#include<stdlib.h>

#define Initsize 10

typedef int Elemtype;
typedef struct 
{
    Elemtype * data;
    int Maxsize;
    int length;
}SqList;

void InitList(SqList *L);                   //初始化顺序表。
void expandList(SqList *l,int len);             //动态扩展顺序表长度， 新顺序表的长度为l.Maxsize + len；
int ListInsert(SqList *l,int i,Elemtype e);      //插入e到位序为i的位置
int ListDelete(SqList *l,int i,Elemtype *e);       //删除位序为i的元素，并将删除的元素的值返回
Elemtype Getitem(SqList l,int i);               //查找位序为i的元素的值并返回
int LocateItem(SqList l,Elemtype e);            //查找元素值为e的元素的下标并返回
void ListPrint(SqList *l);                  //打印顺序表内的数据

void InitList(SqList *L){               
    L->data = (Elemtype *)malloc(sizeof(Elemtype) * Initsize);
    L->length = 0;
    L->Maxsize = 10;
}

void expandList(SqList *l,int len){         
    
    int *temp = l->data;
    l->data = (Elemtype *)malloc((l->Maxsize + len) * sizeof(Elemtype));
    for (int i = 0; i < l->Maxsize; i++)
    {
        *(l->data + i) = *(temp + i);
    }

    for (int i = l->Maxsize; i < l->Maxsize + len; i++)
    {
        l->data[i] = 0;
    }   
    l->Maxsize = l->Maxsize + len;
    free(temp);
}

int ListInsert(SqList *l,int i,Elemtype e){         

    if (i < 1 || i > l->length)     
    {
        printf("输入i的次序有误");
        return 0;
    }
    if (l->length >= l->Maxsize)
    {
       printf("顺序表已经满了");
       return 0;
    }
    for(int j = l->length; j >= i; j--){
        *(l->data + j) = *(l->data + j - 1);
    }
    l->data[i-1] = e;
    l->length ++;
    return 1;
}

int ListDelete(SqList *l,int i,Elemtype *e){        
    if(i < 1 || i > l->length){
         printf("输入i的次序有误");
        return 0;
    }
    *e = l->data[i - 1];
    for (int j = i - 1; j < l->length; j ++)
    {
        l->data[j] = l->data[j + 1];
    }
    l->length --;
    return 1;
}

Elemtype Getitem(SqList l,int i){
    if(i < 1 || i > l.length){
        printf("输入位序有误！\n");
        return 0;
    }
    return l.data[i - 1];
}

int LocateItem(SqList l,Elemtype e){
    for (int i = 0; i < l.length; i++)
    {
        if(e == l.data[i]){
            return i + 1;
        }
    }
    return 0;
    
}       

void ListPrint(SqList *l){
    for (int i = 0; i < l->Maxsize; i++)
    {
        if(i != l->Maxsize - 1) printf("%d->",l->data[i]);
        else printf("%d \n",l->data[i]);     
    }
}



int main(){
    
    SqList l;
    InitList(&l);
    for (int i = 0;i < l.Maxsize; i ++){
        *(l.data + i) = i;
        l.length ++;
    }
    
    ListPrint(&l);

    expandList(&l,5);
    
    if(ListInsert(&l,2,111)){
        printf("成功！\n");
    }
    else{
        printf("buxing a !!!!!!!\n");
    }

    ListPrint(&l);
    int e;
    if(ListDelete(&l,1,&e)){
        printf("你删除的时%d\n",e);
    }
    ListPrint(&l);

    Elemtype get = Getitem(l,3);
    if(get != 0) printf("位序3的元素值为%d\n",get);
    
    int locate = LocateItem(l,9);
    if(locate != 0){
        printf("9的位序是%d\n",locate);
    }
    else{
        printf("数组中没有值为9的元素\n");
    }
    system("pause");
}