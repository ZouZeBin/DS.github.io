#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main(){
	fstream outfile;//建立输出文件流
	outfile.open("text.txt",ios::out);//指定文件打开模式
	if(!outfile){
		cout<<"text.txt文件不能打开"<<endl;
		abort();//若成功打开，写入内容 
	} 
	outfile<<"写入文件text.txt的内容"<<endl;//将一个字符串写入文件中
	outfile.close(); //当对象ofile离开它的作用域时便消亡 
	return 0;
} 
