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

//����"<"��������غ��� 
int coord::operator<(coord &c){
	if(x<c.x)
		if(y<c.y)
			return 1;
	return 0; 
}

//����ģ��˵������ 
template<class obj>

obj &min(obj &o1,obj &o2){
	if(o1<o2)//��������ʵ����Ϊ����󣬶�"<"�������أ�����ʹ�ñ�׼"<"����� 
		return o1;
	else 
		return o2;
} 
int main(){
	coord c1(5,11);
	coord c2(6,18);
	coord c3=min(c1,c2);//����<������Ƚ�min�е�����coord����
	cout<<"��С������:("<< c3.getX()<<","<<c3.getY()<<")"<<endl;
	double d1=3.55;
	double d2=3.4;
	cout<<"��С����"<<min(d1,d2)<<endl;//<������Ƚ�double���� 
	return 0;
} 
