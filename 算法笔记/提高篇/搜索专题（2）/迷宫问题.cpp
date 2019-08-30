#include<cstdio>
#include<string>
#include<queue>
using namespace std;
const int maxn=100;

struct node{
	int x,y;//位置(x,y)
	int step; //步数 
}S,T,Node;//起点，终点，临时节点

int n,m;//行列
char maze[maxn][maxn];//迷宫信息
bool inq[maxn][maxn]={false};//记录位置是否入队
int X[4]={0,0,1,-1};//增量函数 
int Y[4]={1,-1,0,0}; 

//检测位置是否有效
bool test(int x,int y){
	if(x>=n||x<0||y>=m||y<0) return false;//越界
	if(maze[x][y]=='*') return false;//墙壁
	if(inq[x][y]==true) return false;//已入过队
	return true;	
} 

int BFS(){
	queue<node> q;
	q.push(S);//起点入队 
	while(!q.empty()){
		//取出队首元素
		node top=q.front(); 
		//队首元素出队
		q.pop();
		//如果到终点返回最少步数
		if(top.x==T.x&&top.y==T.y){
			return top.step;
		} 
		for(int i=0;i<4;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(test(newX,newY)){//位置有效 
				//设置Node节点坐标
				Node.x=newX,Node.y=newY;
				Node.step=top.step+1;
				q.push(Node);
				inq[newX][newY]=true;//标记入队 
			}
		}
	}
	return -1;//无法到达 
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		getchar();//过滤每行后面的换行符
		for(int j=0;j<m;j++){
			maze[i][j]=getchar();
		} 
		maze[i][m+1]='\0';
	}
	scanf("%d%d%d%d.",&S.x,&S.y,&T.x,&T.y);//起点终点
	S.step=0;//步数初始化
	printf("%d\n",BFS()); 
	return 0;
} 

