#include<iostream>
using namespace std;
template <class T>
class Sample{
	T t;
	public :
		Sample(T i):t(i){}
		void disp(){
			cout<<"t="<<t<<endl;
		}
}; 
int main(){
	Sample<int> obj1(10);//模板类Sample<class T>实例化 
	Sample<char *> obj2("China!");
	obj1.disp(); 
	obj2.disp(); 
	return 0;
} 
