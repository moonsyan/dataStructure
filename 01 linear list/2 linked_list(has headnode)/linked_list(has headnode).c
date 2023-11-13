#include<stdio.h>
#include<stdlib.h>


typedef int elemtype;
typedef struct LNode
{
    elemtype data;
    struct LNode *next;
}LNode,*LinkList;

typedef enum bool{
    false,true
}bool;

bool InitList(LinkList *L);                  //闁跨喐鏋婚幏宄邦潗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚规径鎾晸閺傘倖瀚归柨鐔告灮閹烽攱瀵氶柨鐔告灮閹??
void ListHeadInsert(LinkList l);
void ListTailInsert(LinkList l);         //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏?
bool empty(LinkList L);                     //闁跨喎褰ㄧ拋瑙勫闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔活潡閸戙倖瀚规稉娲晸閺傘倖瀚?
bool ListInsert(LinkList l,int i, elemtype e);         //闁跨喐鏋婚幏铚傜秴闁跨喐鏋婚幏铚傝礋i闁跨喍鑼庨崷鏉垮殩閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏宄扳偓闂磋礋e闁跨喍鑼庨懞鍌滎暜閹??
bool InsertNextNode(LNode *p,elemtype e);           //闁跨喐鏋婚幏閿嬪瘹闁跨喐鏋婚幏鐑芥晸閼哄倻顣幏閿嬫瘖闁跨喐鏋婚幏鐑芥晸閺傘倖瀚圭拠姗€鏁撻弬銈嗗闁跨喎褰ㄧ拠褎瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁???
bool InsertPreNode(LNode *p,elemtype e);           //闁跨喐鏋婚幏閿嬪瘹闁跨喐鏋婚幏鐑芥晸閼哄倻顣幏鐑芥晸閺傘倖瀚归柨鐔活潡鐢喗瀚圭拠姗€鏁撻弬銈嗗闁跨喎褰ㄧ拠褎瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁???
bool ListDelete(LinkList l,int i, elemtype* e);       //閸掔娀鏁撻弬銈嗗閹稿洭鏁撻弬銈嗗闁跨喍鑼庨懞鍌滎暜閹??
bool DeleteNode(LNode *p);      //閸掔娀鏁撻弬銈嗗閹稿洭鏁撻弬銈嗗闁跨喕濡喊澶嬪

LNode * GetItem(LinkList l,int i);  //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚规担宥夋晸閺傘倖瀚归柨鐔告灮閹峰嘲灏扮拠姗€鏁??

void print(LinkList l);

bool InitList(LinkList *L){
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
    {
        return false;
    }
    (*L)->next = NULL;
    return true;
}
void ListTailInsert(LinkList l){       //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏?,娴ｅ潡鏁撻弬銈嗗鐏忛箖鏁撻挊澶嬬《
    LNode *p = l; 
    LNode * temp;
    printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗鐟曚線鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸鐞涙顣幏鐑芥晸?");
    elemtype a ;
    scanf("%d",&a);
    while (a != -1)
    {
        temp = (LNode*)malloc(sizeof(LNode));
        temp->next = NULL;
        temp->data = a;
        p->next = temp;
        p = temp;
        printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗鐟曚線鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸鐞涙顣幏鐑芥晸?");
        scanf("%d",&a);
    }
    p->next = NULL;
}  
void ListHeadInsert(LinkList l){       //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏?,娴ｅ潡鏁撻弬銈嗗婢舵挳鏁撻挊澶嬬《
    LNode *p = l; 
    LNode * temp;
    printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗鐟曚線鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸鐞涙顣幏鐑芥晸?");
    elemtype a ;
    scanf("%d",&a);
    while (a != -1) 
    {
        temp = (LNode*)malloc(sizeof(LNode));
        temp->next = NULL;
        temp->data = a;
        temp->next = p->next;
        p->next = temp;
        printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗鐟曚線鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸鐞涙顣幏鐑芥晸?");
        scanf("%d",&a);
    }
}  
bool empty(LinkList L){
    if (L->next == NULL)
    {
       return true;
    }
    return false;
} 

