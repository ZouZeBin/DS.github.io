#include<cstdio>
#include<queue>
using namespace std;
//代表小顶堆的优先队列
priority_queue<long long,vector<long long>,greater<long long> > q;

int main(){
	int n;
	long long temp,x,y,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		q.push(temp);//将初始重量压入优先队列 
	}
	while(q.size()>1){
		//只要优点队列中至少有两个元素
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		q.push(x+y);//取出堆顶的两个元素，然后压入优先队列
		ans+=x+y; 
	} 
	printf("%lld",ans);
	return 0;
} 
