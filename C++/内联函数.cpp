#include<iostream>
using namespace std;
void fun();//���������� 

inline int add(int i,int j){
	return i+j;
}
class A{
	//int a=2;�����ڶ�����ʱֱ�Ӹ�ֵ 
};
int main(){
//	int sum=add(1,2);
	fun();	
	return 0;
}
void fun(){
	cout<<add(1,2)<<endl;
} 
