#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	pair<string,int> p;
	//��1 
	p.first="haha";
	p.second=5;
	cout<<p.first<<" "<<p.second<<endl;
	//��2 
	p=make_pair("xixi",55);
	cout<<p.first<<" "<<p.second<<endl;
	//��3 
	p=pair<string,int>("heihei",555);
	cout<<p.first<<" "<<p.second<<endl;
	//�Ƚϴ�С ��first ��ͬ��second 
	pair<int,int> p1(5,10);
	pair<int,int> p2(2,10);
	pair<int,int> p3(5,11);
	if(p1>p2){
		cout<<"p1>p2"<<endl;
	}
	if(p1<p3){
		cout<<"p1<p3"<<endl;
	}
	return 0;
}
