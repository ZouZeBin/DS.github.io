#include<cstdio>
#include<set>
using namespace std;
int main(){
	set<int> st;
	st.insert(3);//��3���뼯��
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		//printf("%d",*it);
	} 
	printf("%d",*st.find(2));
	//����erase() size() clear() ��vector���� 
	return 0;
} 
