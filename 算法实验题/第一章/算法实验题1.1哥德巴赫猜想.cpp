/*
问题描述：
哥德巴赫猜想： 任何一个大于 2 的偶数均可表示为两个素数之和。
 实验任务：
验证哥德巴赫猜想。 计算给定的大偶数可以表示为多少对素数之和。
 数据输入：
由文件 input.txt 给出输入数据。 每行有一个大偶数， 文件一数字 0 结尾。
 结果输出：
将计算出的相应素数分解数输出到文件 output.txt
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<stdlib.h>
#define PRIME_COUNT 50
#define SIZE 10
using namespace std;
int a[SIZE];
int *load(){
 	FILE *fp;
	int i;
	fp=fopen("input.txt","r");
	for(i=0;i<SIZE;i++) 
		fscanf(fp,"%d",&a[i]);
//	printf("%d,",a[i]);
	fclose(fp);
	return a;
}

void save(int m,int n){ 
	FILE *fp;
	int i;
	if((fp=fopen("output.txt","w"))==NULL) {
		printf("cannot open file.\n"); return;
	}
	fprintf(fp,"%d,%d\n",m,n);
	fclose(fp);
}

int isPrime(int t){//判断t是否为素数
	
	int i,k=sqrt(t); //sqrt对函数重载的定义不明确
					//改为float进行重载，强制转化为int
	for(i=2;i<=k;i++){
		if(t%i==0)
			break;
	}
	if(i>=k+1)
		return t;
	else return -1;
} 

int *getPrimes(int max){//取得N/2以下的素数列表 
	static int primes[PRIME_COUNT];
	int i,j,m;
	primes[1]=2;
	for(j=2,i=3;i<=max/2;i++){
		m=isPrime(i);
		if(m>0)
			primes[j++]=m;
	} 
	for(i=1;i<j;i++){
		printf("%d",primes[i]);//输出素数 
	}
	printf("\n");
	return primes; 
}

//考察复合要求的素数对 
int outEven(int primes[],int n){
	int p,q,count;
	for(int i=1;!(p=primes[i]);i++){
		count=0;
		if((q=isPrime(n-p))>0){
			printf("%d,%d\n",p,q);
			count++;
		}
	}
	return count;//返回复合素数对个数 
}
int main(){
	int *n,*primes;
//	scanf("%d",&n);
//	primes=getPrimes(n);
//	outEven(primes,n);
	n=load();
	for(int i=0;i<SIZE;i++){
		printf("输入大偶数为:");
		printf("%d\n",n[i]);
		printf("待查找的素数表列为");
		primes= getPrimes(n[i]);
		printf("该偶数可以分解为%d 对素数之和.",
				outEven(primes,n[i]));
		printf("\n\n");
	}
	return 0;
}
















