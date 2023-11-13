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
void middleVisit(Tree t) {   //中序遍历
	if (!t) {
		return;
	}
	else
	{
		middleVisit(t->lchild);
		printf("%c", t->data.value);
		middleVisit(t->rchild);
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


typedef struct linknode{
    TreeNode* data;
    struct linknode * next;
}LNode;

typedef struct{
    LNode *front,*rear;
    int length;
}LQuene;


void InitQuene(LQuene *Lq){
    Lq->front = Lq->rear = (LNode *)malloc(sizeof(LNode));
    Lq->length = 0; 
}
bool empty(LQuene *lq){
    if(lq->front == lq->rear){
        return True;
    }
    return False;
}
bool enQuene(LQuene *lq, TreeNode *e){
    LNode * temp = (LNode *)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = NULL;
    lq->rear->next = temp;
    lq->rear = temp;
    lq->length ++;
    printf("enQuene is %c\n",e->data.value);
    return True;
}
bool deQuene(LQuene *lq,TreeNode **e){
    if(empty(lq)){
        return False;
    }
    LNode *temp = lq->front->next;
    lq->front->next = temp->next;
    (*e) = temp->data;
    if(lq->rear == temp){
        lq->rear = lq->front;
    }
    printf("deQuene is %c\n",(*e)->data.value);
    free(temp);
    lq->length --;
    return True;
}
void levelVisit(Tree t){
    LQuene q;
    InitQuene(&q);
    if(t == NULL){
        printf("树为空\n");
        return;
    }
    else{
        enQuene(&q,t);
        while (!empty(&q))
        {
            TreeNode* temp;
            deQuene(&q,&temp);
            printf("%c\n",temp->data.value);
            if(temp->lchild != NULL)
            {
                enQuene(&q,temp->lchild);  
            }
            if(temp->rchild != NULL){
                 enQuene(&q,temp->rchild);
            }
        }
    }
}


int main(){
    Tree T;
    InitTree(&T);
    CreateTree(&T);
    preVisit(T);
    printf("\n");
    middleVisit(T);
    printf("\n");
    backVisit(T);
    printf("\n");

    printf("叶子节点的数量是%d\n",countLeaf(T));
    printf("树的深度是%d\n",depth(T));
    printf("结点总数是%d\n",count(T));

    levelVisit(T);
    printf("\n");
    system("pause");
}