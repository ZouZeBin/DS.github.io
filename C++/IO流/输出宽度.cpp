#include<iostream>
//ostream类派生iostream类，这里也可以用 #include<iostream.h>
#include<iomanip>
using namespace std;
int main(){
	cout<<setw(10)<<1234567890<<endl;
	cout.width(10);
	cout<<1.2<<endl;
	cout.width(10);
	cout<<'A'<<endl; //设置的宽度起作用 
	cout.width(10);
	cout.put('A');//此前设置宽度不起作用 
	return 0;
}
