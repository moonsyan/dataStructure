#include<stdio.h>
#include<stdlib.h>


typedef struct elemtype{
    char value;
}elemtype;
typedef enum{
    False,True
} Bool;

typedef struct TreeNode{
    elemtype data;
    struct TreeNode *lchild,*rchild;
    int ltag = 0;
    int rtag = 0;      //0表示是线索，1表示指向的是左右孩子
}TreeNode, *Tree;



InitTree(Tree *t){
    *t = (TreeNode *)malloc(sizeof(TreeNode));
    (*t)->data.value;
    (*t)->lchild = NULL;
    (*t)->rchild = NULL;
    return True;
}
void CreateTree(Tree *t){
    elemtype e;
    scanf("%c",&e.value);
    getchar();
    if(e.value == '#'){
        *t = NULL;
    }
    else{
        *t = (TreeNode *)malloc(sizeof(TreeNode));
        if(!t){
            printf("创建失败！\n");
        }
        (*t)->data = e;
        (*t)->ltag = (*t)->rtag = 0;
        CreateTree(&(*t)->lchild);
        CreateTree(&(*t)->rchild);
    }
}

void preVisit(Tree t) {   //先序遍历
	if (!t) {
		return;
	}
	else
	{
		printf("%c", t->data.value);
		preVisit(t->lchild);
		preVisit(t->rchild);
	}

}

void middleVisit(Tree *t,TreeNode **pre) {   //中序遍历
	if (*t == NULL) {
		return;
	}
	else
	{
		middleVisit(&((*t)->lchild),pre);
		printf("%c", (*t)->data.value);
       
        if ((*t)->lchild == NULL)
        {
            (*t)->lchild = *pre;
            (*t)->ltag = 1;
        }
        if((*pre) != NULL && (*pre)->rchild == NULL){
            (*pre)->rchild = *t;
            (*pre)->rtag = 1;
        }
        *pre = *t;

		middleVisit(&((*t)->rchild),pre);
	}
}
void backVisit(Tree t) {   //后序遍历
	if (!t) {
		return;
	}
	else
	{
		backVisit(t->lchild);
		backVisit(t->rchild);
		printf("%c", t->data.value);
	}
}
int countLeaf(Tree t){      //计算叶子节点的数量
    if(t == NULL){
        return 0;
    }
    if(t->lchild == NULL && t->rchild == NULL){
        return 1;
    }
    else{
       return countLeaf(t->lchild) + countLeaf(t->rchild);
    }
}
int depth(Tree t){
    if(t == NULL){
        return 0;
    }
    else{
        return 1 + depth(t->lchild) > 1 + depth(t->rchild)? 1 + depth(t->lchild) : 1 + depth(t->rchild);
    }
}
int count(Tree t){
    if(t == NULL){
        return 0;
    } 
    else{
        return 1 + count(t->lchild) + count(t->rchild);
    }
}

void CreateInthread(Tree t){
    TreeNode* pre = NULL;
    if(t != NULL){
        middleVisit(&t,&pre);
        if(pre->rchild == NULL){
            pre->rtag = 1;
        }
    }
}
TreeNode *findFirstNode(Tree t){   //中序线索化寻找第一个结点
    while (t->ltag == 0)
    {
        t = t->lchild;
    }
    return t;
}
TreeNode *nextNode(TreeNode *t){    //确定访问顺序，如果右节点被线索化了，那么直接访问右节点，如果没有 被线索化，就需要找到他的 右子树上第一个而被访问的结点
    if(t->rtag == 1){
        t = t->rchild;
    }
    else{
        t = findFirstNode(t->rchild);
    }
    return t;
}
void inOrderMiddleClue(Tree t){         //根据后继 遍历 中序线索二叉树
    for (t = findFirstNode(t); t != NULL; t = nextNode(t))
    {
        printf("%c -> ",t->data.value);
    }
}
TreeNode *findlastNode(Tree t){         //找到中序遍历的最后一个结点
    while (t->rtag == 0)
    {
        t = t->rchild;
    }
    return t;
}
TreeNode *lastNode(TreeNode * t){       //找到中序前驱
    if(t->ltag == 1){
        t  = t->lchild;
    }
    else{
        t = findlastNode(t->lchild);
    }
    return t;
}
void revInOrderMiddleClue(Tree t){          //从最后一个结点开始不断遍历前驱结点
    for (t = findlastNode(t);t != NULL; t = lastNode(t))
    {
        printf("%c -> ",t->data.value);
    }
    printf("\n");
}
// typedef struct linknode{
//     TreeNode* data;
//     struct linknode * next;
// }LNode;

// typedef struct{
//     LNode *front,*rear;
//     int length;
// }LQuene;

// void InitQuene(LQuene *Lq){
//     Lq->front = Lq->rear = (LNode *)malloc(sizeof(LNode));
//     Lq->length = 0; 
// }
// bool empty(LQuene *lq){
//     if(lq->front == lq->rear){
//         return True;
//     }
//     return False;
// }
// bool enQuene(LQuene *lq, TreeNode *e){
//     LNode * temp = (LNode *)malloc(sizeof(LNode));
//     temp->data = e;
//     temp->next = NULL;
//     lq->rear->next = temp;
//     lq->rear = temp;
//     lq->length ++;
//     printf("enQuene is %c\n",e->data.value);
//     return True;
// }
// bool deQuene(LQuene *lq,TreeNode **e){
//     if(empty(lq)){
//         return False;
//     }
//     LNode *temp = lq->front->next;
//     lq->front->next = temp->next;
//     (*e) = temp->data;
//     if(lq->rear == temp){
//         lq->rear = lq->front;
//     }
//     printf("deQuene is %c\n",(*e)->data.value);
//     free(temp);
//     lq->length --;
//     return True;
// }
// void levelVisit(Tree t){
//     LQuene q;
//     InitQuene(&q);
//     if(t == NULL){
//         printf("树为空\n");
//         return;
//     }
//     else{
//         enQuene(&q,t);
//         while (!empty(&q))
//         {
//             TreeNode* temp;
//             deQuene(&q,&temp);
//             printf("%c\n",temp->data.value);
//             if(temp->lchild != NULL)
//             {
//                 enQuene(&q,temp->lchild);  
//             }
//             if(temp->rchild != NULL){
//                  enQuene(&q,temp->rchild);
//             }
//         }
//     }
// }


int main(){
    Tree T;
    InitTree(&T);
   
    CreateTree(&T);
    // preVisit(T);
    // printf("\n");
    CreateInthread(T);
    printf("\n");
    inOrderMiddleClue(T);
    printf("\n");
    revInOrderMiddleClue(T);
    // backVisit(T);
    // printf("\n");

    // printf("The number of leafNode is %d\n",countLeaf(T));
    // printf("The Depth of tree is %d\n",depth(T));
    // printf("The number of treeNode is %d\n",count(T));

    // levelVisit(T);
    // printf("\n");

    system("pause");
}