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
	a.disp();//���2
	void (A::*p)(int);//�����Ա����ָ��
	p=A::f1;
	(a.*p)(10);//�ȼ���a.f1(10)
	a.disp(); //���12 
	return 0;
} 
