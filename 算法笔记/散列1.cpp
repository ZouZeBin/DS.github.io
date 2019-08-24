#include<cstdio>
const int maxn=100010;
bool hashTable[maxn]={false};
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		hashTable[x]=true;//数字x出现过 
	}
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(hashTable[x]==true){
			//如果数字x出现，输出yes
			printf("yes\n"); 
		}else{
			printf("no\n");
		}
	} 
	return 0;
} 
