/*�㷨ʵ���� 3.3 ��ջģ������

	����������
	�赱ǰϵͳ���ж��ջ�ڹ����� ��ջģ������Ҫ��ģ�⵱ǰϵͳ�и�ջ�Ĺ���״̬��
	
 	ʵ������
	���ڸ�����ջ������ ģ��ϵͳ�и�ջ�Ĺ���״̬��
	
	�������룺
	���ļ� input.txt �����������ݡ� �� 1 ���������� n�� ��ʾ�� n ��ջ������ 
	�������� n �У�ÿ�и���һ��ջ����ָ� 
	ָ��"PUSH A B" ��ʾ�������� B ���뵽���Ϊ A ��ջ���� 
	ָ��"POP A" ��ʾ������Ϊ A ��ջ��Ԫ�ء�
	
    ��������
	������������ POP ָ�������������������ļ� output.txt�� 
	�����Ϊ A ��ջΪ��ʱ��ջ����ָ��"POP A" ��� 0��
Դ�������£�
1�� ��ջģ��.cpp
// ����ģ��.cpp : �������̨Ӧ�ó������ڵ㡣*/ 
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "�������.h"
#include "malloc.h"
typedef struct list
{	
	int id;
	int data;
	struct list * next;
}Node;

//���幤������
typedef Node * link;
link head,tail=NULL;
int count,L=0;

void Insert(int m,int n)
{ 
	link ptr,q;
	if(head==NULL)
	{ 
		head=(link)malloc(sizeof(Node));
		head->next=NULL;
		head->id=m;
		head->data=n;
	}
	else
	{ 
		ptr=head;
		q=(link)malloc(sizeof(Node));
		q->id=m;
		q->data=n;
		q->next=ptr;
		head=q;
	}	
}//ͨ�������㽨������

int delete_node(int n)
{ 
	link q,ptr=head;
	if(head->id==n)
	{ 
		printf("��ջ ID�� %d ���� ֵ�� %d\n",ptr->id,ptr->data);
		head=head->next;
		return ptr->data;
		free(ptr);
	}//�������ջ����ǵ�һ����㣬 ��ͷָ�����
	else
	{ 
		while((ptr->id!=n)&&ptr->next!=NULL)
		{ 
			q=ptr;
			ptr=ptr->next;
			if(ptr->id==n)
			{ 
				printf("��ջ ID�� %d ���� ֵ�� %d\n",ptr->id,ptr->data);
				q->next=ptr->next;
				return ptr->data;
				free(ptr);
			}
		}
	}
	return 0;
}//�������ջ�Ľ��λ�������м䣬 ����֮�� �ҵ�����ɾ��

void display()
{ 
	link p=head;
	printf("\n ��ǰ��ջ����״̬Ϊ�� \n");
	while(p)
	{ 
		printf("��ջ ID�� %d,ֵ�� %d\n",p->id,p->data);
		p=p->next;
	}
}//��ӡ��ǰ��ջ����״̬

void main()
{ 
	FILE *fp;
	char a[SIZE];
	int out[SIZE];
	int i=0,k,num;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&count);
	printf("ϵͳ��һ����%d ��ջ�ڹ���\n",count);
	while(!feof(fp))
	{ 
		fscanf(fp,"%s",a);
		if(strcmp(a,"push")==0)
		{	
			printf("%s:\n",a);
			fscanf(fp,"%d%d",&k,&num);
			Insert(k,num);
			display();
		}
		if(strcmp(a,"pop")==0)
		{ 
			fscanf(fp,"%d",&k);
			printf("%s:\n",a);
			i=delete_node(k);
			save(i);
			display();
		}
	}//���ж�ȡ�����ļ��� ͨ���ַ����Ƚ�ȷ����ջ������ ������Ӧ����
	fclose(fp);
	getchar();
}

