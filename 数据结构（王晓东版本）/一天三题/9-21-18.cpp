//18实现二叉树操作的头文件 BinaryTree.h（清华大学 王晓东）
#include"malloc.h"
typedef struct btnode* btlink;
struct btnode
{ 
	TreeItem element;
	btlink left;
	btlink right;
} Btnode;//二叉树的ADT定义

typedef btlink SElemType;
typedef btlink QElemType;
#include"LQueue.h"
#include"stack. h"
//创建新节点 
btlink NewBNode()
{ 
	btlink p;
	if((p=(btnode *) malloc(sizeof(Btnode) ) ) ==0) printf("Error, Exhausted memory. ") ;
	else return p;
}
typedef struct binarytree *BinaryTree;
typedef struct binarytree
{ 
	btlink root;
} BTree;

BinaryTree BinaryInit() //初始化二叉树
{ 
	BinaryTree T=(binarytree *) malloc(sizeof *T) ;
	T->root=0;
	return T;
}

int BinaryEmpty(BinaryTree T) //判断是否为空树
{ 
	return T->root==0;
}

TreeItem Root(BinaryTree T) //返回二叉树根节点的值
{ 
	if(BinaryEmpty(T) ) printf("Error, Tree is empty. ") ;
	return T->root->element;
}

void MakeTree(TreeItem x, BinaryTree T, BinaryTree L, BinaryTree R) //建立二叉树
{ 
	T->root=NewBNode();
	T->root->element=x;
	T->root->left=L->root;
	T->root->right=R->root;
	L->root=R->root=0;
}

TreeItem BreakTree(BinaryTree T,BinaryTree L, BinaryTree R)//二叉树的分拆
{ 
	TreeItem x;
	if(!T->root) printf("Error, Tree is empty. ") ;
	x=T->root->element;
	L->root=T->root->left;
	R->root=T->root->right;
	T->root=0;
	return x;
}

void PreOrder(void(*visit)(btlink u), btlink t)//以下为递归前、中、后序遍历
{ 
	//前序 
	if(t)
	{ 
		(*visit) (t) ;
		PreOrder(visit, t->left) ;
	PreOrder(visit, t->right) ;
	}
}

void InOrder(void(*visit) (btlink u) ,btlink t)
{ 	
	//中序 
	if(t)
	{ 
		InOrder(visit, t->left) ;
		(*visit) (t) ;
		InOrder(visit, t->right) ;
	}
}

void PostOrder(void(*visit) (btlink u) ,btlink t)
{
	//后序 
	if(t)
	{ 
		PostOrder(visit, t->left) ;
		PostOrder(visit, t->right) ;
		(*visit) (t) ;
	}
}

void IPreOrder(void(*visit) (btlink u) ,btlink t) //二叉树非递归遍历
{
	SqStack *s;
	InitStack(&s) ;
	Push(s, t) ;
	while(!StackEmpty(*s) )
	{ 
		(*visit) (t=Pop(s) ) ;
		if(t->right) Push(s, t->right) ;
		if(t->left)
			Push(s, t->left) ;
	}
}
 
void IPreOrder(void(*visit) (btlink u) ,btlink t) //二叉树非递归遍历
{ 
	SqStack s;
	btlink p=t;
	InitStack(s) ;
	Push(s, t) ;
	while(!StackEmpty(s) )
	{
		while(GetTop(s, p) &&p)
		{ 
			Push(s, p->left) ;
			(*visit) (t=Pop(s) ) ;
		}
		if(!StackEmpty(s) )
		{ 
			(*visit) (t=Pop(s) ) ;
			Push(s, t->right) ;
		}
	}
}

void LevelOrder(void(*visit)(btlink u), btlink t)//层序遍历
{ 
	LinkQueue q;
	InitQueue(q) ;
	EnQueue(q, t) ;
	while(!QueueEmpty(q) )
	{ 
		(*visit) (t=DeQueue(q) ) ;
		if(t->left) EnQueue(q,t->left);
		if(t->right) EnQueue(q, t->right);
	} 
}
void outnode(btlink t)//以下为输出二叉树的前中后序列表
{ 
	printf("%d", t->element) ;
}

void PreOut(BinaryTree T)
{ 
	PreOrder(outnode, T->root) ;
}

void InOut(BinaryTree T)
{ 
	InOrder(outnode, T->root) ;
}

void PostOut(BinaryTree T)
{ 
	PostOrder(outnode, T->root) ;
}
void LevelOut(BinaryTree T)
{ 
	LevelOrder(outnode, T->root) ;
}
int Height(btlink t)//求二叉树高度
{ 
	int hl, hr;
	if(!t) { printf("Error, Tree is empty. ") ; return -1; }
	hl=Height(t->left) ;
	hr=Height(t->right) ;
	if(hl>hr) return ++hl;
	else return ++hr;
}

