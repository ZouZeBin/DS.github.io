#include<iostream>
using namespace std;
class A{
	int a;
	public:
		void setA(int x){
			a=x; 
		}
		void dispA(){
			cout<<"a="<<a<<endl;
		}
};

class B:public A{
	int b;
	public:
		void setB(int y){
			b=y;
		}
		void dispB(){
			cout<<"b="<<b<<endl;
		}
};
int main(){
	//直接用基类指针引用基类的对象 
	A *pa=new A();
	pa->setA(1);
	pa->dispA();
	//直接用派生类指针引用派生类对象
	B *pb=new B();
	pb->setB(2);
	pb->dispB();
	//用基类指针引用一个派生类的对象
	A *pc=new B();
	pc->setA(3);
	pc->dispA();
	//用派生类指针引用基类对象（必须强制转化） 
	B *pd=new B();
	A objA;
	objA.setA(4);
	pd=(B*)&objA;
	pd->dispA();
	//执行pd->dispB();时显示错误结果 
	return 0;
} 
