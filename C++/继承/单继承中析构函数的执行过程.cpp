#include<iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<"����A()���캯��"<<endl;
		}
		~A(){
			cout<<"����A()��������"<<endl; 
		}
};
class B:public A{
	public:
		B(){
			cout<<"����B()���캯��"<<endl; 
		}	
		~B(){
			cout<<"����B()��������"<<endl;
		}
};

int main(){
	B b;
	return 0;
}
