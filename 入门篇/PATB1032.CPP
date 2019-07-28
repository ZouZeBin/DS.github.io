/*
在第一行给出不超过10的五次方的正整数N，即参赛人数
每行给一位参赛者的信息和成绩 （学校编号 比赛成绩）
统计能够学校总评分最高 
*/
/*样例
	3 
	2 34
	1 56
	1 15
	输出
	1 71 
*/
#include<cstdio>
int school[100010]={0};
int main(){
	int n,schID,score;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&schID,&score);
		school[schID]+=score;
	}
	int k=1,MAX=-1;
	for(int i=1;i<=n;i++){
		if(school[i]>MAX){
			MAX=school[i];
			k=i;
		}
	}
	printf("%d %d\n",k,MAX);
	return 0;
}
