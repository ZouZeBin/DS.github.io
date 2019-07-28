/* Callatz猜想
	对任何一个自然数，如果他是偶数，把他砍掉一半，
	奇数把（3n+1）砍掉一半，最后得到n=1，求步数
*/

//思路
/*
	读入n，之后用while判断n是否为1
	1、n为1，退出循环
	2、n不为1，进行判断...
	3、判断完后step++ 
*/ 
/* 样例
3
输出 
5 
*/ 

#include<cstdio>
int main(){
	int n,step=0;
	scanf("%d",&n);
	while(n!=1){
		if(n%2==0){
			n/=2;
		}else{
			n=(3*n+1)/2;
		}
		step++;
	}
	printf("%d",step);
	return 0;
}
