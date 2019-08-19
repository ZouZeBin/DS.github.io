#include<iostream>
using namespace std;
class A{
	public:
		A(int i){
			cout<<i;
		}
		~A(){}
}; 

class B:virtual public A{
	public:
		B(int i,int j=0):A(j){
			cout<<i;
			//cout<<"j="<<j;
		}
		~B(){}
};

class C:virtual public A{
	public:
		C(int i,int j=0):A(j){
			cout<<i;
		}
		~C(){}
};

class D:public C,public B{
	C obj2;
	B obj1;
	public:
		D(int a,int b,int c,int d):obj1(a),obj2(b),B(c),C(d),A(a){
			cout<<b;
		}
}; 
int main(){
	D d(1,2,3,4);
	int i;
	cin>>i; 
	return 0;
}





