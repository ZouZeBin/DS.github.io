#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std; 
const int MAXV=1000;//最大顶点数
const int INF=1000000000;

//邻接矩阵
int n,G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV]={false};//标记数组是否访问

void Dijkstra(int s){//s为起点 
	fill(d,d+MAXV,INF);//将整个数组赋为INF
	d[s]=0;//起点s到自身的距离为0
	for(int i=0;i<n;i++){//循环n次 
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		} 
		//剩下的点不联通
		if(u==-1) return;
		vis[u]=true;//标识已访问
		for(int v=0;v<n;v++){
			//若v未访问,可达且更优
			 if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
			 	d[v]=d[u]+G[u][v];//优化d[v] 
			 }
		} 
	} 
} 


//邻接表版本
struct Node{
	int v,dis;//边 边权 
}; 
vector<Node> Adj[MAXV];//图的邻接表表示
int n;//n为顶点数
int d[MAXV];//到达各点的最短路径长度
bool vis[MAXV]={false};//标记数组是否访问


void Dijkstra(int s){//s为起点 
	fill(d,d+MAXV,INF);//将整个数组赋为INF
	d[s]=0;//起点s到自身的距离为0
	for(int i=0;i<n;i++){//循环n次 
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		} 
		//剩下的点不联通
		if(u==-1) return;
		vis[u]=true;//标识已访问
//		for(int v=0;v<n;v++){
//			//若v未访问,可达且更优
//			 if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
//			 	d[v]=d[u]+G[u][v];//优化d[v] 
//			 }
//		}

		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;//通过邻接表可以到达顶点v
			//若v未访问,可达且更优
			 if(vis[v]==false&&d[u]+Adj[u][j].dis<d[v]){
			 	d[v]=d[u]+Adj[u][j].dis;//优化d[v] 
			 } 
		} 
	} 
} 



 





