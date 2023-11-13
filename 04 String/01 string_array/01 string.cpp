#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 255
typedef char elemtype;

typedef struct {
    elemtype *data;
    int length;
}SString;

typedef enum {
    False,True
}Bool;

Bool InitString(SString *s){            //初始化串
    s->data = (elemtype *)malloc(sizeof(elemtype) * max);
    if (!s->data)
    {
        return False;
    }
    s->length = 0;
    return True;
}

int StrLength(SString s){       //求串长
    return s.length;
}
void ClearString(SString s){
    s.length = 0;
}
Bool SubString(SString *e,SString s,int pos,int len){    //将s  的pos位置的len  长度的字串 赋值给e
    if(pos + len -1 > s.length){
        return False;
    }
    for (int i = pos; i <= pos + len - 1 ; i++)
    {
        e->data[i - pos + 1] =  s.data[i];
    }
    e->length = len;
    return True;
}
int StrCompare(SString s,SString t){       //s > t, return  > 0 ； s = t ,return  0 ； s < t ,return < 0 
    for (int i = 1; i <= s.length && i <= t.length; i++)
    {
        if(s.data[i] != t.data[i]){
            return s.data[i] - t.data[i];
        }
    }
    return s.length - t.length; 
}
int index(SString s, SString child){
    int i = 1;
    int end = s.length - child.length + 1;
    SString temp;
    InitString(&temp);
    while (i <= end)
    {
        SubString(&temp,s,i,child.length);
        if (StrCompare(temp,child) != 0)
        {
            i ++;
        }
        else {
            return i;
        }
    }
    return 0;
}
// int simplicityModeMatch(SString s,SString temp){
//     int k = 1;
//     int i = 1,j = 1;
//     while (k <= s.length - temp.length + 1 && j <= temp.length)
//     {
//         if (s.data[i] == temp.data[j])
//         {
//             i ++;
//             j ++;
//         }
//         else{
//             i = i - j + 2;
//             j = 1;
//             k ++;
//         }
//     }
//     if(j > temp.length){
//         return i - temp.length;
//     }
//     else{
//         return 0;
//     }
    
// }

int simplicityModeMatch(SString s,SString temp){
    // int k = 1;
    int i = 1,j = 1;
    while (i <= s.length && j <= temp.length)
    {
        if (s.data[i] == temp.data[j])
        {
            i ++;
            j ++;
        }
        else{
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > temp.length){
        return i - temp.length;
    }
    else{
        return 0;
    }
    
}
Bool StrAssign(SString *s,char  temp[]){    //将字符串常量赋值给s
        int i = 1,j = 0;
        while (temp[j] != '\0')
        {
            s->data[i] = temp[j];
            s->length ++;
            i ++;
            j ++;
        }
        return True;
}

Bool StringAssign(SString *s,SString temp){    //将串temp得值赋值到 串s中
        int i = 1;
        while (i <= temp.length)
        {
            s->data[i] = temp.data[i];
            i ++;
        }
        s->length = temp.length;
        return True;
}
Bool StrEmpty(SString s){       //判断串s是否为空
    if(s.length == 0){
        return True;
    }
    return False;
}
Bool Concat(SString *s,SString s1,SString s2){
    int i = 1;
    for (; i <= s1.length; i++)
    {
        s->data[i] = s1.data[i];
        s->length ++;
    }
    for (int j = 1; j <= s2.length;)
    {
        s->data[i] = s2.data[j];
        i ++;
        j ++;
        s->length ++;
    }
    return True;
}
Bool Replace(SString s, SString child,SString replace){     //因为在这里修改了s的length 和数据，需要传地址
    int i = 1;
    int end = s.length - child.length + 1;
    SString temp;
    InitString(&temp);
    while (i <= end)
    {
        SubString(&temp,s,i,child.length);
        if (StrCompare(temp,child) != 0)
        {
            i ++;
        }
        else {
            int j = 1;
            int x = child.length - replace.length;
            if(x == 0){
                for (; j <= replace.length; j++)
                {
                    s.data[i] = replace.data[j];
                    i ++;
                }
            }
            else if(x < 0){
                for (int  k = s.length; k >= i + child.length; k --)
                {
                    s.data[k - x] = s.data[k];
                }
                s.length -= x;
                for (; j <= replace.length; j++)
                {
                    s.data[i] = replace.data[j];
                    i ++;
                }
            }
            else{
                for (int k = i + replace.length; k <= s.length; i++)
                {
                    s.data[k - x] = s.data[k];
                }
                s.length -= x;
                for (; j <= replace.length; j++)
                {
                    s.data[i] = replace.data[j];
                    i ++;
                }
            }

        }
    }
    return True;
}
void printString(SString s){
    printf("s.length  is %d\n", s.length);
    int i = 1;
    while (i <= s.length)
    {
        printf("%c",s.data[i]);
        i ++;
    }
    printf("\n");
}
int main(){ 
    SString s;
    SString temp;
    InitString(&s); 
    InitString(&temp);
    
    SString T;
    InitString(&T); 

    char mainString[] = "google";
    char child[] = "gl";

    StrAssign(&s,mainString);        //将 字符串 mainString 的数据 赋值到 s 的 data 
    StrAssign(&temp,child);         //将字符串  child    的数据赋值给temp 的 data

    // printString(s);
    // printString(temp);

    // // StringAssign(&s,temp);      //将串 temp 的数据 赋值到 s 中
    // // printString(s);

    if(!StrEmpty(s) && !StrEmpty(temp)){
        Concat(&T,temp,s);
    }
    printString(T);
    
    char oldstr[] = "gl"; 
    SString old;
    InitString(&old);
    StrAssign(&old,oldstr);

    char new_str[] = "yws";
    SString new_string;
    InitString(&new_string);
    StrAssign(&new_string,new_str);
    if(Replace(T,old,new_string)){
        printString(T);
    }
     if(index(s,temp)){
        printf("yes ! ok! position is %d\n",index(s,temp));
    }
    // if(StrAssign(&s,mainString) && StrAssign(&temp,child)){
    //     printf("abcnaokdnmkwmdkm");
    //     if(simplicityModeMatch(s,temp)){
    //         printf("yes ! ok! position is %d\n",simplicityModeMatch(s,temp));
    //     }
    //     else{
    //         printf("oh my god !");
    //     }
    // }
    

    system("pause");
}
