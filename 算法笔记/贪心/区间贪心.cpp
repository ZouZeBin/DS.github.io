/*���밸��
	4
	1 3
	2 4
	3 5
	6 7
���
	3 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Inteval{
	int x,y;//���������Ҷ˵� 
}I[maxn];

bool cmp(Inteval a,Inteval b){
	if(a.x!=b.x)
		return a.x>b.x;//�Ȱ�����˵�Ӵ�С�� 
	else
		return a.y<b.y;//��˵���ͬ���Ҷ˵��С������ 
} 

int main(){
	int n;//������� 
	while(scanf("%d",&n),n!=0){
		for(int i=0;i<n;i++){
			scanf("%d%d",&I[i].x,&I[i].y);//�������� 
		}
	sort(I,I+n,cmp);//����������
	//ans��¼���ཻ���������lastX��¼��һ����ѡ���������˵�
	int ans=1,lastX=I[0].x;
	for(int i=1;i<n;i++){
		if(I[i].y<=lastX){//���Ҷ˵���lastX����ߣ�û���ཻ 
			lastX=I[i].x;//��i��Ϊ��ѡ������ 
			ans++; 
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
} 
