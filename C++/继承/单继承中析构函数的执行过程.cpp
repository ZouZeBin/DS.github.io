#include<iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<"调用A()构造函数"<<endl;
		}
		~A(){
			cout<<"调用A()析构函数"<<endl; 
		}
};
class B:public A{
	public:
		B(){
			cout<<"调用B()构造函数"<<endl; 
		}	
		~B(){
			cout<<"调用B()析构函数"<<endl;
		}
};

int main(){
	B b;
	return 0;
}
