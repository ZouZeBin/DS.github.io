#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main(){
	fstream outfile;//��������ļ���
	outfile.open("text.txt",ios::out);//ָ���ļ���ģʽ
	if(!outfile){
		cout<<"text.txt�ļ����ܴ�"<<endl;
		abort();//���ɹ��򿪣�д������ 
	} 
	outfile<<"д���ļ�text.txt������"<<endl;//��һ���ַ���д���ļ���
	outfile.close(); //������ofile�뿪����������ʱ������ 
	return 0;
} 
