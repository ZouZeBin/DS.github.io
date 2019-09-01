//算法笔记333页例题 
#include<cstdio>
const int N=110;
int father[N];//存放父亲节点
bool isRoot[N];//记录每个节点是否作为自己的根节点
int findFather(int x){
	//查找x所在集合的根节点
	int a=x;
	while(x!=father[x]){
		x=father[x];
	} 
	//压缩路径
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	} 
	return x;
} 

void Union(int a,int b){
	//合并a,b集合
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB){
		father[faA]=faB;
	} 
}

void init(int n){
	//初始化
	for(int i=1;i<=n;i++){
		father[i]=i;
		isRoot[i]=false;
	} 
}

int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	init(n);//要记得初始化
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);//输入两个好朋友的关系
		Union(a,b);//合并a,b集合 
	} 
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]=true;//i的根节点为findFather(i) 
	} 
	int ans=0;//记录集合数量
	for(int i=1;i<=n;i++){
		ans+=isRoot[i];
	} 
	printf("%d\n",ans);
	return 0;
}



