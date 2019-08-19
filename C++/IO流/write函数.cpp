#include<fstream>
using namespace std;
struct Data{
	int mo,da,yr;
}; 
int main(){
	Data dt={2,20,2001};
	ofstream myfile("text.dat",ios::binary);//建立输出文件并指定文件打开模式
	myfile.write((char*)&dt,sizeof dt);//文件中写入数据块 二进制数，因此打开是乱码 
	return 0;
}
