#include<iostream>
using namespace std;
template <class T>
class A{
	public:
		void dispA(T obj){
			cout<<obj<<endl;
		}
};

template <class T1,class T2>
class B:public A<T2>{
	public:
		void dispB(T1 obj1,T2 obj2){
			cout<<obj1<<" "<<obj2<<endl;
		}
}; 
int main(){
	B<char *,double> obj1;
	obj1.dispA(12.34);
	obj1.dispB("hello:",12);
	B<int ,int > obj2;
	obj2.dispB(12,341);
	
	return 0;
} 
