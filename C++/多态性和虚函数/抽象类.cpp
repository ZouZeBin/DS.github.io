#include<iostream>
using namespace std;
//������ļ���涨
/*
	1��������ֻ������������Ļ��࣬���ܽ������������
	2�������಻�������������͡������������ͻ�����ʽת��������
	3������˵��ָ��������ָ������ã���ָ�����ָ�����������࣬����ʵ�ֶ�̬��  
*/ 
/*
	����һ��������Shapes����������������square��circle����main()
	�ж����˳������ָ������ptr[2],��������ֱ���s1,c1���󡣴Ӷ�
	��������������в��� 
*/ 

const double PI=3.14159;
//������ 
class Shapes{
	protected:
		int x,y;
	public:
		void setValue(int d,int w){
			x=d;
			y=w;
		} 
		void setValue(int d){
			x=d;
		}
		virtual void disp()=0;//���麯�� 
}; 
class square:public Shapes{
	public:
		void disp(){
			cout<<"���������"<<x*y<<endl; 
		}
}; 

class circle:public Shapes{
	public:
		void disp(){
			cout<<"Բ�������"<<PI*x*x<<endl;
		}
};

int main(){
	Shapes *ptr[2];
	square s1;
	circle c1;
	ptr[0]=&s1;
	ptr[0]->setValue(10,3);
	ptr[0]->disp();
	ptr[1]=&c1;
	ptr[1]->setValue(10);
	ptr[1]->disp(); 
	return 0;
}

