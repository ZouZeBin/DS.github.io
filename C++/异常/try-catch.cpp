#include<iostream>
using namespace std;
//int f(int);
void f2(int); 
int main(){
//	try{
//		cout<<"4!="<<f(4)<<endl;
//		cout<<"-2!="<<f(-2)<<endl;
//		cout<<"5!="<<f(5)<<endl;//不执行该语句 
//	}
//	catch(int n){
//		cout<<"n="<<n<<"不能计算n!"<<endl;
//		cout<<"程序执行结束"<<endl;
//	}
	f2(0);
	f2(1);
	f2(2);
	return 0;
} 
//int f(int n){
//	if(n<=0){
//		throw n;
//	}
//	int s=1;
//	for(int i=1;i<=n;i++){
//		s*=i;
//	}
//	return s;
//}

void f2(int code){
	try{
		if(code==0) throw code;//引发int型异常 
		if(code==1) throw 'x' ;//引发字符类型异常
		if(code==2) throw 12.345;//引发double类型异常 
	}
	catch(int n){
		cout<<"捕获整数类型："<<n<<endl;
	} 
	catch(...){
		cout<<"默认捕获"<<endl; 
	}
	return ;
}