bool ListInsert(LinkList l,int i, elemtype e){     
    if(i < 1){
        return false;
    }
    // LNode* p = l;       //p閹稿洭鏁撻弬銈嗗閸撳秵澹傞柨鐔封偓鐔峰煂闁跨喍鑼庨懞鍌滎暜閹??
    // int j = 0;          //闁跨喐鏋婚幏椋庛仛p閹稿洭鏁撻弬銈嗗闁跨喐鏋婚幏宄扮埐鐠団晠鏁撻弬銈嗗闁跨喐鏋婚幏鐤樁闁???
    // while (p != NULL && j < i - 1)  //闁跨喐鏋婚幏铚傜秴闁跨喐鏋婚幏铚傝礋i-1闁跨喍鑼庨懞鍌滎暜閹??
    // {
    //     p = p->next;
    //     j ++;
    // }
    // if(p == NULL){              //闁跨喐鏋婚幏椋庛仛闁跨喐鏋婚幏閿嬫闁跨喓鐛ら幘鍛闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閺堫偄鐔柨鐔告灮閹烽鍔у▽锟犳晸閺傘倖瀚归柨鐔稿疆绾板瀚规担宥夋晸閺傘倖瀚规稉绡?-1闁跨喍鑼庨懞鍌滎暜閹??
    //     return false;
    // }
    //闁跨喐鏋婚幏绋tItem 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归惄鎾晸閹恒儱灏呴幏鐑芥晸閻ㄥ棗鍤栭幏鐑芥晸閹搭亞顣幏绌掗柨鐔告灮閹峰嘲鍘撻柨鐔告灮閹??
    LNode *p =  GetItem(l,i - 1);
    // LNode *temp = (LNode *)malloc(sizeof(LNode));   //闁跨喎澹欏▓浣冩彧閹风兘鏁撻弬銈嗗婢ф捇鏁撻弬銈嗗閼烘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸?    p 闁跨喕濡喊澶嬪娑斿鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閹活厺绱幏鐑芥晸閺傘倖瀚圭拠妯诲€撮濠冨闁跨喓绮搁幉瀣闁跨喐鏋婚幏閿嬫焿闁跨喐鏋婚幏鐤Ω闁跨喖妯佺敮顔藉闁跨喓绁sertNextNode闁跨喐鏋婚幏鐑芥晸閺傘倖瀚?
    // temp->data = e;
    // temp->next = p->next;
    // p->next = temp;
    // return true; 
    return InsertNextNode(p,e);
}

