#include<cstdio>
const int maxn=100010;
bool hashTable[maxn]={false};
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		hashTable[x]=true;//����x���ֹ� 
	}
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(hashTable[x]==true){
			//�������x���֣����yes
			printf("yes\n"); 
		}else{
			printf("no\n");
		}
	} 
	return 0;
} 
