#include<fstream>
using namespace std;
struct Data{
	int mo,da,yr;
}; 
int main(){
	Data dt={2,20,2001};
	ofstream myfile("text.dat",ios::binary);//��������ļ���ָ���ļ���ģʽ
	myfile.write((char*)&dt,sizeof dt);//�ļ���д�����ݿ� ������������˴������� 
	return 0;
}
