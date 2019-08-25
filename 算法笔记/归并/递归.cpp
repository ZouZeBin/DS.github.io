#include <cstdio>
#include <iostream>
 
using namespace std;
 
// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
 
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;
 
	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}
 
// 用于对整数数组进行排序的递归函数
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; 
	mid = n/2;  // 查找中间值mid 
 
	// 创建左右子数组 
	// mid元素(从索引0到mid-1)是左子数组的一部分
	// (n-mid)元素(从mid到n-1)是右子数组的一部分
	L = new int[mid];
	R = new int [n - mid];
 
	for(i = 0;i<mid;i++) L[i] = A[i]; // 创建左数组 
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // 创建右数组 
	MergeSort(L,mid);  // 对左边数组进行排序 
	MergeSort(R,n-mid);  // 对右边数组进行排序 
	Merge(A,L,mid,R,n-mid);  // 将L和R合并为A作为排序列表.
	// 删除空间 
	delete [] R;
	delete [] L;
}
 
int main() {
 
	int A[] = {6,2,3,1,9,10,15,13,12,717}; //待排序数组 
	int i,numberOfElements;
	numberOfElements = sizeof(A)/sizeof(A[0]);//待排序数组长度 
	MergeSort(A,numberOfElements);
	for(i = 0;i < numberOfElements;i++)//打印 
	   cout << " " << A[i];
	return 0;
}
