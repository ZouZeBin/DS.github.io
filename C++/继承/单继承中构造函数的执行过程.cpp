#include<iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<"����A()���캯��"<<endl;
		}
};
class B:public A{
	public:
		B(){
			cout<<"����B()���캯��"<<endl;
		}
};
int main(){
	B b; 
	return 0;
} 
/*�ȵ���A�������B*/ 
