#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;//a>bʱ��a��bǰ�� 
}
//�ṹ����������
struct node{
	int x,y;
}ssd[10];

//bool cmp(node a,node b){
//	return a.x>b.x;//�Ӵ�С�� 
//} 
//
//bool cmp(node a,node b){
//	if(a.x!=b.x)
//		return a.x>b.x;//�������Ȱ�x�Ӵ�С��
//	else				//�����Ȱ�y��С������ 
//		return a.y<b.y; 
//} 
int main(){
	int x=1,y=-2;
//	printf("%d %d\n",max(x,y),min(x,y));
//	printf("%d %d\n",abs(x),abs(y));
//	swap(x,y);
//	cout<<x<<" "<<y<<endl;
	int a[10]={1,12,3,45,5};
//	reverse(a,a+2);//a[0]-a[1]��ת
//	for(int i=0;i<5;i++){
//		cout<<a[i]<<" ";
//	}
//	string str="abxdddssw";
//	reverse(str.begin()+2,str.begin()+6);//��str[2]-str[5]��ת
//	for(int i=0;i<str.length();i++){
//		cout<<str[i]<<" ";
//	}

//} 

//fill����ͬ��ֵ 
//fill(a,a+2,6);
//	for(int i=0;i<5;i++){
//		cout<<a[i]<<" ";
//	}
//	

//sort()���� ���� 
//sort(a,a+4);//a[0]-a[3]��С�������� 
//for(int i=0;i<5;i++){
//	cout<<a[i]<<" ";
//}

//�ȽϺ���cmp
//
//	sort(a,a+5,cmp); 
//	for(int i=0;i<5;i++){
//		cout<<a[i]<<" ";
//	} 

//�ṹ����������
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
	
//����������
//	vector<int> vi;
//	vi.push_back(3);
//	vi.push_back(1);
//	vi.push_back(2);
//	sort(vi.begin(),vi.end(),cmp);//������vector����
//	for(int i=0;i<3;i++){
//		cout<<vi[i]<<endl;
//	}  
	
	return 0;
} 
