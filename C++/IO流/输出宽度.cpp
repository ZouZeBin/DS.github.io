#include<iostream>
//ostream������iostream�࣬����Ҳ������ #include<iostream.h>
#include<iomanip>
using namespace std;
int main(){
	cout<<setw(10)<<1234567890<<endl;
	cout.width(10);
	cout<<1.2<<endl;
	cout.width(10);
	cout<<'A'<<endl; //���õĿ�������� 
	cout.width(10);
	cout.put('A');//��ǰ���ÿ�Ȳ������� 
	return 0;
}
