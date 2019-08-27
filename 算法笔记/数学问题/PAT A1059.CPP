/*
	给出一个int范围整数，按照从小到大顺序输出其分解为质因数的乘法算式
	思路：
		1、打印素数表
		2、进行质因子分解操作 
*/ 


#include<cstdio>
#include<cmath>
const int maxn=100010; 
//判断n是否为素数
bool isPrime(int n){
	if(n<=1)
		return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
//求素数表
int prime[maxn],pNum=0;
void findPrime(){
	for(int i=1;i<maxn;i++){
		if(isPrime(i)==true){
			prime[pNum++]=i;
		}
	}
} 
//结构体
struct factor{
	int x,cnt;//x:质因数 cnt:个数 
}fac[10];

//主函数
int main(){
	findPrime();
	int n,num=0;//num为不同质因数的个数
	scanf("%d",&n);
	//判1	
	if(n==1)
		printf("1=1"); 
	else{
		printf("%d=",n);
		int sqr=(int)sqrt(1.0*n);//n的根号
		//枚举根号n以内的质因子
		 for(int i=0;i<pNum&&prime[i]<=sqr;i++){
		 	//如果是质因子，记录
			 if(n%prime[i]==0){
			 	fac[num].x=prime[i];
			 	fac[num].cnt=0;
			 	//计算出质因子的个数
				 while(n%prime[i]==0){
				 	fac[num].cnt++;
				 	n/=prime[i];
				 } 
				 num++;//不同质因子个数+1 
			 } 
			 if(n==1) break;//退出循环 
		 }
		 //如果无法被根号n以内质因子除尽 
		 if(n!=1){
		 	//一定有大于根号n的质因子
			 fac[num].x=n;
			 fac[num++].cnt=1; 
		 } 
		//按格式输出结果 
		for(int i=0;i<num;i++){
			if(i>0)
				printf("*");
				printf("%d",fac[i].x);
				if(fac[i].cnt>1){
					printf("^%d",fac[i].cnt);
				}
		}
	}
	return 0;
} 
 
