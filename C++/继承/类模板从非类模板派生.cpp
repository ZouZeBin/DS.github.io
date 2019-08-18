#include<iostream>
using namespace std;
class A{
	int x;
	public:
		A(int i):x(i){}
		int getX(){
			return x;
		}
		void disp(){
			cout<<x<<endl;
		}
};

template <class T>
class B:public A{
	T y;
	public:
		B(T a,int j):A(j){
			y=a;
		}
		T getY(){
			return y;
		}
		void disp(){
			cout<<y<<" "<<getX()<<endl;
		}
};
int main(){
	A obj(123);
	obj.disp();
	B<int> obj1(1,2);
	B<double> obj2(1.3,5);
	B<char *> obj3("haha",2);
	obj1.disp();
	obj2.disp();
	obj3.disp();
	return 0;
} 
