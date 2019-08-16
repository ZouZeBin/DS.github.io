#include<iostream>
using namespace std;
void fun(int a[],int n,int &max,int &min){
	max=min=a[0];
	for(int i=1;i<n;i++){
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
	}
	cout<<"max:"<<max<<endl;
	cout<<"min:" <<min<<endl;
}
int main(){
	int a[6]={1,3,5,6,7,8};
	int max,min;
	fun(a,6,max,min);
	return 0;
} 

