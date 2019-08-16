#include<iostream>
using namespace std;
class A{
	int n;
	public:
		A(int i):n(i){}
		int getN() const{//没有const声明的成员函数不能用来操作常数据成员 
			return n;
		}
};

int add(const A &a1,const A &a2){
		int sum=a1.getN()+a2.getN();
		return sum;
}

int main(){
	A a1(100),a2(234);
	cout<<"sum="<<add(a1,a2); 
	return 0;
} 
