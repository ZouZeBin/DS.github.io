#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
struct student{
	int no;
	char name[10];
	double degree;
};

struct student stud[3]={1,"����",95.5,16 ,"���ǿ",88,8,"�����",78 };
int main(){
	fstream infile,outfile;
	//������д��data.dat 
	outfile.open("data.dat",ios::out|ios::binary);
	if(!outfile){
		cout<<"�ļ����ܴ�"<<endl;
		abort(); 
	}
	for(int i=0;i<3;i++){
		outfile.write((char*)&stud[i],sizeof(stud[i]));
	}
	outfile.close();
	//��д�����ݶ�ȡ��ʾ���� 
	infile.open("data.dat",ios::out|ios::binary);
	if(!infile){
		cout<<"�ļ����ܴ�"<<endl;
		abort(); 
	}
	for(int i=0;i<3;i++){
		infile.read((char*)&stud[i],sizeof(stud[i]));
		cout<<stud[i].no<<"\t"<<stud[i].name<<"\t"<<stud[i].degree<<endl;
	}
	infile.close();
	return 0;
}
