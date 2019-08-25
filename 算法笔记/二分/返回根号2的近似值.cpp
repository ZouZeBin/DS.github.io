#include<iostream>
using namespace std;
const double eps=1e-5;//精度
double f(double x){//计算f(x) 
	return x*x; 
} 
double calSqrt(){
	double left=1,right=2,mid;//[left,right]=[1,2]
	while(right-left>eps){
		mid=(left+right)/2;//取中点
			if(f(mid)>2){//mid>sqrt(2)
				right=mid;//往左区间逼近 
			}else{
				left=mid;//往右区间逼近 
			} 
	}
	return mid; 
}
int main(){
	cout<<calSqrt();
	return 0;
}
