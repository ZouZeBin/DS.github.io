#include<iostream>
using namespace std;
typedef long long LL;
//��a^b%m�ĵݹ���
LL binaryPow(LL a,LL b,LL m){
	if(b==0){
		return 1;//a^0%m=1
	}
	if(b%2==1)//bΪ���� 
		return a*binaryPow(a,b-1,m)%m;
	else{//bΪż��,ת��Ϊb/2 
		LL mul=binaryPow(a,b/2,m);
		return mul*mul%m;
	} 
} 
int main(){
	cout<<binaryPow(2,3,9);
	return 0;
}
