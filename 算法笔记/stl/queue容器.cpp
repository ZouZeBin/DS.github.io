#include<iostream>
#include<queue>
using namespace std;
//�ṹ�����ȼ�����
struct fruit{
	string name;
	int price;
	friend bool operator<(fruit f1,fruit f2){//��sort��cmpЧ���෴ 
		return f1.price>f2.price;
	}
}f1,f2,f3; 

int main(){
//	queue<int> q;
//	for(int i=1;i<=5;i++){
//		q.push(i);
//	}
//	q.pop();
//	printf("%d %d [%d]",q.front(),q.back(),q.size());
//	if(!q.empty()){
//		printf("no null!");
//	}
	
	//���ȶ���
/*	priority_queue<int> q;//priority_queue<int,vector<int>,greater<int>> q;
	q.push(3);
	q.push(5);
	q.push(1);
	printf("%d",q.top()); //���5 //���1 
*/	
	priority_queue<fruit> q;
	f1.name="����";
	f1.price=3;
	f2.name="ƻ��";
	f2.price=12;
	q.push(f1);
	q.push(f2);
	cout<<q.top().name<<" "<<q.top().price<<endl;
	
	return 0; 
}
