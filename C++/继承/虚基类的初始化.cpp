#include<iostream>
using namespace std;
/*
原则：
	虚基类的构造函数在非虚基类之前调用
	若同一层次包含多个虚基类，这些虚基类的构造函数按照他们的说明顺序调用
	若虚基类由非虚基类派生而来，则仍然遵循先调用基类构造函数，再调用派生类的构造函数的执行顺序 
*/
class base1{
	public:
		base1(){
			cout<<"base1"<<endl; 
		}
}; 
class base2{
	public:
		base2(){
			cout<<"base2"<<endl;
		}
};
class level1:public base2,virtual public base1{
	public:
		level1(){
			cout<<"level1"<<endl; 
		}
};
class level2:public base2,virtual public base1{
	public:
		level2(){
			cout<<"level2"<<endl; 
		}
};
class toplevel:public level1,virtual public level2{
	public:
		toplevel(){
			cout<<"toplevel"<<endl;
		}
};
int main(){
	toplevel t;
	return 0;
} 
