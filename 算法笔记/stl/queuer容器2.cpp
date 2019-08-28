#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct fruit{
	string name;
	int price;
}f1,f2,f3;
struct cmp{
	bool operator()(fruit f1,fruit f2){
		return f1.price > f2.price;
	}
};
int main(){
	priority_queue<fruit,vector<fruit>,cmp> q;
	f1.name="Æ»¹û";
	f1.price=12;
	f2.name="Àæ×Ó";
	f2.price=3;
	q.push(f1);
	q.push(f2);
	cout<<q.top().name<<" "<<q.top().price<<endl;
	return 0; 
}
