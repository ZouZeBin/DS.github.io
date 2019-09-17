/*14算法实验题 6.1 交换排序问题
  问题描述：
通过交换元素位置实现排序的算法通常称为交换排序算法。
如果只允许交换相邻元素的位置， 则称为相邻交换排序算法。 
对于给定的待排序元素序列， 相邻交换排序算法最少需要交换多少次元素位置？
 
  实验任务：
对于给定的待排序元素序列， 计算相邻交换排序算法交换元素位置的最少次数。
 
  数据输入：
由文件 input.txt 给出输入数据。 
第 1 行是正整数 n， 表示有 n 个数据元素。 
接下来 1 行中是 n 个待排序的非负整数。
  
  结果输出：
将计算出的最少交换次数依次输出到文件 output.txt。
源程序如下：
1、 交换排序.cpp*/ 
// 交换排序问题.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include "输入输出.h"
typedef int Item;
#define SIZE 50
#define less(A,B) (A<B)
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {Item t=A;A=B;B=t;}
#define compswap(A,B) {if(less(B,A)) swap(A,B);}
int a[SIZE];
int Mini(int A[], int len,int k) //查找待排序列中的最小元素
{ 	
	int i,m=k;
	for(i=k;i<len;i++)
	{ 
		if(less(a[i],a[m])) m=i;
	}
	return m;
}

int change_sort(int A[],int n) //通过交换排序将最小元素换到最前
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

