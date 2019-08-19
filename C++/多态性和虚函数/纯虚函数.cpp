#include<iostream>
#include<math.h>
using namespace std;
class base{
	protected:
		int x,y;
	public:
		virtual void setX(int i,int j=0){
			x=i;
			y=j;
		}
		virtual void disp()=0;//¶¨Òå´¿Ðéº¯Êý 
};

class Square:public base{
	public:
		void disp(){
			cout<<"x="<<x<<":";
			cout<<"x square="<<x*x<<endl;
		}
}; 

class Cube:public base{
	public:
		void disp(){
			cout<<"x="<<x<<":";
			cout<<"x Cube="<<x*x*x<<endl;	
		}
};

class Chpow:public base{
	public:
		void disp(){
			cout<<"x="<<x<<" "<<"y="<<y<<" : ";
			cout<<"pow(x,y)="<<pow(double(x),double(y))<<endl;	
		}
};

int main(){
	base *ptr;
	Square B;
	Cube C;
	Chpow D;
	ptr=&B;
	ptr->setX(5);
	ptr->disp();
	ptr=&C;
	ptr->setX(6);
	ptr->disp(); 
	ptr=&D;
	ptr->setX(3,4);
	ptr->disp();
	return 0;
}




