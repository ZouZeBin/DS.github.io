/*7算法实验题 3.2 单柱汉诺塔问题
问题描述：
	在一个塔座上有一叠大小不等的 n 个圆盘， 各圆盘从小到大编号为 1， 2……， n。 
	初始时， 这些圆盘自下而上散乱地叠在一起。 现要求按照以下的翻转规则， 经若干次翻转， 
	将塔座上的这一叠圆盘排好序， 即按照自底向上， 从大到小的顺序叠置。

翻转规则： 每次可以将最顶上的若干圆盘翻转， 即按其相反的次序叠置。

  实验任务：
  对于给定的大小不等的 n 个圆盘的初始状态， 用翻转运算将 n 个圆盘排序。

  数据输入：
  由文件 input.txt 给出输入数据。 
  第一行是给定的圆盘自顶向下的初始状态。
  
  结果输出：
  排序所用的翻转运算依次输出到文件 output.txt。
  输出翻转运算 flip(i)时， 只要输出数字 i 即可， 相邻数字用空格分隔。
源程序如下：
1、 单柱汉诺塔.cpp*/ 

#include"stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include"输入输出.h"
typedef int SElemType;
#include"stack.h"
//加载堆栈操作的头文件
#define SIZE 10
int len,count=0;
SqStack *S;

void display(int a[]) //打印每次排序后的序列情况
{ 
	for(int t=0;t<len;t++) 
		printf("%d,",a[t]);
}

void Flip(int n,int A[]) //利用栈将若干圆盘翻转,使较大者在下
{ 
	int i;
	printf("\n 翻转 H[%d] 以前的圆盘: ",n);
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
	printf("汉诺塔原始状态:");
	len=load(H);
	printf("\n\n 翻转过程如下： \n");
	for(j=len-1;j>0;j--)
	{ 
		max=H[0];k=0;
		for(i=1;i<=j;i++)//查找最大的圆盘
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
		} //如果最大圆盘在最上方， 将所有圆盘翻转一次

		else if(k<j)
		{ 
			Flip(k,H);
			Flip(j,H);
		}
		//如果圆盘在中间区域， 先将其翻转至最上方， 再进行所有圆盘翻转， 将其翻转至最下方
	}
	printf("\n\n 一共进行了%d 次翻转\n",count);
	DestroyStack(S);
	getchar();
}

