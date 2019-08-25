#include<iostream>
using namespace std;
//有bug
int merge(int A[],int B[],int C[],int n,int m){
	int i=0,j=0,index=0;//i指向A[0],j指向B[0]
	while(i<n&&j<m){
		if(A[i]<=B[j]){
			C[index++]=A[i++];
		}else{
			C[index++]=B[j++];
		}
	} 
	while(j<n)C[index++]=A[i++];//A剩余加入C
	while(j<m)C[index++]=B[j++];//B剩余加入C
	return index;//返回长度 
}
int main(){
	int A[]={1,2,4};
	int B[]={5,7};
	int C[5]={0};
	int n=4;
	int m=5;
	cout<<merge(A,B,C,n,m);
	return 0;
} 
