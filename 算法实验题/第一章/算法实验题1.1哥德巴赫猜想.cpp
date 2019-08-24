/*
����������
��°ͺղ��룺 �κ�һ������ 2 ��ż�����ɱ�ʾΪ��������֮�͡�
 ʵ������
��֤��°ͺղ��롣 ��������Ĵ�ż�����Ա�ʾΪ���ٶ�����֮�͡�
 �������룺
���ļ� input.txt �����������ݡ� ÿ����һ����ż���� �ļ�һ���� 0 ��β��
 ��������
�����������Ӧ�����ֽ���������ļ� output.txt
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

int isPrime(int t){//�ж�t�Ƿ�Ϊ����
	
	int i,k=sqrt(t); //sqrt�Ժ������صĶ��岻��ȷ
					//��Ϊfloat�������أ�ǿ��ת��Ϊint
	for(i=2;i<=k;i++){
		if(t%i==0)
			break;
	}
	if(i>=k+1)
		return t;
	else return -1;
} 

int *getPrimes(int max){//ȡ��N/2���µ������б� 
	static int primes[PRIME_COUNT];
	int i,j,m;
	primes[1]=2;
	for(j=2,i=3;i<=max/2;i++){
		m=isPrime(i);
		if(m>0)
			primes[j++]=m;
	} 
	for(i=1;i<j;i++){
		printf("%d",primes[i]);//������� 
	}
	printf("\n");
	return primes; 
}

//���츴��Ҫ��������� 
int outEven(int primes[],int n){
	int p,q,count;
	for(int i=1;!(p=primes[i]);i++){
		count=0;
		if((q=isPrime(n-p))>0){
			printf("%d,%d\n",p,q);
			count++;
		}
	}
	return count;//���ظ��������Ը��� 
}
int main(){
	int *n,*primes;
//	scanf("%d",&n);
//	primes=getPrimes(n);
//	outEven(primes,n);
	n=load();
	for(int i=0;i<SIZE;i++){
		printf("�����ż��Ϊ:");
		printf("%d\n",n[i]);
		printf("�����ҵ���������Ϊ");
		primes= getPrimes(n[i]);
		printf("��ż�����Էֽ�Ϊ%d ������֮��.",
				outEven(primes,n[i]));
		printf("\n\n");
	}
	return 0;
}
















