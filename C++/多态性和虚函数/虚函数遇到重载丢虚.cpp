#include<iostream> 
using namespace std;
//����������麯��������Ӧ���麯��������ͬʱ����������麯������ʧ���ԣ���Ϊ���غ���
// 
class A{
	public:
		virtual void fun(int i){
			cout<<"�����麯��:"<<i<<endl;
		}
};

class B:public A{
	public :
		void fun(double i){
			cout<<"�����ຯ��:"<<i;
		}
};
int main(){
	A a,*p=&a;
	B b;
	(*p).fun(1);
	p=&b;
	(*p).fun(2.5);//���õ�����A���麯�� 
	return 0;
} 
