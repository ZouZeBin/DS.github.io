#include<iostream>
using namespace std;
//��bug
int merge(int A[],int B[],int C[],int n,int m){
	int i=0,j=0,index=0;//iָ��A[0],jָ��B[0]
	while(i<n&&j<m){
		if(A[i]<=B[j]){
			C[index++]=A[i++];
		}else{
			C[index++]=B[j++];
		}
	} 
	while(j<n)C[index++]=A[i++];//Aʣ�����C
	while(j<m)C[index++]=B[j++];//Bʣ�����C
	return index;//���س��� 
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
