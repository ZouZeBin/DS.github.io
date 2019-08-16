#include<iostream>
#include<cstring>
using namespace std;
class A{
	char *p;
	int size;
	public:
		A(){}//默认构造函数
		
		A(char a[],int n){//重载构造函数
			p=new char[n+1];//分配n+1个空间
			strcpy(p,a);//复制字符串
			size=n; 
		}
		
		~A(){//析构函数 
			delete [] p;
		}
		
		/*A Copy(A &c){ 报错！！！！！*/  
		A&Copy(A &c){//复制 由于没有采用引用，达不到希望效果，将返回类型
					//改成Copy成员函数的引用，a1和返回共享同一内存空间 
			this->p=new char[c.size+1];
			strcpy(this->p,c.p);
			this->size=c.size;
			return *this; //返回当前对象，即修改后的对象代替原对象 
			//return c;
		} 
		
		void disp(){//输出p 
			cout<<p<<endl;
		} 
		
};
int main(){
	A a("ZZB",3),a1;
	cout<<"a:";
	a.disp();
	a1.Copy(a);
	cout<<"a1:";
	a1.disp();
	return 0;
} 
