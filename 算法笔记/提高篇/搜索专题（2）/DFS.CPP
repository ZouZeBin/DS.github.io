/*
	有n件物品，没见物品重量为w[i],价值为c[i].现在需要选出若干物品放入容器
	量为V的背包中，使得在选入背包的物品重量不超过V的前提下，让背包物品价
	值和最大，求最大价值（1<=n<=20） 
*/
#include<cstdio>
const int maxn=30;
int n,V,maxValue=0;//物品件数 背包容量 最大价值
int w[maxn],c[maxn];// w[i]每件物品的重量 c[i]每件物品的价值
//DFS,index为当前处理物品编号
//sumW当前总重量,sumC当前总价值
void DFS(int index,int sumW,int sumC){
	if(index==n){//已经完成对n件物品的选择（死胡同） 
		if(sumW<=V&&sumC>maxValue){
			maxValue=sumC;//更新最大价值 
		} 
		return; 
	} 
	//岔道口
	DFS(index+1,sumW,sumC);//不选第index个物品
	DFS(index+1,sumW+w[index],sumC+c[index]);//选第index件物品
}	
int main(){
	scanf("%d%d",&n,&V);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);//每件物品的重量 
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);//每件物品的价值 
	} 
	DFS(0,0,0);//初始化
	printf("%d\n",maxValue); 
	return 0;
} 

//复杂度为2的n次方 


 
