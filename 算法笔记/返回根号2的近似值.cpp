#include<iostream>
using namespace std;
const double eps=1e-5;//����
double f(double x){//����f(x) 
	return x*x; 
} 
double calSqrt(){
	double left=1,right=2,mid;//[left,right]=[1,2]
	while(right-left>eps){
		mid=(left+right)/2;//ȡ�е�
			if(f(mid)>2){//mid>sqrt(2)
				right=mid;//��������ƽ� 
			}else{
				left=mid;//��������ƽ� 
			} 
	}
	return mid; 
}
int main(){
	cout<<calSqrt();
	return 0;
}
