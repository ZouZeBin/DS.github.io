/*7�㷨ʵ���� 3.2 ������ŵ������
����������
	��һ����������һ����С���ȵ� n ��Բ�̣� ��Բ�̴�С������Ϊ 1�� 2������ n�� 
	��ʼʱ�� ��ЩԲ�����¶���ɢ�ҵص���һ�� ��Ҫ�������µķ�ת���� �����ɴη�ת�� 
	�������ϵ���һ��Բ���ź��� �������Ե����ϣ� �Ӵ�С��˳����á�

��ת���� ÿ�ο��Խ���ϵ�����Բ�̷�ת�� �������෴�Ĵ�����á�

  ʵ������
  ���ڸ����Ĵ�С���ȵ� n ��Բ�̵ĳ�ʼ״̬�� �÷�ת���㽫 n ��Բ������

  �������룺
  ���ļ� input.txt �����������ݡ� 
  ��һ���Ǹ�����Բ���Զ����µĳ�ʼ״̬��
  
  ��������
  �������õķ�ת��������������ļ� output.txt��
  �����ת���� flip(i)ʱ�� ֻҪ������� i ���ɣ� ���������ÿո�ָ���
Դ�������£�
1�� ������ŵ��.cpp*/ 

#include"stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include"�������.h"
typedef int SElemType;
#include"stack.h"
//���ض�ջ������ͷ�ļ�
#define SIZE 10
int len,count=0;
SqStack *S;

void display(int a[]) //��ӡÿ���������������
{ 
	for(int t=0;t<len;t++) 
		printf("%d,",a[t]);
}

void Flip(int n,int A[]) //����ջ������Բ�̷�ת,ʹ�ϴ�������
{ 
	int i;
	printf("\n ��ת H[%d] ��ǰ��Բ��: ",n);
	for(i=0;i<=n;i++) 
		Push(S,A[i]);
	for(i=0;i<=n;i++) 
		Pop(S,&A[i]);
	display(A);
	save(len-n+1);
	count++;
}
	
void main()
{ 
	int H[SIZE];
	int i,j,max,k;
	InitStack(&S);
	printf("��ŵ��ԭʼ״̬:");
	len=load(H);
	printf("\n\n ��ת�������£� \n");
	for(j=len-1;j>0;j--)
	{ 
		max=H[0];k=0;
		for(i=1;i<=j;i++)//��������Բ��
		{ 
			if(max<H[i])
			{ 
				max=H[i];
				k=i;
			}
		}
		
		if(k==0) 
		{
			Flip(j,H);
		} //������Բ�������Ϸ��� ������Բ�̷�תһ��

		else if(k<j)
		{ 
			Flip(k,H);
			Flip(j,H);
		}
		//���Բ�����м����� �Ƚ��䷭ת�����Ϸ��� �ٽ�������Բ�̷�ת�� ���䷭ת�����·�
	}
	printf("\n\n һ��������%d �η�ת\n",count);
	DestroyStack(S);
	getchar();
}

