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
		cout<<"data1.dat���ܴ�"<<endl;
		abort();
	}
	for(i=1;i<=20;i++){
		file.write((char*)&i,sizeof(int));
	}
	long pos=file.tellp();//tellp��Ա�������ص�ǰ�ļ���ָ���λ�ã����ֵ��streampos���͵ģ�������iostream��
	cout<<"��ǰ�ֽڱ�ţ�"<<pos<<endl;
	disp(file,1);
	disp(file,30);
	file.close(); 
	return 0;
}
void disp(fstream file,int i){
	int j;
	file.seekp((i-1)*4,ios::beg);//��3��ʼ,��ָ�����ƫ��(i-1)*4λ
								//������֪��ʲôԭ��
								 
	file.read((char*)&j,sizeof(int));
	if(file.eof()) 
		cout<<"��ȡ���ݴ���"<<endl;
	else
		cout<<"��"<<i<<"�����ݣ�"<<j<<endl; 
}
