/*14�㷨ʵ���� 6.1 ������������
  ����������
ͨ������Ԫ��λ��ʵ��������㷨ͨ����Ϊ���������㷨��
���ֻ����������Ԫ�ص�λ�ã� ���Ϊ���ڽ��������㷨�� 
���ڸ����Ĵ�����Ԫ�����У� ���ڽ��������㷨������Ҫ�������ٴ�Ԫ��λ�ã�
 
  ʵ������
���ڸ����Ĵ�����Ԫ�����У� �������ڽ��������㷨����Ԫ��λ�õ����ٴ�����
 
  �������룺
���ļ� input.txt �����������ݡ� 
�� 1 ���������� n�� ��ʾ�� n ������Ԫ�ء� 
������ 1 ������ n ��������ķǸ�������
  
  ��������
������������ٽ�����������������ļ� output.txt��
Դ�������£�
1�� ��������.cpp*/ 
// ������������.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include "�������.h"
typedef int Item;
#define SIZE 50
#define less(A,B) (A<B)
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {Item t=A;A=B;B=t;}
#define compswap(A,B) {if(less(B,A)) swap(A,B);}
int a[SIZE];
int Mini(int A[], int len,int k) //���Ҵ��������е���СԪ��
{ 	
	int i,m=k;
	for(i=k;i<len;i++)
	{ 
		if(less(a[i],a[m])) m=i;
	}
	return m;
}

int change_sort(int A[],int n) //ͨ������������СԪ�ػ�����ǰ
{ 
	int i,j,min,cnt=0;
	for (i=0;i<n;i++)
	{ 
		min=Mini(a,n,i);
		for (j=min;j>i;j--)
		{ 
			swap(A[j-1],A[j]);
			cnt++;
		}
		for(int t=0;t<n;t++) printf("%d,",a[t]);
		printf("\n");
	}
	return cnt;
}
void main(){
int l,count;
l=load(a);
count=change_sort(a,l);
printf("\n%d\n",count);
save(count);
}

