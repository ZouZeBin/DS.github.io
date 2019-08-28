#include<iostream>
#include<string>
using namespace std;
int main(){
	string str="hello zzb!";
/*		
	//通过下标访问 
	for(int i=0;i<str.length();i++){
		printf("%c",str[i]);
	}
	//读入字符串只能cin cout
	//string str1;
	//cin>>str1;
	//cout<<str1; 
	
	//printf输出string
	printf("%s\n",str.c_str());//将string型str使用c_str()变为字符数组
*/	
	///迭代器访问
	for(string::iterator it=str.begin();it!=str.end();it++){
		printf("%c",*it);
	} 
	
	//字符串拼接 +
	//字符串比较大小 > < ...字典序
	//str.insert() 插入
	//str.erase()
	//str.clear()
	
	//返回子串
	cout<<str.substr(1,3)<<endl; 
	//npos==-1 npos==4294967295
	string s="zzb!";
	string s1="7b!";
	cout<<str.find(s)<<endl;
	cout<<str.find(str,2);//
	cout<<str.find(s1);
	//replace(pos,len,str2)
	//replace(it1,it2,str2)
	string str1="ni hao";
	string str2="hahaha";
	cout<<str1.replace(str1.begin()+3,str1.begin()+6,str2)<<endl;
	cout<<str1.replace(3,5,str2);	 
	return 0;
} 
