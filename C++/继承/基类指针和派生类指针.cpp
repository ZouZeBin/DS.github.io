#include<iostream>
using namespace std;
class A{
	int a;
	public:
		void setA(int x){
			a=x; 
		}
		void dispA(){
			cout<<"a="<<a<<endl;
		}
};

class B:public A{
	int b;
	public:
		void setB(int y){
			b=y;
		}
		void dispB(){
			cout<<"b="<<b<<endl;
		}
};
int main(){
	//ֱ���û���ָ�����û���Ķ��� 
	A *pa=new A();
	pa->setA(1);
	pa->dispA();
	//ֱ����������ָ���������������
	B *pb=new B();
	pb->setB(2);
	pb->dispB();
	//�û���ָ������һ��������Ķ���
	A *pc=new B();
	pc->setA(3);
	pc->dispA();
	//��������ָ�����û�����󣨱���ǿ��ת���� 
	B *pd=new B();
	A objA;
	objA.setA(4);
	pd=(B*)&objA;
	pd->dispA();
	//ִ��pd->dispB();ʱ��ʾ������ 
	return 0;
} 
