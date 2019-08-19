#include<iostream>
using namespace std;
class Complex{
		double real;//实部 
		double imag;//虚部
	public:
		friend ostream& operator<<(ostream&,Complex &);
		friend istream& operator>>(istream&,Complex &); 
};

//重载流插入<<
ostream& operator<<(ostream& output,Complex &c){
	output<<"("<<c.real;
	if(c.imag>=0){
		output<<"+";
	}
	output<<c.imag<<"i)"<<endl;
	return output; 
}

//重载流提取>> 
istream& operator>>(istream& input,Complex &c){
	cout<<"输入一个复数的实部和虚部:";
	input>>c.real>>c.imag;
	return input;
}
int main(){
	Complex c;
	cin>>c;
	cout<<"c="<<c<<endl;
	return 0;
}
