
/*
һ�� �� ��
1���㷨ʵ���� 1.1 ��°ͺղ�������
 ����������
��°ͺղ��룺 �κ�һ������ 2 ��ż�����ɱ�ʾΪ��������֮�͡�

 ʵ������
 ��֤��°ͺղ��롣 ��������Ĵ�ż�����Ա�ʾΪ���ٶ�����֮�͡�
 
 �������룺
 ���ļ� input.txt �����������ݡ� ÿ����һ����ż���� �ļ�һ���� 0 ��β��
 
 ��������
 �����������Ӧ�����ֽ���������ļ� output.txt��
 ʵ��Դ���룺
 1�� ��°ͺ�.cpp
*/ 
// ��°ͺ�.cpp : �������̨Ӧ�ó������ڵ㡣
//#include "stdafx.h"
#include"�������.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PRIME_COUNT 50

int isPrime(int t)//�ж� t �Ƿ�Ϊ����
{
	int i, k=sqrt(t);//sqrt �Ժ������صĶ��岻��ȷ�� �ĳ� float �ͽ������أ� ǿ��ת���� int ��
	for(i=2;i<=k;i++)
	if(t % i == 0) break;
	if (i>=k+1)
		return t;
	else return -1;
}

int* getPrimes(int max)//ȡ�� N/2 ���µ������б�
{
	static int primes[PRIME_COUNT + 1];
	int i, j,m;
	primes[1]=2;
	for (j = 2, i = 3; i <= max/2; i++)
	{ 
		m=isPrime(i);
		if (m>0) 
			primes[j++] = m;
	}
	for(i=1;i<j;i++) 
	printf("%d,",primes[i]);
	printf("\n");
	return primes;
}

int outEven(int primes[], int n)//�������Ҫ���������
{
	int i, p, q,count=0;
	for (i = 1; (p = primes[i]) != 0; i++)
	{ 
		if ((q =isPrime( n - p))>0)
		{
			printf("%d,%d\n", p, q);
			count++;
		}
	}
	return count;
}

int main()
{/*
int n,*primes;
scanf("%d",&n);
primes= getPrimes(n);
outEven(primes,n);
*/
	int *n,*primes;
	n=load();
	for(int i=0;i<SIZE;i++)
	{ 
		printf("\n");
		printf("����Ĵ�ż��Ϊ�� ");
		printf("%d\n",n[i]);
		printf("�����ҵ���������Ϊ");
		primes= getPrimes(n[i]);
		printf("��ż�����Էֽ�Ϊ%d ������֮��.",outEven(primes,n[i]));
		printf("\n\n");
	}
	return 0;
}

