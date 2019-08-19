#include<iostream> 
using namespace std;
//当派生类的虚函数与基类对应的虚函数参数不同时，派生类的虚函数将丢失特性，变为重载函数
// 
class A{
	public:
		virtual void fun(int i){
			cout<<"调用虚函数:"<<i<<endl;
		}
};

class B:public A{
	public :
		void fun(double i){
			cout<<"派生类函数:"<<i;
		}
};
int main(){
	A a,*p=&a;
	B b;
	(*p).fun(1);
	p=&b;
	(*p).fun(2.5);//调用的仍是A的虚函数 
	return 0;
} 
