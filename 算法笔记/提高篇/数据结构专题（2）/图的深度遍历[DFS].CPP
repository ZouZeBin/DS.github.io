#include<cstdio>
#include<vector>
using namespace std;
/* 
//代码思路 
DFS(u){
	//访问顶点u
	vis[u]=true;//设置u已经被访问
	for(/*从u出发能到达所有顶点v/)//枚举从u出发到达的所有顶点v
		if(vis[v]==false)//如果v未被访问
			DFS(v);//递归访问v 
}
 
DFSTrave(G){
	//遍历图G
	for(/*G的所有顶点v/)
		 if(vis[u]==false)//u未被访问
		 	DFS(u);//访问u所在的连通快 
}
*/////////////////////////////////// 

const int MAXV=1000;//最大顶点数
const int INF=1000000000;//很大的数

//邻接矩阵版本
int n,G[MAXV][maxv];//n为顶点数 MAXV为最大顶点数
bool vis[MAXV]={false};//默认未被访问

void DFS_1(int u,int depth){//u 当前顶点标号 depth深度 
	vis[u]=true;//设置u已被访问
	//对u能到达的分支节点进行访问
	for(int v=0;v<n;v++){//对每个顶点v 
		if(vis[v]==false&&G[u][v]!=INF){
			//如果v未被访问，且u可到达v
			DFS_1(v,depth+1);//访问v，深度+1 
		} 
	} 
} 

void DFSTrave_1(){
	//遍历图G
	for(int u=0;u<n;u++){
		//对每个顶点
		if(vis[u]==false){
			//如果u未被访问，访问连通块
			DFS_1(u,1);//1表示初始第一层 
		} 
	} 
} 


//邻接表版本
vector<int> Adj[MAXV];//图G的邻接表
//	int n;//n为顶点数，MAXV为最大顶点数
//	bool vis[MAXV]=false;

void DFS_2(int u,int depth){
	vis[u]=true;
	//对u能到达的分支节点进行访问
	for(int i=0;i<Adj[u].size();i++){//对每个顶点v 
		int v=Adj[u][i];
		if(vis[v]==false){
			//如果v未被访问
			DFS_2(v,depth+1);//访问v，深度+1 
		} 
	} 	
} 

void DFSTrave_2(){
	//遍历图G
	for(int u=0;u<n;u++){
		//对每个顶点
		if(vis[u]==false){
			//如果u未被访问，访问连通块
			DFS_2(u,1);//1表示初始第一层 
		} 
	} 
} 








 

