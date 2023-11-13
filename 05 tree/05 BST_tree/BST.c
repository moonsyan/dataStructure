#include<stdio.h>
#include<stdlib.h>


typedef int elemtype;
typedef enum{
    False,True
} Bool;

typedef struct TreeNode{
    elemtype data;
    struct TreeNode *lchild,*rchild;
}TreeNode, *Tree;

void InitTree(Tree *t){
    (*t) = NULL;
}

int BST_insert(Tree *t,elemtype k){       //往二叉排序树上插入节点
  
    while (1)                               //非递归的实现方法
    {
    
        if((*t) == NULL){
            (*t) = (TreeNode *)malloc(sizeof(TreeNode));
            (*t)->data = k;
            (*t)->lchild = NULL;
            (*t)->rchild = NULL;
            return 1; 
        }
        if ((*t)->data == k)
        {
            return 0;
        }
        if((*t)->data < k){
            // (*t) = (*t)->rchild;   
            t = &((*t)->rchild);
            continue;
        }
        if((*t)->data > k){

            // (*t) = (*t)->lchild;
             t = &((*t)->lchild);
            continue;
        }

    }
}
int BST_insert_recursion(Tree *t,elemtype k){       //往二叉排序树上插入节点
    if((*t) == NULL){
        (*t) = (TreeNode *)malloc(sizeof(TreeNode));
        (*t)->data = k;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
        return 1;
    }
    if((*t)->data < k){
        return BST_insert_recursion(&(*t)->rchild,k);       
    }
    if((*t)->data > k){
        return BST_insert_recursion(&(*t)->lchild,k);    
    }
    if ((*t)->data == k)
    {
        return 0;
    }
}

TreeNode *BST_search(Tree t,TreeNode **temp,elemtype k){
    // while (t != NULL)
    // {
    //      if(t->data < k){
    //         t = t->rchild; 
    //         continue;      
    //     }
    //     if(t->data > k){
    //         t = t->lchild;
    //          continue;    
    //     }
    //     if (t->data == k)
    //     {
    //         return t;
    //     }
    // }
    // return NULL;
    while (t != NULL && k != t->data)
    {
        if(t->data > k){
              *temp = t;
            t = t->lchild;
        }
        else{
              *temp = t;
            t = t->rchild;
        }
    }
    return t;
}

TreeNode * BST_search_recursion(Tree t,elemtype k){
    if(t == NULL || t->data == k ){
        printf("%ld\n",t);
        return t;
    }
    if(t->data > k){
        return BST_search_recursion(t->lchild,k);       // return must be here. Beacause it have returned value.
    }
    if(t->data < k){
        return BST_search_recursion(t->rchild,k);
    }
}

void BST_delete(Tree t,elemtype k){
    if(t == NULL){
        printf("Tree is empty!");
        return;
    }
    TreeNode *pre;              //记录当前节点的前驱节点
    TreeNode *temp = BST_search(t,&pre,k);
    if(temp == NULL){
        printf("This Tree doesn't have the node!");
        return;
    }
    if(temp->lchild == NULL && temp->rchild == NULL)
    {       
            if(pre->lchild == NULL){  
                 pre->rchild = NULL;
            }
            else{  
                pre->lchild = NULL;
            } 
    }
    else if (temp->lchild == NULL && temp->rchild != NULL){
            if(pre->lchild == temp)
            {  pre->lchild = temp->rchild;}  
           else{  
               pre->rchild = temp->rchild;
            } 
    }
    else if(temp->rchild == NULL && temp->lchild != NULL){
          if(pre->lchild == temp)
            {  pre->lchild = temp->lchild;;}  
           else{  
               pre->rchild = temp->lchild;
            } 
    }
    else{
        TreeNode * replaceNode = temp->rchild;
        while (replaceNode ->lchild != NULL)
        {
            replaceNode = replaceNode->lchild;
        }
      
        pre = NULL;
        BST_search(t,&pre,replaceNode->data);
        temp->data = replaceNode->data;
        if(replaceNode->rchild != NULL){ 
            pre->lchild = replaceNode->rchild;
        }else{
             pre->lchild = NULL;
        }
    }
}



void preVisit(Tree t) {   //先序遍历
	if (!t) {
		return;
	}
	else
	{
		printf("%d", t->data);
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
		printf("%d->", t->data);
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
		printf("%d", t->data);
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
    printf("enQuene is %d\n",e->data);
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
    printf("deQuene is %d\n",(*e)->data);
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
            printf("%d\n",temp->data);
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
    Tree test;
    InitTree(&test);
    int number[9] = {5,4,8,2,6,3,7,10,9};
    for (int i = 0; i < sizeof(number)/sizeof(int); i++)
    {
        BST_insert(&T,number[i]);
        BST_insert_recursion(&test,number[i]);
    }
  
    // preVisit(T);
    // printf("\n");
    middleVisit(T);
    printf("\n");
    // backVisit(T);
    // printf("\n");

    printf("----------------------------------------------\n");
    BST_delete(T,10);
    printf("\n");
    // preVisit(test);
    // printf("\n");
    middleVisit(T);
    printf("\n");
    // backVisit(test);
    // printf("\n");
    // printf("The number of leafNode is %d\n",countLeaf(T));
    // printf("The Depth of tree is %d\n",depth(T));
    // printf("The number of treeNode is %d\n",count(T));

    // levelVisit(T);
    printf("\n");
    system("pause");
}