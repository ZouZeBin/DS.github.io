/*�㷨ʵ���� 2.1 ������������
	����������
	���� m �� n ά���� a1�� a2����am�� Ҫ����ͬ����������Ϊͬһ�ࡣ ���ó����������ͱ�
	������������������Ч�㷨��

	ʵ������
	���� m �� n ά������ ������ m �� n ά�����ɷ�Ϊ���ٸ��ࣿ
 
 	�������룺
	���ļ� input.txt �����������ݡ� 
	��һ���� 2 �������� m �� n�� �ֱ��ʾ����������������ÿ��������ά���� 
	�������� m ���У� ÿ���� n �������� ��ʾ��Ӧ�� n ά������

	��������
	��������������ȼ�����������ļ� output.txt��
	Դ�������£�*/ 
//1�� ��������.cpp
// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//
//#include"stdafx.h"
//#include"stdio.h"
//#include"malloc.h"
//#include"string.h"
//#include"�������.h"
#include<cstdio> 
#define SIZE 50
int N[SIZE];
typedef struct Rect
{ 
	char n[SIZE];
	struct Rect* next;
}Node;

typedef Node* link;//����� 

link head,tail;

int count=0,num=0;

void display() //�������
{ 
	link p=head;
	printf("\n ��%d �α���������£� \n",num);
	while(p)
	{ 
		printf("%s\n",p->n);
		p=p->next;
	}
	printf("\n һ����%d ������\n",count);
}

void Init(char a[])//�����ʼ��
{ 
	link tmp;
	head=(link)malloc(sizeof(Node));
	tmp=head;
	strcpy(head->n,a);
	head->next=NULL;
	tail=head;
	count++;
	num++;
}

void Insert(char a[]) //ͨ�������㽨������
{ 
	link tmp1,tmp2;
	tmp1=tail;
	tmp2=(link)malloc(sizeof(Node));
	strcpy(tmp2->n,a);
	tmp2->next=NULL;	
	tmp1->next=tmp2;
	tmp1=tmp1->next;
	tail=tmp2;
	count++;
}

void compare(char a[]) //ͨ���ַ����Ƚ�ȷ����������
{ 
	link tmp=head;
	int flag=0;
	while(tmp)
	{ 
		if(strcmp(tmp->n,a)==0)//����� 
		{
			flag=1;break;
		}
		tmp=tmp->next;
	}
	if((flag==0)&&tmp==NULL)
	Insert(a);
	display();
}

int main()
{ 
	char str[SIZE];
	FILE *fp;
	fp=fopen("input.txt","r");
	fgets(str,SIZE,fp);
	Init(str);
	display();
	while(!feof(fp))
	{ 
		fgets(str,SIZE,fp);
		num++;
		compare(str);
	}
	fclose(fp);
	save(count); 
	getchar(); 
	return 0;
}

