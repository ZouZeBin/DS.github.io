#include<iostream>
#include<string>
using namespace std;
int main(){
	string str="hello zzb!";
/*		
	//ͨ���±���� 
	for(int i=0;i<str.length();i++){
		printf("%c",str[i]);
	}
	//�����ַ���ֻ��cin cout
	//string str1;
	//cin>>str1;
	//cout<<str1; 
	
	//printf���string
	printf("%s\n",str.c_str());//��string��strʹ��c_str()��Ϊ�ַ�����
*/	
	///����������
	for(string::iterator it=str.begin();it!=str.end();it++){
		printf("%c",*it);
	} 
	
	//�ַ���ƴ�� +
	//�ַ����Ƚϴ�С > < ...�ֵ���
	//str.insert() ����
	//str.erase()
	//str.clear()
	
	//�����Ӵ�
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
