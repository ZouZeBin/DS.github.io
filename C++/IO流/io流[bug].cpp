#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void disp(fstream ,int );
int main(){
	int i;
	fstream file;
	file.open("data1.dat",ios::in|ios::out|ios::binary);
	if(!file){
		cout<<"data1.dat不能打开"<<endl;
		abort();
	}
	for(i=1;i<=20;i++){
		file.write((char*)&i,sizeof(int));
	}
	long pos=file.tellp();//tellp成员函数返回当前文件读指针的位置，这个值是streampos类型的，定义在iostream中
	cout<<"当前字节编号："<<pos<<endl;
	disp(file,1);
	disp(file,30);
	file.close(); 
	return 0;
}
void disp(fstream file,int i){
	int j;
	file.seekp((i-1)*4,ios::beg);//从3开始,将指针向后偏移(i-1)*4位
								//报错，不知道什么原因
								 
	file.read((char*)&j,sizeof(int));
	if(file.eof()) 
		cout<<"提取数据错误"<<endl;
	else
		cout<<"第"<<i<<"个数据："<<j<<endl; 
}
