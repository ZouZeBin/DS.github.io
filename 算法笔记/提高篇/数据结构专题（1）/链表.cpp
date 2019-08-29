#include<stdio.h>
#include<stdlib.h>

struct node{//链表节点 
	int data;
	node *next;
};
 
//1、创建链表
node* create(int Array[]){
	node* p,*pre,*head;//pre保存前驱结点，head为头节点
	head=new node;//创建头节点
	head->next=NULL;//头节点不需要数据域，指针域初始值为空
	pre=head;//记录pre为head
	for(int i=0;i<5;i++){
		p=new node;//新建节点
		//将Array[i]赋值给新建的节点作为数据域，也可以scanf输入
		p->data=Array[i];
		p->next=NULL;//新节点的指针域为空 
		pre->next=p; //前驱节点的指针域为新建节点的地址
		pre=p;//把pre设为p，作为下一个节点的前驱节点 
	} 
	return head;//返回头节点指针 
} 

//2、查找元素,返回x个数 
int search(node* head,int x){
	int count=0;//计数器
	node *p=head->next;//从第一个节点开始
	while(p!=NULL){
		if(p->data==x){
			count++;
		}
		p=p->next;
	} 
	return count;
}

//3、插入元素
void insert(node* head,int pos,int x){
	node *p=head;
	for(int i=0;i<pos-1;i++){
		p=p->next;//pos-1是为了到插入位置的前一个节点 
	}
	node* q=new node;//新建节点
	q->data=x;
	q->next=p->next;
	p->next=q; 
} 
//4、删除元素 
void del(node* head,int x){
	node* p=head->next;//p从第一个指针开始枚举 
	node* pre=head;//pre始终保存p的前驱结点
	while(p!=NULL){
		if(p->data==x){
			pre->next=p->next;
			delete(p);
			p=pre->next;
		}else{//后移查找 
			pre=p;
			p=p->next;
		}
	} 
}


int main(){
	int Array[5]={5,3,6,1,2};
	node*L=create(Array);//新建链表，返回头指针head赋值给L
	L=L->next;//从第一个节点开始有数据域
//	while(L!=NULL){
//		printf("%d",L->data);//输出每个数据域
//		L=L->next; 
//	} 
	insert(L,2,1);//插入 
	del(L,1);
	printf("%d",search(L,1));//查找个数 
	return 0;
} 



