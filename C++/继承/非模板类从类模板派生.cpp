#include<iostream>
using namespace std;
template<class T>
class A{
	protected:
		T x;
	public:
		A<T>(T i):x(i){}
};
class B:public A<int>{
	int y;
	public:
		B(int i,int j):A<int>(i){
			y=j;
		}
		void disp(){
			cout<<"x="<<x<<",y="<<y<<endl;
		}
};
int main(){
	B obj(1,2);
	obj.disp();
	return 0;
} 
