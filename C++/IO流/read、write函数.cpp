#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
struct student{
	int no;
	char name[10];
	double degree;
};

struct student stud[3]={1,"王华",95.5,16 ,"李国强",88,8,"孙悟空",78 };
int main(){
	fstream infile,outfile;
	//将数据写入data.dat 
	outfile.open("data.dat",ios::out|ios::binary);
	if(!outfile){
		cout<<"文件不能打开"<<endl;
		abort(); 
	}
	for(int i=0;i<3;i++){
		outfile.write((char*)&stud[i],sizeof(stud[i]));
	}
	outfile.close();
	//将写入数据读取显示出来 
	infile.open("data.dat",ios::out|ios::binary);
	if(!infile){
		cout<<"文件不能打开"<<endl;
		abort(); 
	}
	for(int i=0;i<3;i++){
		infile.read((char*)&stud[i],sizeof(stud[i]));
		cout<<stud[i].no<<"\t"<<stud[i].name<<"\t"<<stud[i].degree<<endl;
	}
	infile.close();
	return 0;
}
