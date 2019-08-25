#include<cstdio>
const int maxn=11;
//P为当前排列，hashTable记录整数x是否已经在P中
int n,P[maxn],hashTable[maxn]={false};
//处理当前排列第index位
void generateP(int index){
	if(index==n+1){//递归边界，已经处理完排列1-n位
		for(int i=1;i<=n;i++){
			printf("%d",P[i]);//输出当前排列 
		} 
		printf("\n");
		return; 
	}


for(int x=1;x<=n;x++){//枚举1-n，将x填入P[index]
	if(hashTable[x]==false){//x不在P[0]-P[index] 里面
		P[index]=x;//把x加入该排列
		hashTable[x]=true;//标记x已经在P中
		generateP(index+1);//处理排列的第index+1位
		hashTable[x]=false;//还原状态 
	} 
  }	
}
int main(){
	n=4;//输出1-3的全排列
	generateP(1);//P(1)开始填 
	return 0;
}
