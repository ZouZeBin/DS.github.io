#include<iostream>
using namespace std;
//抽象类的几点规定
/*
	1、抽象类只能用作其他类的基类，不能建立抽象类对象
	2、抽象类不能用作参数类型、函数返回类型或者显式转换的类型
	3、可以说明指向抽象类的指针和引用，此指针可以指向它的派生类，进而实现多态性  
*/ 
/*
	定义一个抽象类Shapes和他的两个派生类square和circle，在main()
	中定义了抽象类的指针数组ptr[2],并给数组分别赋予s1,c1对象。从而
	对这两个对象进行操作 
*/ 

const double PI=3.14159;
//抽象类 
class Shapes{
	protected:
		int x,y;
	public:
		void setValue(int d,int w){
			x=d;
			y=w;
		} 
		void setValue(int d){
			x=d;
		}
		virtual void disp()=0;//纯虚函数 
}; 
class square:public Shapes{
	public:
		void disp(){
			cout<<"矩形面积："<<x*y<<endl; 
		}
}; 

class circle:public Shapes{
	public:
		void disp(){
			cout<<"圆形面积："<<PI*x*x<<endl;
		}
};

int main(){
	Shapes *ptr[2];
	square s1;
	circle c1;
	ptr[0]=&s1;
	ptr[0]->setValue(10,3);
	ptr[0]->disp();
	ptr[1]=&c1;
	ptr[1]->setValue(10);
	ptr[1]->disp(); 
	return 0;
}

