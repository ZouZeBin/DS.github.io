/*
	算法思路
	1、初始令ans=1，用来存储累计的结果
	2、判断b是否为奇数(b的二进制末尾是否为1，对其求与运算进行判断)
	3、令a平方，将b右移1位（除以2）
	4、只要b大于0就返回第二部 
*/ 

#include<iostream>
using namespace std;
typedef long long LL;
LL binaryPow(LL a,LL b,LL m){
	LL ans=1;
	while(b>0){
		if(b&1){//判断b是否为奇数 
			ans=ans*a%m;//令ans累计上a 
		} 
		a=a*a%m;//令a平方
		b>>=1;//b右移一位 
	}
	return ans; 
}
int main(){
	cout<<binaryPow(2,3,9);
	return 0;
}



