/*输入案例
	4
	1 3
	2 4
	3 5
	6 7
输出
	3 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Inteval{
	int x,y;//开区间左右端点 
}I[maxn];

bool cmp(Inteval a,Inteval b){
	if(a.x!=b.x)
		return a.x>b.x;//先按照左端点从大到小排 
	else
		return a.y<b.y;//左端点相同，右端点从小到大排 
} 

int main(){
	int n;//区间个数 
	while(scanf("%d",&n),n!=0){
		for(int i=0;i<n;i++){
			scanf("%d%d",&I[i].x,&I[i].y);//输入区间 
		}
	sort(I,I+n,cmp);//把区间排序
	//ans记录不相交区间个数，lastX记录上一个被选中区间的左端点
	int ans=1,lastX=I[0].x;
	for(int i=1;i<n;i++){
		if(I[i].y<=lastX){//该右端点在lastX的左边，没有相交 
			lastX=I[i].x;//以i作为新选的区间 
			ans++; 
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
} 
