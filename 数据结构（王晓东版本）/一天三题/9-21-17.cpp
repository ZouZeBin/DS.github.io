/*17算法实验题 6.4 最优服务次序问题
	 问题描述：
 设有 n 个顾客同时等待一项服务。 
 顾客 i 需要的服务时间为 t， 1<i<n。 
 应如何安排 n 个顾客的服务次序， 才能使平均等待时间达到最小？ 
 平均等待时间是 n 个顾客等待服务时间的总和除以 n。
	
	实验任务：
 对于给定的 n 个顾客需要的服务时间， 计算最优服务次序。

	数据输入：
 由文件 input.txt 给出输入数据。 第 1 行是正整数 n， 表示有 n 个顾客。 
 接下来 1 行中，有 n 个正整数， 表示 n 个顾客需要的服务时间。
	
	结果输出：
将计算出的最小平均等待时间输出到文件 output.txt 中。
（采用短作业优先原则， 试用任一种排序算法将顾客按服务时间从小到大排序。）
源程序如下：
1、 最优服务次序问题.cpp*/ 
//使用选择排序
#include<stdio.h>
typedef int Item;
#define MaxSize 50
#define less(A,B) (A<B)
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {Item t=A;A=B;B=t;}
#define compswap(A,B) {if(less(B,A)) swap(A,B);}
int T[MaxSize+1];
int mini(Item a[],int i,int r)
{ 
	int j,min=i;
	for(j=i+1;j<=r;j++)
	if(less(a[j],a[min])) min=j;
	return min;
}

void selection(Item a[],int l)//选择排序
{ 
	int i,j;
	for(i=0;i<l;i++)
	{
		j=mini(a,i,l);
		swap(a[i],a[j]);
	}
}

void main()
{ 
	int i,N;
	double WTime=0,STime=0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	printf("\n%d 个顾客分别需要的服务时间为： \n",N);
	for (i=1; i<=N; i++) scanf("%d",&T[i]);
	for (i=1; i<=N; i++)
		printf("%d,",T[i]);
	selection(T,N);
	printf("\n\n 按照短作业优先原则排序之后时间序列为： \n");
	
	for (i=1; i<=N; i++) printf("%d,",T[i]);
	for (i=1; i<=N; i++) STime+=T[i];
	for(i=1; i<N; i++) T[i+1]+=T[i];
	for(i=1; i<N; i++) WTime+=T[i];
	STime+=WTime;
	WTime/=N;
	STime/=N;
	printf("\n\n 最优平均需要服务时间为： %f\n",STime);
	printf("\n 最小平均等待时间为： %f\n",WTime);
	freopen("output.txt", "w", stdout);
	printf("%f %f",STime,WTime);
}

