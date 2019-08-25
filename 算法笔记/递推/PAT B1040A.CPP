/*
字符串APPAPT中包含了两个单词“PAT”，
	其中第一个PAT是第2位(P),第4位(A),第6位(T)；
		第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入格式：
	输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：
	在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int MOD=1000000007;
char str[MAXN];//字符串
int leftNumP[MAXN]={0};//每一位左边含P元素的个数
int main(){
	gets(str);//读入字符串
	int len=strlen(str);//长度
	for(int i=0;i<len;i++) {
		if(i>0){//如果不是0号位 
			leftNumP[i]=leftNumP[i-1];//继承上一位的结果
		} 
		if(str[i]=='P'){//当前位是P 
			leftNumP[i]++;
		}
	} 
	int ans=0,rightNumT=0;
	for(int i=len-1;i>=0;i--){//从右到左遍历字符串 
		if(str[i]=='T'){
			rightNumT++;//右边的T+1 
		}else{
			if(str[i]=='A'){//当前为A
				ans=(ans+leftNumP[i]*rightNumT)%MOD;//累计乘积 
			}
		} 
	}     
	printf("%d",ans);
	return 0; 
}





 
