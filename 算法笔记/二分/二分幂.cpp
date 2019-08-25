#include<iostream>
using namespace std;
typedef long long LL;
//求a^b%m的递归求法
LL binaryPow(LL a,LL b,LL m){
	if(b==0){
		return 1;//a^0%m=1
	}
	if(b%2==1)//b为奇数 
		return a*binaryPow(a,b-1,m)%m;
	else{//b为偶数,转化为b/2 
		LL mul=binaryPow(a,b/2,m);
		return mul*mul%m;
	} 
} 
int main(){
	cout<<binaryPow(2,3,9);
	return 0;
}
