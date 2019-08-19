#include<iostream>
using namespace std;
/*派生类的构造函数的成员初始化列表，可以包含派生类中子对象的初始化，
但是不能包含基类对象的初始化，后者可由基类构造函数进行初始化*/

class X{
	int a;
	public:
		X(int i){
			a=i;
		}
		void dispX(){
			cout<<"a="<<a<<endl;
		}
}; 
class Y{
	int b;
	public:
		Y(int j){
			b=j;
		}
		void dispY(){
			cout<<"b="<<b<<endl;
		}
};

class A{
	int n;
	X x;//子对象 
	public:
		A(int i,int j):x(i),n(j){}
		void dispA(){
		//	dispX();报错 
			cout<<"n="<<n<<endl;
		} 
}; 

class B:public A{
	int m;
	Y y;//子对象y
	public:
		B(int i,int j,int k,int l):A(i,j),y(k),m(l){}
		void dispB(){
			dispA();
			y.dispY();
			cout<<"m="<<m<<endl;
		} 
};
int main(){
	B s(1,2,3,4);
	s.dispB();
	return 0;
}




