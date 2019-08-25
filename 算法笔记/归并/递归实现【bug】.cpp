#include<iostream>
using namespace std;
/*
	����˼·��
	����������[left,right]��Ϊ����
	������������[left,mid],[mid+1,right]�ֱ�ݹ���й鲢���� 
*/
const int maxn=100;
//������A��[L1,R1],[L2,R2]�ϲ����������䣨L2=R1+1�� 
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
//��array���鵱ǰ����[left,right]���й鲢
void mergeSort(int A[],int left,int right){ 
	if(left<right){
		int mid=(left+right)/2;//ȡ�е� 
		mergeSort(A,left,mid);//�ݹ齫������鲢 
		mergeSort(A,mid+1,right);//�ݹ齫������鲢 
		merge( A,left,mid,mid+1,right);
	}
} 
int main(){
	
	int A[]={1,2,4,3};
	mergeSort(A,0,4);
	return 0;
} 
