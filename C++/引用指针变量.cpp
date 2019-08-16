#include<iostream>
using namespace std;
int main(){
	int n=10,*p=&n,* &rn=p;
	(*p)++;
	cout<<"n="<<n<<endl;
	(*rn)++;
	cout<<"n="<<n<<endl;
	return 0;
}
