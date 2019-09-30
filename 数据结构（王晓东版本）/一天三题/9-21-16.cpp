/*16算法实验题 6.3 输油管道问题
· 问题描述：
 某石油公司计划建造一条由东向西的主输油管道。 
 该管道要穿过一个有 n 口油井的油田。 
 从每口油井都要有一条输油管道沿最短路径（或南或北） 与主管道相连。 
 如果给定n口油井的位置， 即他们的 x 坐标（东西向） 和 y 坐标（南北向）， 
 应如何确定主管道的最优位置， 使各油井到主管道之间的输油管道长度总和最小？ 
 证明可在线性时间内确定主管道的最优位置。
 
· 实验任务：
 给定 n 口油井的位置， 计算各油井到主管道之间的输油管道最小长度总和。

· 数据输入：
 由文件 input.txt 给出输入数据。 
 文件的第 1 行是油井数 n（n<10000）， 接下来 n 行是油井的位置。 
 每行 2 个整数 x 和 y（-10000<x,y<10000）。
 
· 结果输出：
 将计算结果输出到文件 output.txt 中。 
 文件第一行中的数十油井到主管道之间的最小长度总和。
（程序转化为对 n 对和不等的数据按大小排序并求中位数 k 的问题）
源程序如下：
1、 输油管道.cpp*/ 
// 输油管道问题.cpp : Defines the entry point for the console application.
//TransportOil.cpp
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct Point
{ 
	double x;
	double y;
};

void Insert_Sort(Point *p, int left, int right)//插入排序 
{ 
	Point temp;
	for(int i=left+1; i<=right; i++)
	{ 
		temp=p[i];
		for(int j=i-1; j >=left; j--)
		{
			if(p[j].y > temp.y)
				p[j+1]=p[j];
			else break;
		}
		p[j+1] = temp;
	}	
}

//改进的快速排序
void Quick_Sort(Point *p, int left, int right)
{ 
	Point temp;
	int partition;
	int i=left, j=right;
	if((right - left) < 5)
	{ 
		Insert_Sort(p, left, right);
		return;
	}/**当数组中元素的个数小于 5 个的时候， 就调用插入排序来提高排序速度*/
	partition=(right-left)/2;
	while(i<j)
	{ 
		do{
			i++;
		}while(p[i].y < p[partition].y);
		do{
			j--;
		}while(p[j].y > p[partition].y);
		if(i<j)//将两个点进行交换
		{ 
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
	}
	Quick_Sort(p, left, j);
	Quick_Sort(p, j+1, right);
}

int main(int argc, char* argv[])
{
	int n, y, m, i=1;
	cout<<"请输入油井的个数: ";
	cin>>n;
	m=n;
	Point *p =new Point[n];
	while(n)
	{ 
		cin>>p[i].x>>p[i].y;
		n--;
		i++;
	} //对点 p[]的纵坐标进行排序
	Quick_Sort(p, 1, m);
	int sum = 0;
	for(i = 1; i <= m/2; i++)
	sum += fabs(p[m-i+1].y - p[i].y); //排序后找到中位数 k
	y = p[(m+1)/2].y;
	cout<<sum<<endl;	
	system("pause");
	return 0;
}

