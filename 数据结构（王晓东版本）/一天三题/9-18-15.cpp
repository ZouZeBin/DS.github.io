/*15算法实验题 6.2 DNA 排序问题
  问题描述：
对于给定的全序集中排序元素序列 A={a1， a2， ……， an}， 
A 的逆序数刻画出序列的已排序程度。 
逆序数越小， 序列 A 的已排序程度越高。
生物信息学家在进行分子计算研究 DNA 序列时， 需要将若干长度相同的 DNA 串按其逆序数从小到大排序。 
DNA 排序问题就是要对给定的长度相同的 DNA 串按逆序数排序。

  实验任务：
对于给定的长度相同的 DNA 串， 按其逆序数从小到大排序。
  
  数据输入：
由文件 input.txt 给出输入数据。 
输入数据包含若干数据块。 
每个数据块的第 1 行有 2 个正整数 L 和 n， 分别表示数据块中 DNA 串的长度和个数。 
接下来 n 行中， 每行是 1 个由大写英文字母 A、 C、 G、 T 组成的长度为 L 的 DNA 串。 
文件最后以 2 个 0 结束。
  
  结果输出：
将各数据块中的 DNA 串按逆序数排序输出到文件 output.txt 中。 
每个数据块之间用一个空行分隔。
源程序如下：
1、 DNA 排序.cpp*/ 
// DNA 排序.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#define SIZE 50
char a[SIZE+1][SIZE+1];
typedef struct {
	int seq;
	int inv;
}pair;

pair t[SIZE+1];
int main()
{ 
	int len, N, i, j, k, p,cnt;
	pair temp;
	t[0].seq = 0;
	t[0].inv = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &len,&N);
	printf("%d,%d\n",len,N);
	for (i=1; i<=N; i++)
	{ 
		scanf("%s",a[i]);
		cnt = 0;
		for (j=len-1; j>=1; j--)
		{ 
			for (k=0; k<j; k++)
			{
				if (a[i][k]>a[i][j]) cnt++;
			}//查找字符串的逆序数个数
		}
		temp.seq = i;
		temp.inv = cnt;
		for (k=i-1;k>=0 && t[k].inv>temp.inv; k--) t[k+1] = t[k];
		t[k+1] = temp;
	}//按照逆序数个数将字符串排序
	for (p=1; p<=N; p++)
	printf("%s\n\n", a[t[p].seq]);
	freopen("output.txt", "w", stdout);
	for (p=1; p<=N; p++)
	printf("%s\n\n", a[t[p].seq]);
	return 0;
}

