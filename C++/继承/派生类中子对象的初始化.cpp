#include<iostream>
using namespace std;
/*������Ĺ��캯���ĳ�Ա��ʼ���б����԰������������Ӷ���ĳ�ʼ����
���ǲ��ܰ����������ĳ�ʼ�������߿��ɻ��๹�캯�����г�ʼ��*/

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
	X x;//�Ӷ��� 
	public:
		A(int i,int j):x(i),n(j){}
		void dispA(){
		//	dispX();���� 
			cout<<"n="<<n<<endl;
		} 
}; 

class B:public A{
	int m;
	Y y;//�Ӷ���y
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




