#include<iostream>
using namespace std;
int n=1;
int &fun(int m){
	//int n=1;������ֲ���������������ʱ�Զ��ͷţ��ᱨ�� 
	n+=m;
	return n;
}
int main(){
	fun(10)+=20;
	cout<<"n="<<n<<endl; //fun����ȫ�ֱ��������� 
	return 0;
} 
