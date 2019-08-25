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
 
// ���ڶ����������������ĵݹ麯��
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; 
	mid = n/2;  // �����м�ֵmid 
 
	// �������������� 
	// midԪ��(������0��mid-1)�����������һ����
	// (n-mid)Ԫ��(��mid��n-1)�����������һ����
	L = new int[mid];
	R = new int [n - mid];
 
	for(i = 0;i<mid;i++) L[i] = A[i]; // ���������� 
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // ���������� 
	MergeSort(L,mid);  // ���������������� 
	MergeSort(R,n-mid);  // ���ұ������������ 
	Merge(A,L,mid,R,n-mid);  // ��L��R�ϲ�ΪA��Ϊ�����б�.
	// ɾ���ռ� 
	delete [] R;
	delete [] L;
}
 
int main() {
 
	int A[] = {6,2,3,1,9,10,15,13,12,717}; //���������� 
	int i,numberOfElements;
	numberOfElements = sizeof(A)/sizeof(A[0]);//���������鳤�� 
	MergeSort(A,numberOfElements);
	for(i = 0;i < numberOfElements;i++)//��ӡ 
	   cout << " " << A[i];
	return 0;
}
