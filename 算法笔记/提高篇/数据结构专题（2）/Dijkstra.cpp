#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std; 
const int MAXV=1000;//��󶥵���
const int INF=1000000000;

//�ڽӾ���
int n,G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV]={false};//��������Ƿ����

void Dijkstra(int s){//sΪ��� 
	fill(d,d+MAXV,INF);//���������鸳ΪINF
	d[s]=0;//���s������ľ���Ϊ0
	for(int i=0;i<n;i++){//ѭ��n�� 
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		} 
		//ʣ�µĵ㲻��ͨ
		if(u==-1) return;
		vis[u]=true;//��ʶ�ѷ���
		for(int v=0;v<n;v++){
			//��vδ����,�ɴ��Ҹ���
			 if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
			 	d[v]=d[u]+G[u][v];//�Ż�d[v] 
			 }
		} 
	} 
} 


//�ڽӱ�汾
struct Node{
	int v,dis;//�� ��Ȩ 
}; 
vector<Node> Adj[MAXV];//ͼ���ڽӱ��ʾ
int n;//nΪ������
int d[MAXV];//�����������·������
bool vis[MAXV]={false};//��������Ƿ����


void Dijkstra(int s){//sΪ��� 
	fill(d,d+MAXV,INF);//���������鸳ΪINF
	d[s]=0;//���s������ľ���Ϊ0
	for(int i=0;i<n;i++){//ѭ��n�� 
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		} 
		//ʣ�µĵ㲻��ͨ
		if(u==-1) return;
		vis[u]=true;//��ʶ�ѷ���
//		for(int v=0;v<n;v++){
//			//��vδ����,�ɴ��Ҹ���
//			 if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
//			 	d[v]=d[u]+G[u][v];//�Ż�d[v] 
//			 }
//		}

		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;//ͨ���ڽӱ���Ե��ﶥ��v
			//��vδ����,�ɴ��Ҹ���
			 if(vis[v]==false&&d[u]+Adj[u][j].dis<d[v]){
			 	d[v]=d[u]+Adj[u][j].dis;//�Ż�d[v] 
			 } 
		} 
	} 
} 



 





