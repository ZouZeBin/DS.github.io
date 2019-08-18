#include<iostream>
using namespace std;
class coord{
	int x,y;
	public:
		coord(int x1,int y1):x(x1),y(y1){}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		int operator<(coord &c);
};

//定义"<"运算符重载函数 
int coord::operator<(coord &c){
	if(x<c.x)
		if(y<c.y)
			return 1;
	return 0; 
}

//函数模板说明定义 
template<class obj>

obj &min(obj &o1,obj &o2){
	if(o1<o2)//若函数被实例化为类对象，对"<"进行重载，否则使用标准"<"运算符 
		return o1;
	else 
		return o2;
} 
int main(){
	coord c1(5,11);
	coord c2(6,18);
	coord c3=min(c1,c2);//重载<运算符比较min中的两个coord对象
	cout<<"较小的坐标:("<< c3.getX()<<","<<c3.getY()<<")"<<endl;
	double d1=3.55;
	double d2=3.4;
	cout<<"较小的数"<<min(d1,d2)<<endl;//<运算符比较double对象 
	return 0;
} 
