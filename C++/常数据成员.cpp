#include<iostream>
using namespace std;
class A{
	const int n;//�����ݳ�Ա
	public:
		A(int i,int j):n(i+j){}//���캯����ʼ���б�
		void print(){
			cout<<"n="<<n<<endl;
		} 
};
int main(){
	A a(10,11);
	a.print();
	return 0;
} 
