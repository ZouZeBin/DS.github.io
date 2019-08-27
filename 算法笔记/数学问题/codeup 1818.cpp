/*
题目描述
	输入两个正整数，求其最大公约数。

输入
	测试数据有多组，每组输入两个正整数。

输出
	对于每组输入,请输出其最大公约数。

样例输入
	49 14
样例输出
7

*/ 

#include<cstdio>
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
} 
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		printf("%d\n",gcd(m,n));
	}
}
