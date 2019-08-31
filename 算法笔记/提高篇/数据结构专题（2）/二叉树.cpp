#include<iostream>
#include<queue>
using namespace std;
//struct node{
//	int data;
//	node* lchild;
//	node* rchild;
//};
node* root=NULL;

node* newNode(int v){
	node* Node=new node;//申请一个空间
	Node->data=v;//权值为v 
	Node->lchild=Node->rchild=NULL;//初始状态左右孩子为空
	return Node;//返回节点地址 
}

//查找
void search(node* root,int x,int newdata){
	if(root==NULL){
		return;//空树，递归边界（死胡同） 
	}
	search(root->lchild,x,newdata);//往左子树搜索
	search(root->rchild,x,newdata);//往右子树搜索 
}  

//插入
void insert(node* &root,int x){
	if(root==NULL){//空树,递归边界（插入位置） 
		root=newNode(x); 
		return; 
	}
	if(/*插入判断*/){
		insert(root->lchild,x);
	} else{
		insert(root->rchild,x);
	}
} 

//创建
node* Create(int data[],int n){
	node* root=NULL;//新建空结点
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	} 
	return root;
} 

//先序遍历
void preorder(node* root){
	if(root==NULL){
		return;//到达空树，递归边界 
	}
	//访问根节点root，将其数据域输出
	printf("%d\n",root->data);
	//访问左子树
	preorder(root->lchild);
	//访问右子树
	preorder(root->rchild;) 
} 
//中序遍历
void inorder(node* root){
	if(root==NULL){
		return;//到达空树，递归边界 
	}
	//返回左子树
	inorder(root->lchild);
	//访问根节点root，将其数据域输出
	printf("%d\n",root->data);
	//访问右子树
	inorder(root->rchild);	 
} 

//后序遍历
void postorder(node* root){
	if(root==NULL){
		return;//到达空树，递归边界 
	}
	//访问左子树
	postorder(root->lchild);
	//访问右子树
	postorder(root->rchild);
	//访问根节点root，将其数据域输出
	printf("%d\n",root->data);	 
} 

//层序遍历///////////////////////////////////////
struct node{
	int data;//数据域
	int layer;//层次
	node* lchild;
	node* rchild; 
}; 

void layerOrder(node *root){
	queue<node*> q;//队列存储地址
	root->layer=1;//根节点的层次 
	q.push(root);//根节点地址入队
	while(!q.empty()){
		node* now=q.front();//取出队首元素
		q.pop();
		printf("%d",now->data);//访问队首元素
		if(now->lchild!=NULL) {
			now->lchild->layer=now->layer+1;//左孩子层次+1 
			q.push(now->lchild);
		}
		if(now->rchild!=NULL) {
			now->rchild->layer=now->layer+1;//右孩子层次+1 
			q.push(now->rchild);
		} 
	} 
}
/////////////////////////////////////////////////
//给定先序和中序创建树
node* createByPreandIn(int preL,int PreR,int inL,int inR){
	if(preL>preR){
		return NULL;//先序序列长度小于等于0直接返回 
	}
	node* root=new node;//新建结点，用来存放当前二叉树根节点
	root->data=pre[preL];//新节点数据域为根节点的值
	int k;
	for(k=intL;k<=intR;k++){
		if(in[k]==pre[preL]){//中序序列中找到根节点 
			break; 
		}
	} 
	int numLeft=k-intL;//左子树节点个数
	root->lchild=createByPreandIn(perL+1,preL+numLeft,inL,k-1);
	root->rchild=createByPreandIn(preL+numLeft+1,preR,k+1,inR); 
	return root;
} 




int main(){
	
	return 0;
} 
