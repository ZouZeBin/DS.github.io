/*
	模板
	void BFS(int s) {
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			取出队首元素top
			访问队首元素top
			将队首元素出队
			将top的下一个节点中未曾入队的节点全部入队，并设置为已经入队 
		}
	}
*/
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=100;

struct node{
	int x,y;//(x,y)
}Node;

int n,m;//矩阵大小n*m
int matrix[maxn][maxn];//01矩阵
bool inq[maxn][maxn]={false};//记录位置是否入队
int X[4]={0,0,1,-1};//增量数组
int Y[4]={1,-1,0,0};

bool judge(int x,int y){//判断坐标是否需要访问 
	//越界返回false
	if(x>=n||x<0||y>=m||y<0)	return false;
	//当前位置为0，或者已经入队，返回false
	if(matrix[x][y]==0||inq[x][y]==true) return false;
	//以上都不满足，返回true
	return true; 
} 

void BFS(int x,int y){
	queue<node> Q;//定义队列
	Node.x=x,Node.y=y;//当前坐标(x,y)
	Q.push(Node);//将Node节点入队
	inq[x][y]=true;//设置入队标记
	while(!Q.empty()){
		node top=Q.front();//取出队首元素
		Q.pop();//队首元素出队
		for(int i=0;i<4;i++){//循环4次，得到四个相邻位置 
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(judge(newX,newY)){//如果是可以访问的新位置 
				//设置Node节点的坐标(newX,newY)
				Node.x=newX,Node.y=newY;
				Q.push(Node);//将节点入队
				inq[newX][newY]=true;//标记已入队 
			}
		} 
	} 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			scanf("%d",&matrix[x][y]);//读入01矩阵			
		}

	}
	int ans=0;//存放块数
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			//如果元素为1，且未入队
			if(matrix[x][y]==1&&inq[x][y]==false) {
				ans++;//块数+1
				BFS(x,y);//访问整个块，将所有1的inq标记为true 
			}
		}
	} 
	printf("%d\n",ans); 
	return 0;
} 






 
