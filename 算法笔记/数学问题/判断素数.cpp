#include<cstdio>
#include<cmath>
bool isPrime(int n){
	if(n<=1)
		return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(isPrime(n))
			printf("yes\n");
		else
		    printf("NO\n");
	}
}