bool InsertNextNode(LNode *p,elemtype e)           //闁跨喐鏋婚幏閿嬪瘹闁跨喐鏋婚幏鐑芥晸閼哄倻顣幏閿嬫瘖闁跨喐鏋婚幏鐑芥晸閺傘倖瀚圭拠姗€鏁撻弬銈嗗闁跨喎褰ㄧ拠褎瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁???
{
    if(p == NULL){
        return false;
    }
    LNode * s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL){
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool InsertPreNode(LNode *p,elemtype e)           //闁跨喐鏋婚幏閿嬪瘹闁跨喐鏋婚幏鐑芥晸閼哄倻顣幏鐑芥晸閺傘倖瀚归柨鐔活潡鐢喗瀚圭拠姗€鏁撻弬銈嗗闁跨喎褰ㄧ拠褎瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁???
{           
    //  闁跨喐鏋婚幏铚傝礋闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻惈顐㈠殩閹烽鐓￠柨鐔告灮閹风兘鏁撻弬銈嗗閸撳秹鏁撻懞鍌滎暜閹风兘鏁撻弬銈嗗娴犫偓娑斿牓鏁撻弬銈嗗闁跨喐鏋婚幏?   闁跨喐鏋婚幏鐑芥晸閻ㄥ棗灏呴幏鐑芥晸閺傘倖瀚归柨鐔笺偤閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喕顕犻崚浼存晸閺傘倖瀚归幒銏ｇ樁閹???  閻掑爼鏁撶憲鐔舵唉娴兼瑦瀚归柨鐔告灮閹风兘鏁撻弬銈嗗
    if(p == NULL){
        return false;
    }
    LNode * s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL){
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList l,int i, elemtype* e)       //閸掔娀鏁撻弬銈嗗閹稿洭鏁撻弬銈嗗闁跨喍鑼庨懞鍌滎暜閹??
{
    if(i < 1){
        return false;
    }
    // LNode * p = l;
    // int j = 0;
    // while (p != NULL && j < i -1)
    // {
    //     p = p->next;
    //     j ++;
    // }
 
    
    //闁跨喐鏋婚幏绋tItem 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归惄鎾晸閹恒儱灏呴幏鐑芥晸閻ㄥ棗鍤栭幏鐑芥晸閹搭亞顣幏绌掗柨鐔告灮閹峰嘲鍘撻柨鐔告灮閹??
    LNode *p =  GetItem(l,i - 1);
    if(p == NULL){      //闁跨喎褰ㄩ弬顓狀暜閹风⿸-1闁跨喕濡喊澶嬪闁跨喕顫楃拠褎瀚归柨鐔活潡閸栤剝瀚?
        return false;
    }
    if(p->next == NULL){    //闁跨喎褰ㄩ弬顓狀暜閹?? i 闁跨喕濡喊澶嬪闁跨喕顫楃拠褎瀚归柨鐔活潡閸栤剝瀚?
        return false;
    }

    LNode * temp = p->next;
    *(e) = temp->data;
    p->next = temp->next;
    free(temp);
    return true;
}
bool DeleteNode(LNode *p){      //閸掔娀鏁撻弬銈嗗閹稿洭鏁撻弬銈嗗闁跨喕濡喊澶嬪
    if(p == NULL){
        return false;
    }
    LNode *temp = p->next;
    p->data = temp->data;
    p->next = temp->next;
    free(temp);
    return true;
}
LNode* GetItem(LinkList l,int i) { //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚规担宥夋晸閺傘倖瀚归柨鐔告灮閹峰嘲灏伴柨鐔告灮閹??
    if(i < 0){
        return NULL;
    }
    LNode* p = l;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j ++;
    }
    return p;
}
LNode* locateElem(LinkList l, elemtype e){
    LNode * p = l;
    while (p != NULL && e != p->data)
    {
        p = p->next;
    }
    return p;
}
int length(LinkList l){
    int len = 0;
    LNode *p = l;
    while (p != NULL )
    {
        p = p->next;
        len ++;
    }
    return len;
}
// bool LListInsert(LinkList *l,int i, elemtype e){     
//     if(i < 1){
//         return false;
//     }
//     LNode* p = (*l);       //p閹稿洭鏁撻弬銈嗗閸撳秵澹傞柨鐔封偓鐔峰煂闁跨喍鑼庨懞鍌滎暜閹??
//     int j = 0;          //闁跨喐鏋婚幏椋庛仛p閹稿洭鏁撻弬銈嗗闁跨喐鏋婚幏宄扮埐鐠団晠鏁撻弬銈嗗闁跨喐鏋婚幏鐤樁闁???
//     while (p != NULL && j < i - 1)  //闁跨喐鏋婚幏铚傜秴闁跨喐鏋婚幏铚傝礋i-1闁跨喍鑼庨懞鍌滎暜閹??
//     {
//         p = p->next;
//         j ++;
//     }
//     if(p == NULL){              //闁跨喐鏋婚幏椋庛仛闁跨喐鏋婚幏閿嬫闁跨喓鐛ら幘鍛闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閺堫偄鐔柨鐔告灮閹烽鍔у▽锟犳晸閺傘倖瀚归柨鐔稿疆绾板瀚规担宥夋晸閺傘倖瀚规稉绡?-1闁跨喍鑼庨懞鍌滎暜閹??
//         return false;
//     }
//     LNode *temp = (LNode *)malloc(sizeof(LNode));   
//     temp->data = e;
//     temp->next = p->next;
//     p->next = temp;
//     return true; 
// }


