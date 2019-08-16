#include<iostream>
using namespace std;
class A{
	int n;
	public:
		A(int i):n(i){}
		void set(A &a){
			n=a.n;
		} 
		void disp(){
			cout<<"n="<<n<<endl;
		}
};
int main(){
	A b(2),c(3);
	b.disp();
	c.disp();
	b.set(c);
	b.disp();
	return 0;
} 
