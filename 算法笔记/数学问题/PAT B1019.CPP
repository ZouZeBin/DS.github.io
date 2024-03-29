/*
	给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，	
	再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。
	一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，
	这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；
否则将计算的每一步在一行内输出，直到6174作为差出现，
输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000*/

#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){//递减排序cmp 
	return a>b; 
}
void to_array(int n,int num[]){//将n的每一位存到num数组中 
	for(int i=0;i<4;i++){
		num[i]=n%10;
		n/=10;
	} 
}
int to_number(int num[]){//将num数组转为数字 
	int sum=0;
	for(int i=0;i<4;i++){
		sum=sum*10+num[i];
	}
	return sum;
}

int main(){
	int n,max,min;
	scanf("%d",&n);
	int num[5];
	while(1){
		to_array(n,num);//将n转化为数组
		sort(num,num+4);//对num从小到大排序
		min=to_number(num);//获取最小值
		sort(num,num+4,cmp);//对num从大到小排序
		max=to_number(num);//获取最大值
		n=max-min;//得到下一个数
		printf("%04d-%04d=%04d\n",max,min,n);
		if(n==0||n==6174) break; 
	}
	return 0;
}







