#include<iostream>
using namespace std;
class Complex{
	float real,imag;
	public:
		Complex(float r,float i):real(r),imag(i){}
		Complex():real(0),imag(0){}
		void print();
		friend Complex operator+(Complex a,Complex b);
		friend Complex operator-(Complex a,Complex b);
		friend Complex operator*(Complex a,Complex b);
		friend Complex operator/(Complex a,Complex b);
};
void Complex::print(){
	cout<<real;
	if(imag>0) cout<<"+";
	if(imag!=0) cout<<imag<<"i"<<endl;
}
 Complex operator+(Complex a,Complex b){
 	Complex temp;
 	temp.real=a.real+b.real;
 	temp.imag=a.imag+b.imag;
 	return temp;
 }
 Complex operator-(Complex a,Complex b){
 	Complex temp;
 	temp.real=a.real-b.real;
 	temp.imag=a.imag-b.imag;
 	return temp;
 }
 Complex operator*(Complex a,Complex b){
 	Complex temp;
 	temp.real=a.real*b.real-a.imag*b.imag;
 	temp.imag=a.real*b.imag+a.imag*b.real;
 	return temp;
 }
 Complex operator/(Complex a,Complex b){
 	Complex temp;
 	float tt;
 	tt=1/(b.real*b.real+b.imag*b.imag);
 	temp.real=(a.real*b.real+b.imag*b.imag)*tt;
 	temp.imag=(a.real*a.imag+b.real*b.imag)*tt;
 	return temp;
 }
int main(){
	Complex c1(2.3,4.6),c2(3.6,2.8),c3;
	c1.print();
	c2.print();
	c3=c1+c2;
	c3.print();
	cout<<endl;
	
	
	c1.print();
	c2.print();
	c3=c1-c2;
	c3.print();
	cout<<endl;
	

	c1.print();
	c2.print();
	c3=c1*c2;
	c3.print();
	cout<<endl;
	

	c1.print();
	c2.print();
	c3=c1/c2;
	c3.print();			
	return 0;
} 
