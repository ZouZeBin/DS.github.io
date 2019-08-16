#include<iostream>
using namespace std;
class A{
	public:
		A(){}
		~A(){
			cout<<"调用一次A的析构函数"<<endl;
		} 	
};
class B{
	public:
		B(){}
		~B(){
			cout<<"调用一次B的析构函数"<<endl;
		} 	
};
int main(){
	A a[3]; 
	B b[5];
	B *p[2]; 
	return 0;
} 
