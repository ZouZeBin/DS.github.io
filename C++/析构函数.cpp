#include<iostream>
using namespace std;
class A{
	public:
		A(){}
		~A(){
			cout<<"����һ��A����������"<<endl;
		} 	
};
class B{
	public:
		B(){}
		~B(){
			cout<<"����һ��B����������"<<endl;
		} 	
};
int main(){
	A a[3]; 
	B b[5];
	B *p[2]; 
	return 0;
} 
