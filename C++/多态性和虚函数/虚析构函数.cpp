#include<iostream>
using namespace std;
/*
	������鹹��������Ϊ�麯��ʱ������fun(a)������ִ��delete a;�����ö�̬���࣬�������Ļ������������
	����˵���������������Ϊ�麯��ʱ��Ҳ���ǲ��������Ļ�����鹹���� 
*/
class A{
	public:
		virtual ~A(){
			cout<<"����A������������"<<endl;
		}
};
class B:public A{
	char * buf;
	public:
		B(int i){
			buf=new char[i];
		}
		virtual ~B(){
			cout<<"����B������������"<<endl; 
		}
};

void fun(A *a){
	delete a;
}
int main(){
	A *a=new B(10);
	fun(a);
	return 0;
}
