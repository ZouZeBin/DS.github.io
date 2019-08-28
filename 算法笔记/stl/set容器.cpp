#include<cstdio>
#include<set>
using namespace std;
int main(){
	set<int> st;
	st.insert(3);//将3插入集合
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		//printf("%d",*it);
	} 
	printf("%d",*st.find(2));
	//还有erase() size() clear() 和vector类似 
	return 0;
} 
