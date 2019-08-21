#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//判断读入一个以@为结尾的回文 
int main(){
	stack<char> s;
	vector<char> v;
	char c;
	cin>>c;
	while(c!='@'){
		v.push_back(c);
		cin>>c;
	}
	for(int i=0;i<v.size();++i){
		s.push(v[i]);
	}
	for(int j=0;j<v.size();++j){
		char c=s.top();
		s.pop();
		if(c!=v[j]){
			cout<<"no"<<endl;
			return -1;
		}
	}
	cout<<"yes"<<endl;
	return 0;
} 
