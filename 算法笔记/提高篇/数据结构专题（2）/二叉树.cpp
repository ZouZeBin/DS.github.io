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
	node* Node=new node;//����һ���ռ�
	Node->data=v;//ȨֵΪv 
	Node->lchild=Node->rchild=NULL;//��ʼ״̬���Һ���Ϊ��
	return Node;//���ؽڵ��ַ 
}

//����
void search(node* root,int x,int newdata){
	if(root==NULL){
		return;//�������ݹ�߽磨����ͬ�� 
	}
	search(root->lchild,x,newdata);//������������
	search(root->rchild,x,newdata);//������������ 
}  

//����
void insert(node* &root,int x){
	if(root==NULL){//����,�ݹ�߽磨����λ�ã� 
		root=newNode(x); 
		return; 
	}
	if(/*�����ж�*/){
		insert(root->lchild,x);
	} else{
		insert(root->rchild,x);
	}
} 

//����
node* Create(int data[],int n){
	node* root=NULL;//�½��ս��
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	} 
	return root;
} 

//�������
void preorder(node* root){
	if(root==NULL){
		return;//����������ݹ�߽� 
	}
	//���ʸ��ڵ�root���������������
	printf("%d\n",root->data);
	//����������
	preorder(root->lchild);
	//����������
	preorder(root->rchild;) 
} 
//�������
void inorder(node* root){
	if(root==NULL){
		return;//����������ݹ�߽� 
	}
	//����������
	inorder(root->lchild);
	//���ʸ��ڵ�root���������������
	printf("%d\n",root->data);
	//����������
	inorder(root->rchild);	 
} 

//�������
void postorder(node* root){
	if(root==NULL){
		return;//����������ݹ�߽� 
	}
	//����������
	postorder(root->lchild);
	//����������
	postorder(root->rchild);
	//���ʸ��ڵ�root���������������
	printf("%d\n",root->data);	 
} 

//�������///////////////////////////////////////
struct node{
	int data;//������
	int layer;//���
	node* lchild;
	node* rchild; 
}; 

void layerOrder(node *root){
	queue<node*> q;//���д洢��ַ
	root->layer=1;//���ڵ�Ĳ�� 
	q.push(root);//���ڵ��ַ���
	while(!q.empty()){
		node* now=q.front();//ȡ������Ԫ��
		q.pop();
		printf("%d",now->data);//���ʶ���Ԫ��
		if(now->lchild!=NULL) {
			now->lchild->layer=now->layer+1;//���Ӳ��+1 
			q.push(now->lchild);
		}
		if(now->rchild!=NULL) {
			now->rchild->layer=now->layer+1;//�Һ��Ӳ��+1 
			q.push(now->rchild);
		} 
	} 
}
/////////////////////////////////////////////////
//������������򴴽���
node* createByPreandIn(int preL,int PreR,int inL,int inR){
	if(preL>preR){
		return NULL;//�������г���С�ڵ���0ֱ�ӷ��� 
	}
	node* root=new node;//�½���㣬������ŵ�ǰ���������ڵ�
	root->data=pre[preL];//�½ڵ�������Ϊ���ڵ��ֵ
	int k;
	for(k=intL;k<=intR;k++){
		if(in[k]==pre[preL]){//�����������ҵ����ڵ� 
			break; 
		}
	} 
	int numLeft=k-intL;//�������ڵ����
	root->lchild=createByPreandIn(perL+1,preL+numLeft,inL,k-1);
	root->rchild=createByPreandIn(preL+numLeft+1,preR,k+1,inR); 
	return root;
} 




int main(){
	
	return 0;
} 
