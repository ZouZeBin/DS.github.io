#include<cstdio>
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
} 
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		printf("%d\n",lcm(m,n));
	}
	return 0;
}
