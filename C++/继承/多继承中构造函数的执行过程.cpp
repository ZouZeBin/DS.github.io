#include<iostream>
using namespace std;
//定义基类A 
class A{
	int a;
	public:
		A(int i){
			a=i;
			cout<<"调用A()构造函数"<<endl;
		}
		void disp(){
			cout<<"a="<<a<<endl;
		}
};
//定义基类B 
class B{
	int b;
	public:
		B(int j){
			b=j;
			cout<<"调用B()构造函数"<<endl;
		}
		void disp(){
			cout<<"b="<<b<<endl;
		}
};
//从类A，B公有派生类C 
class C:public B,public A{
	int c;
	public:
		C(int k):A(k-2),B(k+2){//包含基类初始化列表 
			c=k;
			cout<<"调用C的构造函数"<<endl; 
		} 
		void disp(){
			A::disp();//::为作用域运算符	
			B::disp();
			cout<<"c="<<c<<endl; 
		}
};
int main(){
	C obj(10);
	obj.disp();
	return 0;
} 
