#include<iostream>
using namespace std;
/*
	代码思路：
	反复将区间[left,right]分为两半
	对两个子区间[left,mid],[mid+1,right]分别递归进行归并排序 
*/
const int maxn=100;
//将数组A的[L1,R1],[L2,R2]合并成有序区间（L2=R1+1） 
void merge(int *A,int L1,int R1,int L2,int R2){
	int i=L1,j=L2;
	int temp[maxn],index=0;
	while(i<=R1&&j<=R2){
		if(A[i]<A[j]){
			temp[index++]=A[i++];
		}else{
			temp[index++]=A[j++];
		}
	} 
	while (i<=R1) temp[index++]=A[i++];
	while (i<=R2) temp[index++]=A[j++];
}
//将array数组当前区间[left,right]进行归并
void mergeSort(int A[],int left,int right){ 
	if(left<right){
		int mid=(left+right)/2;//取中点 
		mergeSort(A,left,mid);//递归将左区间归并 
		mergeSort(A,mid+1,right);//递归将右区间归并 
		merge( A,left,mid,mid+1,right);
	}
} 
int main(){
	
	int A[]={1,2,4,3};
	mergeSort(A,0,4);
	return 0;
} 
