#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int> st;
	for(int i=1;i<=5;i++){
		st.push(i);//push(i)ѹջ 
	}
	st.pop();
	printf("%d %d",st.top(),st.size());//ջ��Ԫ�� 
	return 0;
} 
