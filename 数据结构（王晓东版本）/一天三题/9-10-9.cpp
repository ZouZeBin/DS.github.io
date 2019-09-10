/*算法实验题 3.4 亲兄弟问题
  问题描述： 
  给定 n 个整数 a0， a1， ……， an-1 组成的序列。 
  序列中元素 ai 的亲兄弟元素 ak 定义为ai 的右边最靠近它且不小于它的元素。 
  本题目要求给定序列中每个元素的亲兄弟元素的位置。
  元素ai的亲兄弟元素为 ak 时， 称 k 为元素 ai 的亲兄弟元素的位置。 
  当元素ai没有亲兄弟元素时， 约定其亲兄弟元素位置为-1。

  实验任务：
  对于给定的 n 个整数 a0， a1， ……， an-1 组成的序列， 计算相应的亲兄弟元素位置序列。
 
  数据输入：
  由文件 input.txt 给出输入数据。 
  第 1 行是正整数 n， 表示给定 n 个整数。 
  第 2 行是整数a0， a1， ……an-1。
  
  结果输出：
  将计算出的与给定序列相应的亲兄弟元素位置序列输出到文件 output.txt 中。
源程序如下：
1、 亲兄弟问题.cpp（数组实现）

 Input.txt
10
6 1 4 3 6 2 4 7 3 5
 Output.txt
4 2 4 4 7 6 7 -1 9 -1
// 亲兄弟问题.cpp : Defines the entry point for the console application.
*/ 
#include "stdafx.h"
#include "stdio.h"
#include "输入输出.h"
#define SIZE 50
#define ERROR -1
void main()
{ 
	int n,i,j,m;
	int A[SIZE];
	n=load(A);
	for(i=0;i<n;i++) //使用数组下标确定亲兄弟元素值
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


//2、 亲兄弟问题.cpp（栈实现）
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
	printf("输入整数序列为（共%d 个整数）： \n",m);
	StackTraverse(*op,visit);
	fclose(fp);
}

void main()
{ 
	int *a,*b;
	load();
	printf("\n\n 亲兄弟位置序列为： \n");
	a=op->base+1;
	b=op->base;
	while(b!=op->top) //使用堆栈指针取得亲兄弟元素位置并输出
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

