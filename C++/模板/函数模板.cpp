#include<iostream>
using namespace std;
template <class T>//ģ�庯����˵�����������ȫ��������  
T min1(T x,T y){
	if(x<y)
		return x;
	return y; 
} 
int main(){
	int n1=2,n2=10;
	double a1=2.4,a2=4.3;
	cout<<"��С����(2��10):"<<min1(n1,n2)<<endl;//��min�ᱨ�������ɵ��ÿ����min���� 
	cout<<"��СС��(2.4��4.3):"<<min1(a1,a2)<<endl; 
	/* 
	cout<<min1(n1,a2); //ģ�����Ͳ�������ʽ����ת��,��������Ӧ�ñ���һ�µ�����
				//����� 
	*/ 
	return 0;
}
