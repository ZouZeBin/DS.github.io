#include<iostream>
using namespace std;
/*
ԭ��
	�����Ĺ��캯���ڷ������֮ǰ����
	��ͬһ��ΰ����������࣬��Щ�����Ĺ��캯���������ǵ�˵��˳�����
	��������ɷ��������������������Ȼ��ѭ�ȵ��û��๹�캯�����ٵ���������Ĺ��캯����ִ��˳�� 
*/
class base1{
	public:
		base1(){
			cout<<"base1"<<endl; 
		}
}; 
class base2{
	public:
		base2(){
			cout<<"base2"<<endl;
		}
};
class level1:public base2,virtual public base1{
	public:
		level1(){
			cout<<"level1"<<endl; 
		}
};
class level2:public base2,virtual public base1{
	public:
		level2(){
			cout<<"level2"<<endl; 
		}
};
class toplevel:public level1,virtual public level2{
	public:
		toplevel(){
			cout<<"toplevel"<<endl;
		}
};
int main(){
	toplevel t;
	return 0;
} 
