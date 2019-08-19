#include<iostream>
using namespace std;
//静态联编是联编工作出现在编译连接阶段，又称早期联编，程序开始运行之前完成
//在编译时就解决了程序中的操作调用与执行该操作代码之间的关系
class Point{
	int x,y;
	public:
		Point(int x1,int y1){
			x=x1;
			y=y1;
		}
		int area() const{
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
		int area()const{
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
