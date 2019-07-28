#include<cstdio>
#include<cmath>
const double eps=1e-8;
const double pi=acos(-1.0);
#define Equ(a,b)  ((fabs((a)-(b))) <(eps))
#define More(a,b) (((a)-(b))>(eps))
#define Less(a,b) (((a)-(b))<(-eps))
int main(){
	double db=1.23;
//	if(Equ(db,1.23000001)){
//		printf("db=1.23!");
//	}else{
//		printf("db!=1.23!");
//	}
//	if(More(db,1.22999)){
//		printf("db>1.22999999999999999");
//	}else{
//		printf("db<1.22999");
//	}
int T,a,b;
scanf("%d",&T);
while(T--){
	scanf("%d%d",&a,&b);
	printf("%d\n",a+b);
}

	return 0;
}
