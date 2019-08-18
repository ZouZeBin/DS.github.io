#include<iostream>
using namespace std;
template <class T>//模板函数的说明定义必须是全局作用域  
T min1(T x,T y){
	if(x<y)
		return x;
	return y; 
} 
int main(){
	int n1=2,n2=10;
	double a1=2.4,a2=4.3;
	cout<<"较小整数(2和10):"<<min1(n1,n2)<<endl;//用min会报错，被当成调用库里的min函数 
	cout<<"较小小数(2.4和4.3):"<<min1(a1,a2)<<endl; 
	/* 
	cout<<min1(n1,a2); //模板类型不具有隐式类型转换,各个参数应该保持一致的类型
				//该项报错 
	*/ 
	return 0;
}
