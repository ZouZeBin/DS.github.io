/*�㷨ʵ���� 3.4 ���ֵ�����
  ���������� 
  ���� n ������ a0�� a1�� ������ an-1 ��ɵ����С� 
  ������Ԫ�� ai �����ֵ�Ԫ�� ak ����Ϊai ���ұ�������Ҳ�С������Ԫ�ء� 
  ����ĿҪ�����������ÿ��Ԫ�ص����ֵ�Ԫ�ص�λ�á�
  Ԫ��ai�����ֵ�Ԫ��Ϊ ak ʱ�� �� k ΪԪ�� ai �����ֵ�Ԫ�ص�λ�á� 
  ��Ԫ��aiû�����ֵ�Ԫ��ʱ�� Լ�������ֵ�Ԫ��λ��Ϊ-1��

  ʵ������
  ���ڸ����� n ������ a0�� a1�� ������ an-1 ��ɵ����У� ������Ӧ�����ֵ�Ԫ��λ�����С�
 
  �������룺
  ���ļ� input.txt �����������ݡ� 
  �� 1 ���������� n�� ��ʾ���� n �������� 
  �� 2 ��������a0�� a1�� ����an-1��
  
  ��������
  ��������������������Ӧ�����ֵ�Ԫ��λ������������ļ� output.txt �С�
Դ�������£�
1�� ���ֵ�����.cpp������ʵ�֣�

 Input.txt
10
6 1 4 3 6 2 4 7 3 5
 Output.txt
4 2 4 4 7 6 7 -1 9 -1
// ���ֵ�����.cpp : Defines the entry point for the console application.
*/ 
#include "stdafx.h"
#include "stdio.h"
#include "�������.h"
#define SIZE 50
#define ERROR -1
void main()
{ 
	int n,i,j,m;
	int A[SIZE];
	n=load(A);
	for(i=0;i<n;i++) //ʹ�������±�ȷ�����ֵ�Ԫ��ֵ
	{ 
		m=A[i];
		for(j=i+1;A[j]<m;j++);
		if(j!=SIZE)
		{ 
			save(j);
			printf("%d ",j);
		}
		else
		{ 
			save(ERROR);
			printf("%d ",ERROR);
		}
	}
}


//2�� ���ֵ�����.cpp��ջʵ�֣�
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
typedef int SElemType;
#define STACK_INIT_SIZE 10
#include "stack.h"

SqStack *op;
Status visit(SElemType *e)
{ 
	printf("%d ",*e);
	return OK;
}

void load()
{ 
	FILE *fp;
	int m,n,i;
	InitStack(&op);
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&m);
	for(i=0;i<m;i++)
	{ 
		fscanf(fp,"%d",&n);
		Push(op,n);
	}
	printf("������������Ϊ����%d ���������� \n",m);
	StackTraverse(*op,visit);
	fclose(fp);
}

void main()
{ 
	int *a,*b;
	load();
	printf("\n\n ���ֵ�λ������Ϊ�� \n");
	a=op->base+1;
	b=op->base;
	while(b!=op->top) //ʹ�ö�ջָ��ȡ�����ֵ�Ԫ��λ�ò����
	{
		if(*a>=*b)
		{ 
			printf("%d ",a-op->base);
			++b;
			a=b+1;
		}
		else
		{ 
			if(a>=op->top)
			{ 
				printf("-1 ");
				b++;
				a=b+1;
			}
		else a++;
		} 
	}
	DestroyStack(op);
}

