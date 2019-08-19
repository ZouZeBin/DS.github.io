#include<iostream>
using namespace std;
class Expt{
	public:
		Expt(){}
		~Expt(){}
		void show(){
			cout<<"调用show()成员函数"<<endl;
		}
};
class Demo{
	int n;
	public:
		Demo(){
			cout<<"构造Demo对象1"<<endl;
		}
		Demo(int m){
			n=m;
			cout<<"构造Demo对象2"<<endl;
		}
		~Demo(){
			cout<<"析构Demo对象"<<endl;
		} 
};
void f(){
	Demo d1;
	Demo d2(10);
	cout<<"在f()函数抛掷Expt类异常"<<endl;
	throw Expt();
}
int main(){
	cout<<"开始执行main()主函数"<<endl;
	try{
		cout<<"在try块中调用f()"<<endl;
		f();
	}
	catch(Expt e){
		cout<<"捕获异常"<<endl;
		e.show();
	}
	catch(char *str){
		cout<<"捕获其他异常"<<str<<endl;
	}
		cout<<"main()执行完毕"<<endl;
	return 0;
}
