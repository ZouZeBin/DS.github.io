/*2算法实验题 1.2 连续整数和问题
 	问题描述：
	大部分的正整数可以表示为两个以上连续整数之和。
 
 	实验任务：
	连续整数和问题要求计算给定的正整数可以表述为多少个两个以上的连续整数之和。

	数据输入：
	由文件 input.txt 给出输入数据。 第一行有一个正整数。
	
	结果输出：
	将计算出的相应的连续整数分解数输出到文件 output.txt。
	实验源代码：
	1、 连续整数和.cpp
 	连续整数和.cpp : Defines the entry point for the console application.*/ 

//	#include "stdafx.h"
//	#include "输入输出.h"
	#include <stdio.h>
	int a[SIZE];
	int main()
	{ 
		int length=load(a);
		int i,count;
		for(i=0;i<length;i++)
		{ 
			count=0;
			printf("\n\n%d=\n", a[i]);
			for(int n1=1; n1<=a[i]/2; n1++)// n1 为等差数列第一项
			{ 
				for(int n2=n1+1; n2<a[i]; n2++)// n2 为等差数列最后一项
				{ 
					if((n1+n2)*(n2-n1+1) == a[i]*2)// 用等差数列公式算和
					{ //如果相等就输出结果
						for(int t=n1; t<n2; t++) printf("%d+", t);
						printf("%d\n", t);
						count++;
					}
				}
			}
			printf("共有%d 种分解方式\n", count);
			save(count);
		}
	}

