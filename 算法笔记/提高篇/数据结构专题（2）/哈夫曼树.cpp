#include<cstdio>
#include<queue>
using namespace std;
//����С���ѵ����ȶ���
priority_queue<long long,vector<long long>,greater<long long> > q;

int main(){
	int n;
	long long temp,x,y,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		q.push(temp);//����ʼ����ѹ�����ȶ��� 
	}
	while(q.size()>1){
		//ֻҪ�ŵ����������������Ԫ��
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		q.push(x+y);//ȡ���Ѷ�������Ԫ�أ�Ȼ��ѹ�����ȶ���
		ans+=x+y; 
	} 
	printf("%lld",ans);
	return 0;
} 
