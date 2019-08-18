#include<iostream>
using namespace std;
template<class T>
class Sample{
	T t;
	public:
		Sample(T i):t(i){}
		Sample(){}
		void disp(){
			cout<<"t="<<t<<endl;
		}
		friend Sample<T> operator+(Sample<T> s1,Sample<T> s2){
			Sample<T> tmp;
			tmp.t=s1.t+s2.t;
			return tmp;
		}
};
int main(){
	Sample<int> s1(2),s2(4),s3;
	Sample<double> s4(5.9),s5(6.66),s6;
	s3=s2+s1;
	s6=s4+s5; 
	s3.disp();
	s6.disp();
	return 0;
}
