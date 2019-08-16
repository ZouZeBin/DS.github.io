#include<iostream>
using namespace std;
int n=1;
int &fun(int m){
	//int n=1;放在这局部变量，函数返回时自动释放，会报错 
	n+=m;
	return n;
}
int main(){
	fun(10)+=20;
	cout<<"n="<<n<<endl; //fun返回全局变量的引用 
	return 0;
} 
