/*11�㷨ʵ���� 4.1 ���������
	����������
  �������һ������ĳ����������ͣ�����֧�ֵ����������ڶ������㣬 
  ����ͬ����ÿ��Ԫ���и��ӵ������ԡ� 
  ���������� Enqueue(x)��ͨ����������㲻ͬ�� 
  ���������Enqueue(x)���㽫Ԫ�� x ���뵱ǰ��������Ԫ�� x ����ͬһ���Ԫ�ص�β���� 
  ����е�����������ͨ������Ķ���������ͬ��
  


	ʵ������
  ��Ʋ�ʵ�ֳ���������������л���������㷨��
	
	�������룺
  ���ļ� input.txt �����������ݡ� 
  �� 1 ���������� n����ʾ�� n ������Ԫ�ء� 
  ��������n��ÿ�и���һ������Ԫ�ء� 
  ÿ�еĵ� 1 �������� t ��ʾ��������Ԫ�ظ����� 
  �������� t ����������ʾ�����е� t ��Ԫ�ء� 
  �ٽ��ŵĸ��У�ÿ�и��� 1 ���������㡣 
  ENQUEUE x ��ʾ��Ԫ�� x ��������У� DEQUEUE ��ʾɾ������Ԫ�ء� 
  �ļ������ STOP ��β��
	
	��������
  ��ÿ�� DEQUEUE ����ɾ���Ķ���Ԫ������������ļ� output.txt��
Դ�������£�
1�� �����.cpp
*/ 
// �����.cpp : �������̨Ӧ�ó������ڵ㡣
//
//#include "stdafx.h"
#include "stdio.h"
#include "string.h"
//#include "�������.h"
#include "malloc.h"

#define SIZE 50
void save(int m)
{ 
	FILE *fp;
	if((fp=fopen("output.txt","a"))==NULL)
	{ 
		printf("cannot open file.\n");
		return;
	}
	fprintf(fp,"%d\n",m);
	fclose(fp);
}


typedef struct list
{ 
	int id;
	int data;
	struct list * next;
}Node;

typedef Node * link;

link head,tail=NULL;

int count,L=0;

void Insert(int m,int n)
{ 
	link ptr,p,q;
	if(head==NULL)
	{ 
		head=(link)malloc(sizeof(Node));
		head->next=NULL;
		head->id=m;
		head->data=n;
	}
	else {
			p=ptr=head;
			q=(link)malloc(sizeof(Node));
			q->id=m;
			q->data=n;
			while((ptr->data<q->data)&&(ptr->next!=NULL))
			{
		     	p=ptr;
				ptr=ptr->next;
			}
			if(ptr->data>q->data)
			{ 	
				q->next=ptr;
				p->next=q;
			}
			else {
					ptr->next=q;
					q->next=NULL;
				}
			}
		}//ͨ�����ұȽϲ����㽨����������

int delete_node()
{ 
	link q,ptr;
	q=ptr=head;
	printf("���� ID�� %d ������Ԫ�� ֵ�� %d\n",ptr->id,ptr->data);
	int i=ptr->data;
	ptr=ptr->next;
	head=ptr;
	free(q);
	return i;
}//ɾ����ͷԪ�ز�����ֵ
 
void display()
{ 
	link p=head;
	printf("\n ��ǰ���й���״̬Ϊ�� \n");
	while(p)
	{ 
		printf("���� ID�� %d,Ԫ��ֵ�� %d\n",p->id,p->data);
		p=p->next;
	}
}

int main()
{ 
	FILE *fp;
	char a[SIZE];
	int que;
	int k,cnt;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&cnt);
	printf("ϵͳ��һ����%d ������ڹ���\n",cnt);
	fscanf(fp,"%s",a);
	while(strcmp(a,"STOP")!=0)
	{ 
		if(strcmp(a,"ENQUEUE")==0)
		{
			printf("%s:\n",a);	
			fscanf(fp,"%d",&que);
			Insert(que/100,que);
			display();
		}
		if(strcmp(a,"DEQUEUE")==0)
		{ 
			printf("%s:\n",a);
			k=delete_node();
			save(k);
			display();
		}
		fscanf(fp,"%s",a);
	}//ͨ���ַ����Ƚ�ȷ�����ʵ�ֵĶ��в�������Ӧ���ú�������ģ��

	fclose(fp);
	getchar();
	return 0;
}






