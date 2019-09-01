#include<iostream>
using namespace std;
const int N=100;
//1、初始化 每个元素都是一个集合 
int father[N];
for(int i=1;i<=N;i++){
	father[i]=i;
} 

//2、查找
int findFather(int x){
	while(x!=father[x]){
		//如果不是根节点，继续循环
		x=father[x];//获取自己的父亲节点 
	}
	return x; 
}
//或者可以用递归 
int findFather2(int x){
	if(x==father[x]) return x;//找不到根节点返回根节点编号x
	else return findFather2(father[x]);//递归查找 
}

//3、合并
void Union(int a,int b){
	int faA=findFather(a);//查找a的根节点，记为faA
	int faB=findFather(b);//查找b的根节点，记为faB
	if(faA!=faB){
		father[faA]=faB;//合并 
	} 
} 

//4、路径压缩
/*
	步骤1：按原先的写法获得x的根节点r
	步骤2：重新从x开始走一遍寻找根节点的过程，
	       把路径上经过的所有节点的父亲全部改为根节点 
*/ 
int findFather11(int x){
	//由于x在下面while会变成根节点，先保存一下
	int a=x;
	while(x!=father[x]){
		//寻找根节点
		x=father[x]; 
	} 
	//x存放的是根节点，下面把路径上的所有节点的father都改成根节点
	while(a!=father[a]){
		int z=a;//因为a要被father覆盖，所以先保存a的值，以修改father[a]
		a=father[a];//a回溯父亲节点
		father[z]=x; 
	} 
	return x;//返回根节点 
}

//递归写法
int  findFather22(int v){
	if(v==father[v]) return v;//找到根节点
	else{
		int F=findFather22(father[v]);
		father[v]=F;//将根节点F赋给father[v]
		return F;//返回根节点 
	} 
} 



 

