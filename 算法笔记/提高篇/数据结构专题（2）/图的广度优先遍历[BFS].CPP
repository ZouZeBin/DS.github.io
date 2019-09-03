#include<cstdio>
#include<queue>
using namespace std;

/*实现伪代码*/
BFS(u){
	//遍历u所在的连通块
	queue q;//定义队列q
	将u入队
	inq[u]=true;//设置u已被加入过队列
	while(q非空){
		//只要队列为空
		取出q的队首元素u进行访问;
		for(从u出发可达的所有顶点v)//枚举可达顶点v
			if(inq[v]==false){//v未曾入队 
				将v入队
				inq[v]=true;//设置v已被加入过队列 
			} 
	} 
}

BFSTrave(G){
	//遍历图G
	for(G的所有顶点u)//枚举G的所有顶点u
		if(inq[v]==false)//未加入过队列
			BFS(u);//遍历u所在的连通块 
} 
