#include<iostream>
using namespace std;
class A{
	protected:
		int a;
	public:
		A(){
			a=10;
		}
};
class B1:virtual public A{
	public:
		B1(){
			cout<<a<<endl;
		}
};
class B2:virtual public A{
	public:
		B2(){
			cout<<a<<endl;
		}
};
class C:B1,B2{
	public:
		C(){
			cout<<a<<endl;
		}
};
int main(){
	C c;
	return 0;
} 
