#include<iostream>
#include<cstring>
using namespace std;
class A{
	char *p;
	int size;
	public:
		A(){}//Ĭ�Ϲ��캯��
		
		A(char a[],int n){//���ع��캯��
			p=new char[n+1];//����n+1���ռ�
			strcpy(p,a);//�����ַ���
			size=n; 
		}
		
		~A(){//�������� 
			delete [] p;
		}
		
		/*A Copy(A &c){ ������������*/  
		A&Copy(A &c){//���� ����û�в������ã��ﲻ��ϣ��Ч��������������
					//�ĳ�Copy��Ա���������ã�a1�ͷ��ع���ͬһ�ڴ�ռ� 
			this->p=new char[c.size+1];
			strcpy(this->p,c.p);
			this->size=c.size;
			return *this; //���ص�ǰ���󣬼��޸ĺ�Ķ������ԭ���� 
			//return c;
		} 
		
		void disp(){//���p 
			cout<<p<<endl;
		} 
		
};
int main(){
	A a("ZZB",3),a1;
	cout<<"a:";
	a.disp();
	a1.Copy(a);
	cout<<"a1:";
	a1.disp();
	return 0;
} 
