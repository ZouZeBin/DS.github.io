#include<iostream>
using namespace std;
//�������A 
class A{
	int a;
	public:
		A(int i){
			a=i;
			cout<<"����A()���캯��"<<endl;
		}
		void disp(){
			cout<<"a="<<a<<endl;
		}
};
//�������B 
class B{
	int b;
	public:
		B(int j){
			b=j;
			cout<<"����B()���캯��"<<endl;
		}
		void disp(){
			cout<<"b="<<b<<endl;
		}
};
//����A��B����������C 
class C:public B,public A{
	int c;
	public:
		C(int k):A(k-2),B(k+2){//���������ʼ���б� 
			c=k;
			cout<<"����C�Ĺ��캯��"<<endl; 
		} 
		void disp(){
			A::disp();//::Ϊ�����������	
			B::disp();
			cout<<"c="<<c<<endl; 
		}
};
int main(){
	C obj(10);
	obj.disp();
	return 0;
} 
