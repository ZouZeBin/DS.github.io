#include<iostream>
using namespace std;
class A{
	const int n;//常数据成员
	public:
		A(int i,int j):n(i+j){}//构造函数初始化列表
		void print(){
			cout<<"n="<<n<<endl;
		} 
};
int main(){
	A a(10,11);
	a.print();
	return 0;
} 
