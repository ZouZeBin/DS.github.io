#include<iostream>
using namespace std;
class A{
	int n;
	public:
		A(int i):n(i){}
		void f1(int j){
			n+=j;
		}
		void disp(){
			cout<<"n="<<n<<endl;	
		}
};
int main(){
	A a(2);
	a.disp();//输出2
	void (A::*p)(int);//定义成员函数指针
	p=A::f1;
	(a.*p)(10);//等价于a.f1(10)
	a.disp(); //输出12 
	return 0;
} 
