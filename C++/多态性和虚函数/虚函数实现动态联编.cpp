#include<iostream>
using namespace std;
//动态联编的三个条件
/*
	1、类之间为基类与派生类的关系
	2、要有虚函数
	3、调用虚函数操作的是指向对象的指针或者对象引用，或者由成员函数调用虚函数 
*/ 
class Point{
	int x,y;
	public:
		Point(int x1,int y1){
			x=x1;
			y=y1;
		}
		virtual int area() const{
			return 0;
		}
}; 

class Rect:public Point{
	int l,w;
	public:
		Rect(int x1,int y1,int l1,int w1):Point(x1,y1){
			l=l1;
			w=w1;
		}
		virtual int area()const{
			return l*w;
		}
};

void fun(Point &p){
	cout<<p.area()<<endl;
}

int main(){
	Rect rec(2,4,10,6);
	fun(rec);
	return 0;
}
