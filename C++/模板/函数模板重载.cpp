#include<iostream>
#include<string.h>
using namespace std;
template<class T>
T max1(T x,T y){
	return (x>y?x:y);
} 

char *max1(char *x,char *y){
	if(strcmp(x,y)>=0)
		return x;
	else return y;
}

int main(){
	cout<<max1(2,15)<<endl;//不能用max和库里max重名了 
	cout<<max1(2.3,8.0)<<endl;
	cout<<max1("China","Beijing")<<endl; 
	return 0;
} 
