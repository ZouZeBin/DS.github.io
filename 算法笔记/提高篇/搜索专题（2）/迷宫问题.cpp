#include<cstdio>
#include<string>
#include<queue>
using namespace std;
const int maxn=100;

struct node{
	int x,y;//λ��(x,y)
	int step; //���� 
}S,T,Node;//��㣬�յ㣬��ʱ�ڵ�

int n,m;//����
char maze[maxn][maxn];//�Թ���Ϣ
bool inq[maxn][maxn]={false};//��¼λ���Ƿ����
int X[4]={0,0,1,-1};//�������� 
int Y[4]={1,-1,0,0}; 

//���λ���Ƿ���Ч
bool test(int x,int y){
	if(x>=n||x<0||y>=m||y<0) return false;//Խ��
	if(maze[x][y]=='*') return false;//ǽ��
	if(inq[x][y]==true) return false;//�������
	return true;	
} 

int BFS(){
	queue<node> q;
	q.push(S);//������ 
	while(!q.empty()){
		//ȡ������Ԫ��
		node top=q.front(); 
		//����Ԫ�س���
		q.pop();
		//������յ㷵�����ٲ���
		if(top.x==T.x&&top.y==T.y){
			return top.step;
		} 
		for(int i=0;i<4;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(test(newX,newY)){//λ����Ч 
				//����Node�ڵ�����
				Node.x=newX,Node.y=newY;
				Node.step=top.step+1;
				q.push(Node);
				inq[newX][newY]=true;//������ 
			}
		}
	}
	return -1;//�޷����� 
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		getchar();//����ÿ�к���Ļ��з�
		for(int j=0;j<m;j++){
			maze[i][j]=getchar();
		} 
		maze[i][m+1]='\0';
	}
	scanf("%d%d%d%d.",&S.x,&S.y,&T.x,&T.y);//����յ�
	S.step=0;//������ʼ��
	printf("%d\n",BFS()); 
	return 0;
} 

