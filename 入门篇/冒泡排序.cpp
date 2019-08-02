#include <cstdio>
int main(){
	int a[10]={11,8,5,91,5};
	for(int i=1;i<=4;i++){
		for(int j=0;j<5-i;j++){
			if(a[j]>a[j+1]){
				
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<5;i++){
		printf("%d\n",a[i]);
	}
	return 0;
} 
