/*
	�㷨˼·
	1����ʼ��ans=1�������洢�ۼƵĽ��
	2���ж�b�Ƿ�Ϊ����(b�Ķ�����ĩβ�Ƿ�Ϊ1������������������ж�)
	3����aƽ������b����1λ������2��
	4��ֻҪb����0�ͷ��صڶ��� 
*/ 

#include<iostream>
using namespace std;
typedef long long LL;
LL binaryPow(LL a,LL b,LL m){
	LL ans=1;
	while(b>0){
		if(b&1){//�ж�b�Ƿ�Ϊ���� 
			ans=ans*a%m;//��ans�ۼ���a 
		} 
		a=a*a%m;//��aƽ��
		b>>=1;//b����һλ 
	}
	return ans; 
}
int main(){
	cout<<binaryPow(2,3,9);
	return 0;
}



