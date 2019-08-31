#include<cstdio>
#include<cstring>
#include<queue> 
#include<algorithm>
using namespace std;
const int maxn=50;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn],in[maxn],post[maxn];//先序 中序 后序
int n;//节点个数

//当前二叉树的后序区间[postL,postR]  中序区间[inL,inR]
//create函数返回创建二叉树的根节点
node* create(int postL,int postR,int inL,int inR){
	if(postL>postR){
		return NULL;//后序序列长度小于等于0，直接返回 
	}
	node* root=new node;//创建一个新节点存放当前二叉树的根节点
	root->data=post[postR];//在后序节点中寻找根节点 
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR]){//在中序序列找到根节点所在位置 
			break;
		}
	} 
	int numLeft=k-inL;//左子树根节点的个数
	root->lchild=create(postL,postL+numLeft-1,inL,k-1);
	root->rchild=create(postL+numLeft,postR-1,k+1,inR);
	return root; 
} 

int num=0;//已输出的节点个数
void BFS(node* root){
	queue<node*> q;//队列里存地址
	q.push(root);//将根节点入队
	while(!q.empty()){
		node* now=q.front();//取出队首元素 
		q.pop();
		printf("%d",now->data);//访问队首元素
		if(num<n){
			printf(" ");
		} 
		if(now->lchild!=NULL) q.push(now->lchild);//左子树非空
		if(now->rchild!=NULL) q.push(now->rchild);//右子树非空 
	} 
} 

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	node* root=create(0,n-1,0,n-1);//建树
	BFS(root); 
	return 0;
} 








