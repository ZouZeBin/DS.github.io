#include<iostream>
using namespace std;
class Expt{
	public:
		Expt(){}
		~Expt(){}
		void show(){
			cout<<"����show()��Ա����"<<endl;
		}
};
class Demo{
	int n;
	public:
		Demo(){
			cout<<"����Demo����1"<<endl;
		}
		Demo(int m){
			n=m;
			cout<<"����Demo����2"<<endl;
		}
		~Demo(){
			cout<<"����Demo����"<<endl;
		} 
};
void f(){
	Demo d1;
	Demo d2(10);
	cout<<"��f()��������Expt���쳣"<<endl;
	throw Expt();
}
int main(){
	cout<<"��ʼִ��main()������"<<endl;
	try{
		cout<<"��try���е���f()"<<endl;
		f();
	}
	catch(Expt e){
		cout<<"�����쳣"<<endl;
		e.show();
	}
	catch(char *str){
		cout<<"���������쳣"<<str<<endl;
	}
		cout<<"main()ִ�����"<<endl;
	return 0;
}
