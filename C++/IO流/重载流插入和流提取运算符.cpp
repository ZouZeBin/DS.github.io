#include<iostream>
using namespace std;
class Complex{
		double real;//ʵ�� 
		double imag;//�鲿
	public:
		friend ostream& operator<<(ostream&,Complex &);
		friend istream& operator>>(istream&,Complex &); 
};

//����������<<
ostream& operator<<(ostream& output,Complex &c){
	output<<"("<<c.real;
	if(c.imag>=0){
		output<<"+";
	}
	output<<c.imag<<"i)"<<endl;
	return output; 
}

//��������ȡ>> 
istream& operator>>(istream& input,Complex &c){
	cout<<"����һ��������ʵ�����鲿:";
	input>>c.real>>c.imag;
	return input;
}
int main(){
	Complex c;
	cin>>c;
	cout<<"c="<<c<<endl;
	return 0;
}
