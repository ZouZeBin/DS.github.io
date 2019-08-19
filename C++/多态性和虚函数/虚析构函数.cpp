#include<iostream>
using namespace std;
/*
	基类的虚构函数声明为虚函数时，调用fun(a)函数，执行delete a;语句采用动态联编，调用它的基类的析构函数
	当不说明基类的析构函数为虚函数时，也就是不调用他的基类的虚构函数 
*/
class A{
	public:
		virtual ~A(){
			cout<<"调用A的虚析构函数"<<endl;
		}
};
class B:public A{
	char * buf;
	public:
		B(int i){
			buf=new char[i];
		}
		virtual ~B(){
			cout<<"调用B的虚析构函数"<<endl; 
		}
};

void fun(A *a){
	delete a;
}
int main(){
	A *a=new B(10);
	fun(a);
	return 0;
}
