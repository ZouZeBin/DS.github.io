#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int v,height;//权值，高度
	node *lchild,*rchild;//左右孩子节点地址 
	int data;
};

//生成一个新节点，v为节点权值
node *newNode(int v){
	node *Node=new Node;
	Node->v=v;//权值为v
	Node->height=1;//初始高度
	Node->lchild=Node->rchild=NULL;//初始状态没有左右孩子
	return Node; 
} 
//计算当前高度height
int getHeight(node *root){
	if(root==NULL) return 0;//空节点高度为0
	return root->height; 
} 
//计算root的平衡因子
int getBalanceFactor(node *root){
	//左孩子高度减去右孩子高度
	return  getHeight(root->lchild)-getHeight(root->rchild);
}
//更新节点height
void updateHeight(node *root){
	//max(左孩子高度,右孩子高度)+1
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1; 
} 


//查找操作
void search(node* root,int x){
	if(root==NULL){
		//空树，查找失败
		printf("search failed\n");
		return; 
	}
	if(x==root->data){
		//查找成功
		printf("%d\n",root->data); 
	}
	else if(x<root->data){//x比根节点小，说明x在左子树 
		search(root->lchild,x); 
	}else{
		search(root->rchild);//右子树 
	}
} 

//插入操作
//1、左旋
/*
			 A					
	      	/\	
		  X1   B     
		      /\	
	         X2 X3
	1、先让B的左子树X2成为A的右子树
	2、再让A成为B的左子树
	3、将根节点设置为B 
			 B
	      	/\	
		   A  X3
	      /\	
	     X1 X2
*/ 

//Left Roation
void L(node* &root){
	node* temp=root->rchild;//root指向节点A，temp指向节点B
	root->rchild=temp->lchild; //步骤1
	temp->lchild=root;//步骤2
	updateHeight(root);//更新A高度 
	updateHeight(temp);//更新B高度
	root=temp;//步骤3 
} 

//2、右旋
/*
			 B
	      	/\	
		   A  X3
	      /\	
	     X1 X2
	1、先让A的右子树X2成为B的左子树
	2、再让B成为A的左子树
	3、将根节点设置为A 
			 A					
	      	/\	
		  X1   B     
		      /\	
	         X2 X3
*/ 
//Right Rotation
void R(node* &root){
	node* temp=root->lchild;//root指向节点B，temp指向节点A
	root->lchild=temp->rchild; //步骤1
	temp->rchild=root;//步骤2
	updateHeight(root);//更新B高度 
	updateHeight(temp);//更新A高度
	root=temp;//步骤3 
} 

//插入权值为v的节点 不考虑平衡操作 
void insert1(node* &root,int v){
	if(root==NULL){//到达空结点 
		root=newNode(v);
		return;
	}
	if(v<root->v){//v比根节点的权值小 
		insert(root->lchild,v); //往左子树叉 
	}else{//v比根节点的权值大 
		insert(root->rchild,v);//往右子树叉 
	}
} 

//考虑平衡操作
void insert(node *&root,int v){
	if(root==NULL){
		//到达空结点
		root=newNode(v);
		return; 
	}
	if(v<root->v){
		//1、v比根的权值小
		insert(root->lchild,v);
		updeteHeight(root);//更新树高
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){
				//LL型
				R(root); //直接对root右旋 
			}else if(getBalanceFactor(root->lchild)==-1){
				//LR型
				L(root->rchild);//先对root->rchild左旋
				R(root);//再对root右旋 
			}
		} 
	}else{
		//2、v比根节点权值大
		insert(root->rchild,v);
		updateHeight(root);//更新树高
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){
				//RR型
				L(root); //对root进行左旋 
			}else if(getBalanceFactor(root->rchild)==1){
				//RL型
				R(root->rchild);//先对root->rchild进行右旋 
				L(root); //再对root进行左旋 
			}
		} 
	} 
} 

//AVL树的建立
node* Create(int data[],int n){
	node* root=NULL;//新建空结点 
	for(int i;i<n;i++){
		insert(root,data[i]);//将data[0]-data[n-1]插入 
	}
	return root;//返回根节点 
} 
 
