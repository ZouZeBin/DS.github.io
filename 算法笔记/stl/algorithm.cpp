#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;//a>b时把a放b前面 
}
//结构体数组排序
struct node{
	int x,y;
}ssd[10];

//bool cmp(node a,node b){
//	return a.x>b.x;//从大到小排 
//} 
//
//bool cmp(node a,node b){
//	if(a.x!=b.x)
//		return a.x>b.x;//如果不相等按x从大到小排
//	else				//如果相等按y从小到大排 
//		return a.y<b.y; 
//} 
int main(){
	int x=1,y=-2;
//	printf("%d %d\n",max(x,y),min(x,y));
//	printf("%d %d\n",abs(x),abs(y));
//	swap(x,y);
//	cout<<x<<" "<<y<<endl;
	int a[10]={1,12,3,45,5};
//	reverse(a,a+2);//a[0]-a[1]反转
//	for(int i=0;i<5;i++){
//		cout<<a[i]<<" ";
//	}
//	string str="abxdddssw";
//	reverse(str.begin()+2,str.begin()+6);//对str[2]-str[5]反转
//	for(int i=0;i<str.length();i++){
//		cout<<str[i]<<" ";
//	}

//} 

//fill赋相同的值 
//fill(a,a+2,6);
//	for(int i=0;i<5;i++){
//		cout<<a[i]<<" ";
//	}
//	

//sort()函数 排序 
//sort(a,a+4);//a[0]-a[3]从小到大排序 
//for(int i=0;i<5;i++){
//	cout<<a[i]<<" ";
//}

//比较函数cmp
//
//	sort(a,a+5,cmp); 
//	for(int i=0;i<5;i++){
//		cout<<a[i]<<" ";
//	} 

//结构体数组排序
//	ssd[0].x=2;//{2,2}
//	ssd[0].y=2;
//	ssd[1].x=1;//{1,3}
//	ssd[1].y=3;
//	ssd[2].x=3;//{3,1}
//	ssd[2].y=1;
//	ssd[3].x=3;//{3,2}
//	ssd[3].y=2;
//	sort(ssd,ssd+4,cmp);
//	for(int i=0;i<4;i++){
//		cout<<ssd[i].x<<" "<<ssd[i].y<<endl;
//	} 
	
//容器的排序
//	vector<int> vi;
//	vi.push_back(3);
//	vi.push_back(1);
//	vi.push_back(2);
//	sort(vi.begin(),vi.end(),cmp);//对整个vector排序
//	for(int i=0;i<3;i++){
//		cout<<vi[i]<<endl;
//	}  
	
	return 0;
} 
