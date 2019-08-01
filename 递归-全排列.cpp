#include<cstdio>

void swap(int A[],int i,int j ){
	int temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}
void printArray(int A[],int n){
	int i;
	for(i=0;i<n;i++){
			printf("%d",A[i]);
		}
	printf("\n");
}
void perm(int A[],int k,int m){
	int i;
	if(k==m){
		printArray(A,k+1);
	}else{
		for(i=k;i<=m;i++){
			swap(A,k,i);
			perm(A,k+1,m);
			swap(A,k,i);
		}
	}
}
int main(){
	int A[5]={1,2,3,4,5};
	perm(A,0,4);
	getchar();
} 
