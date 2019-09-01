//�㷨�ʼ�333ҳ���� 
#include<cstdio>
const int N=110;
int father[N];//��Ÿ��׽ڵ�
bool isRoot[N];//��¼ÿ���ڵ��Ƿ���Ϊ�Լ��ĸ��ڵ�
int findFather(int x){
	//����x���ڼ��ϵĸ��ڵ�
	int a=x;
	while(x!=father[x]){
		x=father[x];
	} 
	//ѹ��·��
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	} 
	return x;
} 

void Union(int a,int b){
	//�ϲ�a,b����
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB){
		father[faA]=faB;
	} 
}

void init(int n){
	//��ʼ��
	for(int i=1;i<=n;i++){
		father[i]=i;
		isRoot[i]=false;
	} 
}

int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	init(n);//Ҫ�ǵó�ʼ��
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);//�������������ѵĹ�ϵ
		Union(a,b);//�ϲ�a,b���� 
	} 
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]=true;//i�ĸ��ڵ�ΪfindFather(i) 
	} 
	int ans=0;//��¼��������
	for(int i=1;i<=n;i++){
		ans+=isRoot[i];
	} 
	printf("%d\n",ans);
	return 0;
}



