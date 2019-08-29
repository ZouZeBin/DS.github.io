#include<stdio.h>
#include<stdlib.h>

struct node{//����ڵ� 
	int data;
	node *next;
};
 
//1����������
node* create(int Array[]){
	node* p,*pre,*head;//pre����ǰ����㣬headΪͷ�ڵ�
	head=new node;//����ͷ�ڵ�
	head->next=NULL;//ͷ�ڵ㲻��Ҫ������ָ�����ʼֵΪ��
	pre=head;//��¼preΪhead
	for(int i=0;i<5;i++){
		p=new node;//�½��ڵ�
		//��Array[i]��ֵ���½��Ľڵ���Ϊ������Ҳ����scanf����
		p->data=Array[i];
		p->next=NULL;//�½ڵ��ָ����Ϊ�� 
		pre->next=p; //ǰ���ڵ��ָ����Ϊ�½��ڵ�ĵ�ַ
		pre=p;//��pre��Ϊp����Ϊ��һ���ڵ��ǰ���ڵ� 
	} 
	return head;//����ͷ�ڵ�ָ�� 
} 

//2������Ԫ��,����x���� 
int search(node* head,int x){
	int count=0;//������
	node *p=head->next;//�ӵ�һ���ڵ㿪ʼ
	while(p!=NULL){
		if(p->data==x){
			count++;
		}
		p=p->next;
	} 
	return count;
}

//3������Ԫ��
void insert(node* head,int pos,int x){
	node *p=head;
	for(int i=0;i<pos-1;i++){
		p=p->next;//pos-1��Ϊ�˵�����λ�õ�ǰһ���ڵ� 
	}
	node* q=new node;//�½��ڵ�
	q->data=x;
	q->next=p->next;
	p->next=q; 
} 
//4��ɾ��Ԫ�� 
void del(node* head,int x){
	node* p=head->next;//p�ӵ�һ��ָ�뿪ʼö�� 
	node* pre=head;//preʼ�ձ���p��ǰ�����
	while(p!=NULL){
		if(p->data==x){
			pre->next=p->next;
			delete(p);
			p=pre->next;
		}else{//���Ʋ��� 
			pre=p;
			p=p->next;
		}
	} 
}


int main(){
	int Array[5]={5,3,6,1,2};
	node*L=create(Array);//�½���������ͷָ��head��ֵ��L
	L=L->next;//�ӵ�һ���ڵ㿪ʼ��������
//	while(L!=NULL){
//		printf("%d",L->data);//���ÿ��������
//		L=L->next; 
//	} 
	insert(L,2,1);//���� 
	del(L,1);
	printf("%d",search(L,1));//���Ҹ��� 
	return 0;
} 



