/*（青蛙题精选）你现在是一个买卖青蛙的 huster。
   每天的青蛙价格不一样，prices[i]代表青蛙在第 i 天的价 格，
   求只做一次交易(买入 1 只，卖出 1 只)能得到的最大收益
   （你必须先买了青蛙之后才能 卖青蛙）。 


	时间复杂度要求：O（n） 

	函数：int maxIncome（int prices[ ],int n） 
	
	输入 
	i          4
	prices[i]  4 1 2 3
	输出
	2 
	解析：
	记录遍历的元素中的最小值min和当前所求的最大差值d,然后继续遍历下一个元素
	先和当前最小值min求差，如果比d大，如果差值小于min，则更新min 
*/ 

#include<iostream>
using namespace std;
int maxIncome(int prices[],int n);
int main(){
	int prices[150],i,n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&prices[i]);
	}
	k=maxIncome(prices,n);
	printf("%d",k);
	return 0;
} 

int maxIncome(int prices[],int n ){
	int min,max,i,j;
	max=prices[n-1];
	min=prices[0];
	i=0;j=n-1;
	while(i<j){
		if(prices[i+1]<prices[i]){
			min=prices[i+1];
		}
		if(prices[j-1]>prices[j]){
			max=prices[j];
		}
		i++;
		j--;
	}
	return (max-min);
}
