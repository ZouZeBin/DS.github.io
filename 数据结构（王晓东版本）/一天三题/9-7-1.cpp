
/*
一章 引 论
1、算法实验题 1.1 哥德巴赫猜想问题
 问题描述：
哥德巴赫猜想： 任何一个大于 2 的偶数均可表示为两个素数之和。

 实验任务：
 验证哥德巴赫猜想。 计算给定的大偶数可以表示为多少对素数之和。
 
 数据输入：
 由文件 input.txt 给出输入数据。 每行有一个大偶数， 文件一数字 0 结尾。
 
 结果输出：
 将计算出的相应素数分解数输出到文件 output.txt。
 实验源代码：
 1、 哥德巴赫.cpp
*/ 
// 哥德巴赫.cpp : 定义控制台应用程序的入口点。
//#include "stdafx.h"
#include"输入输出.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PRIME_COUNT 50

int isPrime(int t)//判断 t 是否为素数
{
	int i, k=sqrt(t);//sqrt 对函数重载的定义不明确， 改成 float 型进行重载， 强制转换成 int 型
	for(i=2;i<=k;i++)
	if(t % i == 0) break;
	if (i>=k+1)
		return t;
	else return -1;
}

int* getPrimes(int max)//取得 N/2 以下的素数列表
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

int outEven(int primes[], int n)//考察符合要求的素数对
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
		printf("读入的大偶数为： ");
		printf("%d\n",n[i]);
		printf("待查找的素数表列为");
		primes= getPrimes(n[i]);
		printf("该偶数可以分解为%d 对素数之和.",outEven(primes,n[i]));
		printf("\n\n");
	}
	return 0;
}

