#include<cstdio>
int F(int n){
	if(n==0||n==1)return 1;//µİ¹é±ß½ç
	else return F(n-1)+F(n-2); 
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",F(n));
	return 0;
} 
