#include<iostream>
using namespace std;
class A{
	public:
		int m;
		A(int i):m(i){}
		void disp(){
			cout<<"m="<<m<<endl;
		}
};
int main(){
	A a(2);
	a.disp();//���m=2;
	int A::*p;//����A���ݳ�Աָ��
	p=&A::m;//ָ�����ݳ�Աm
	a.*p=5;
	a.disp(); 
	 
	return 0;
} 
