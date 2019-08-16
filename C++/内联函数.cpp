#include<iostream>
using namespace std;
void fun();//函数的声明 

inline int add(int i,int j){
	return i+j;
}
class A{
	//int a=2;不能在定义类时直接赋值 
};
int main(){
//	int sum=add(1,2);
	fun();	
	return 0;
}
void fun(){
	cout<<add(1,2)<<endl;
} 
