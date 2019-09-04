#include<cstdio>
#include<algorithm>
using namespace std; 
const int MAXV=1000;//最大顶点数
const int INF=1000000000;

//邻接矩阵
int n,m,s,G[MAXV][MAXV];
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
			 if(vis[v]==false &&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
			 	 d[v]=d[u]+G[u][v];//优化d[v] 
			 }
		} 
	} 
} 

int main(){
	int u,v,w;
	scanf("%d%d%d",&u,&m,&s);//顶点个数，边数，起点编号
	fill(G[0],G[0]+MAXV*MAXV,INF);//初始化
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=w;
	} 
	Dijkstra(s);//算法入口
	for(int i=0;i<n;i++){
		printf("%d",d[i]);//输出顶点最短距离 
	} 
	return 0;
}












