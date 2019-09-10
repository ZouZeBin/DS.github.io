/*
	https://wenku.baidu.com/view/0ea1ee4cfbd6195f312b3169a45177232f60e4f9.html
	给定正整数 n， 计算左边轨道车皮编号依次为 1， 2， ……， n 时， 右边轨道最多可以得
	到多少个不同的车皮编序方案。
	
	数据输入：
	由文件 input.txt 给出输入数据。 
	第一行有 1 个正整数 n， 表示有 n 个车皮。

	结果输出：
	将计算出的所有不同编序方案， 以及不同的编序方案数输出到文件 output.txt。 
	文件的每行时一个编序方案， 最后一行是编序方案数。
	
源程序如下：
1、 车皮编序.cpp
*/ 
// 车皮编序问题.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
typedef int SElemType;
#include "stack.h"
#include "输入输出.h"
//#include <iostream>
#include <stdio.h>

void initer(int A[],int n)//初始化 A
{ 
	int i;
	for(i=0;i<n;i++)
	{ 
		A[i]=0;
		A[2*n-i-1]=1; 
	}
}

void adder(int A[],int n)//进位
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

bool real(int A[],int n)//判断是否符合条件
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

bool breakdown(int A[],int n)//退出
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
	printf("\n 共有 %d 种情况",count);
	save(count);
	getchar();
}

