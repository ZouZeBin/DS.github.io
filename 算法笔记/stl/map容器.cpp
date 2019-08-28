#include<cstdio>
#include<map>
using namespace std;
int main(){
	map<char,int> mp;
	mp['c']=20;
	printf("%d\n",mp['c']);
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
		printf("%c %d\n",it->first,it->second);
	}
	mp['c']=34;
	map<char,int>::iterator it=mp.find('c');
		printf("%c %d\n",it->first,it->second);
	//erease()  size() clear() ‘≠¿Ì¿‡À∆
	 
	return 0;
} 
