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
	a.disp();//输出m=2;
	int A::*p;//定义A数据成员指针
	p=&A::m;//指向数据成员m
	a.*p=5;
	a.disp(); 
	 
	return 0;
} 
