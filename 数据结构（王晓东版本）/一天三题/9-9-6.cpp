/*
	https://wenku.baidu.com/view/0ea1ee4cfbd6195f312b3169a45177232f60e4f9.html
	���������� n�� ������߹����Ƥ�������Ϊ 1�� 2�� ������ n ʱ�� �ұ߹�������Ե�
	�����ٸ���ͬ�ĳ�Ƥ���򷽰���
	
	�������룺
	���ļ� input.txt �����������ݡ� 
	��һ���� 1 �������� n�� ��ʾ�� n ����Ƥ��

	��������
	������������в�ͬ���򷽰��� �Լ���ͬ�ı��򷽰���������ļ� output.txt�� 
	�ļ���ÿ��ʱһ�����򷽰��� ���һ���Ǳ��򷽰�����
	
Դ�������£�
1�� ��Ƥ����.cpp
*/ 
// ��Ƥ��������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
typedef int SElemType;
#include "stack.h"
#include "�������.h"
//#include <iostream>
#include <stdio.h>

void initer(int A[],int n)//��ʼ�� A
{ 
	int i;
	for(i=0;i<n;i++)
	{ 
		A[i]=0;
		A[2*n-i-1]=1; 
	}
}

void adder(int A[],int n)//��λ
{ 
	int i=n;
	if(n>=1)
	{ 
		A[i]++;
		if(A[i]==2)
		{ 
			A[i]%=2;
			adder(A,n-1);
		} 
	}
}

bool real(int A[],int n)//�ж��Ƿ��������
{ 
	int i,count1=0,count2=0;
	for(i=0;i<2*n;i++)
	{ 
		if(A[i]==0)
		count1++;
		else
		count2++;
		if(count2>count1)
			return false;
	}
	if(count1==count2)
		return true;
	return false;
}

bool breakdown(int A[],int n)//�˳�
{ 
	int i,j = 0;
	for(i=0;i<2*n;i+=2)
	{ 
		if(A[i]==0&&A[i+1]==1)
		j++;
	}
	if(j == n) return true;
	else return false;
}

void main()
{ 
	int n,i,e,k,t,count=0;
	int A[SIZE],out[SIZE]={0};
	SqStack *S;
	n=load();
	initer(A,n);
	InitStack(&S);
	t=0;
	for(i=0;i<2*n;i++)
	{ 
		k=i+1;
		if(A[i]==0) Push(S,k);
		else
		{ 
			Pop(S,&e);
			printf("%d ",e);
			out[t]=e;
			t++;
		}
    }
	printf("\n");
	count++;
	save(out);
	while(n!=1)
	{ 
		adder(A,2*n-2);
		if(real(A,n))
		{ 
			k=1;
			t=0;
			for(i=0;i<2*n;i++)
			{ 
				if(A[i]==0)
				{ 
					Push(S,k); k++; 
				}
				else
				{ 
					Pop(S,&e);
					printf("%d ",e);
					out[t]=e;
					t++;
				} 
			}
			printf("\n");
			count++;
			save(out);
		}
		if(breakdown(A,n))
		break;
	}
	printf("\n ���� %d �����",count);
	save(count);
	getchar();
}