// bool LListInsert(LinkList *l,int i, elemtype e){             //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔活潡鏉堢偓瀚归柨鐔告灮閹烽攱鎳濋柨??    闁跨喐鏋婚幏? (*p) = (*p)->next;     闁跨喓绮ㄦ稉銏犮亼闁跨喐鏋婚幏鐑芥晸閺傘倖瀚?
//     if(i < 1){
//         return false;
//     }
//     LNode** p = l;       //p閹稿洭鏁撻弬銈嗗閸撳秵澹傞柨鐔封偓鐔峰煂闁跨喍鑼庨懞鍌滎暜閹??
//     int j = 0;          //闁跨喐鏋婚幏椋庛仛p閹稿洭鏁撻弬銈嗗闁跨喐鏋婚幏宄扮埐鐠団晠鏁撻弬銈嗗闁跨喐鏋婚幏鐤樁闁???
//     while ((*p) != NULL && j < i - 1)  //闁跨喐鏋婚幏铚傜秴闁跨喐鏋婚幏铚傝礋i-1闁跨喍鑼庨懞鍌滎暜閹??
//     {
//         (*p) = (*p)->next;               
//         j ++;
//     }
//     if((*p) == NULL){              //闁跨喐鏋婚幏椋庛仛闁跨喐鏋婚幏閿嬫闁跨喓鐛ら幘鍛闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閺堫偄鐔柨鐔告灮閹烽鍔у▽锟犳晸閺傘倖瀚归柨鐔稿疆绾板瀚规担宥夋晸閺傘倖瀚规稉绡?-1闁跨喍鑼庨懞鍌滎暜閹??
//         return false;
//     }
//     LNode *temp = (LNode *)malloc(sizeof(LNode));   
//     temp->data = e;
//     temp->next = (*p)->next;
//     (*p)->next = temp;
//     return true; 
// }

void print(LinkList l){
    LNode *p = l;
    if(empty(p)){
        printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚规稉娲晸缁夐潻缍囬幏绌僴");
    }
    else{
        p = p->next;
        while (p->next != NULL)
        {
            printf("%d->",p->data);
            p = p->next;
        }
        printf("%d\n",p->data);       
    }
}

void inversion(LinkList l){         //閸樼喎婀撮崣宥堟祮闁炬崘銆?
    LNode *beg = NULL;
    LNode *end= l->next; 
    LNode *temp = NULL;
    while(end != NULL){ 
        temp = end->next; 
        end->next = beg;
        beg = end;
        end = temp;
    }
    l->next = beg;
}
// LNode * local_reverse(LinkList  head) {
   
//     LNode * beg = head->next;
//     LNode * end = beg->next;
//     while (end!= NULL) {
//         //闁跨喐鏋婚幏? end 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閹芥﹢鏁撻弬銈嗗
//         beg->next = end->next;
//         //闁跨喐鏋婚幏? end 闁跨喓瀚涚拋瑙勫闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹峰嘲銇?
//         end->next = head;

//         head = end;
//         //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚? end 闁跨喐鏋婚幏閿嬪瘹闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹烽攱瀵氶柨鐔告灮閹?? beg 闁跨喐鏋婚幏鐑芥晸閹活厺绱幏鐑芥晸閺傘倖瀚圭拠妯诲€撮鈺婁悍閹风兘鏁撻梼棰濅悍閹风兘鏁撻幓顓濈串閹风兘鏁撻弬銈嗗鐠囨﹢鏁撻弬銈嗗闁跨喖妯佺涵閿嬪闁???


//         end = beg->next;
//     } 
//     return head;
// }
int main(){
    
    LinkList L;                                         
    InitList(&L);
    ListTailInsert(L);
    // ListHeadInsert(L);
    // LListInsert(&L,1,10);
    // LListInsert(&L,2,20);
    // LListInsert(&L,3,30);
    // LListInsert(&L,4,40);
    // LListInsert(&L,5,50);
    // LListInsert(&L,1,1000);
    // ListInsert(L,1,10);
    // ListInsert(L,2,20);
    // ListInsert(L,3,30);
    // ListInsert(L,4,40);
    // ListInsert(L,1,100000000);
    // print(L);
    // elemtype a,b,c,d;
    // ListDelete(L,1,&a);
    // ListDelete(L,2,&b);
    // ListDelete(L,3,&c);
    // ListDelete(L,2,&d);
    // printf("%d  %d  %d  %d\n",a,b,c,d);
    print(L);
    inversion(L);
    print(L);

    system("pause");
}