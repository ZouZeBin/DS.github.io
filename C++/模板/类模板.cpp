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
	Sample<int> obj1(10);//ģ����Sample<class T>ʵ���� 
	Sample<char *> obj2("China!");
	obj1.disp(); 
	obj2.disp(); 
	return 0;
} 
