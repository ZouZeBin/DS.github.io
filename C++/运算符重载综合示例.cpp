#include<iostream>
using namespace std;
const int MaxSize=100;//���������Ԫ�ظ��� 
class Set{//������Set 
	int *data;//��ż����е�Ԫ�� 
	int n;//������Ԫ�ظ���
	public:
		
		Set(){//���캯�� 
			data=new int [MaxSize];//��̬����ռ� 
			n=0; 
		}
		 
		~Set(){//�������� 
			delete []data;
		} 
		
		bool IsIn(int e){//�ж�e�Ƿ��ڼ����� 
			int i;
			for(int i=0;i<n;i++)
				if(data[i]==e)
					return true;//��data�������ҵ�Ԫ��e����true 
				return false; //��data������û���ҵ�e����false 
		}
		
		bool Insert(int e){//��Ԫ��e���뵽���ϵ���ȥ
			if(IsIn(e)) //���Ҫ�����e�Ѿ��ڼ��ϵ��д��ڣ�����false������ʧ�� 
				return false;
			else{//��������в�����e��������±�Ϊn��λ�ã����鳤��++������true 
				data[n]=e;
				n++;
				return true;
			}
		}
		
		bool Remove(int e){//��Ԫ��e�Ӽ�����ɾ�� 
			int i=0,j;
			while(i<n&&data[i]!=e){//���Ҽ�����e���ڵ������±� 
				i++;
			} 
			if(i>=n) return false;//����ʧ��
			for(j=i+1;j<n;j++)
				data[j-1]=data[j];//����ɾ��Ԫ�غ��������Ԫ����ǰ�ƶ�һ��λ�� 
			n--;//�ɹ�ɾ�������鳤��--
			return true;//����true 
		} 
		
		void display(){//��������е�Ԫ�� 
			int i;
			for(i=0;i<n;i++){
				cout<<data[i]<<" ";
			} 
			cout<<endl;
		} 
		
		Set &operator=(Set &s1){//�����=���س�Ա���� 
			int i;
			for(i=0;i<s1.n;i++){
				data[i]=s1.data[i];
			}
			n=s1.n;
			return *this;
		}
		
		friend Set&operator+(Set &s1,Set &s2){//�󲢼� 
			int i;
			static Set s3;
			for(i=0;i<s1.n;i++)//��s1�������������Ԫ�ظ��Ƶ�s3�� 
				s3.Insert(s1.data[i]);
			for(i=0;i<s2.n;i++){//��s2��������s1�в����ڵ�Ԫ�ظ��Ƶ�s3�� 
				if(!(s1.IsIn(s2.data[i])))
					s3.Insert(s2.data[i]);
			} 
			return s3;//���غϲ���ļ��� 
		} 
		
		friend Set &operator*(Set &s1,Set &s2){//�󽻼� 
			int i;
			static Set s3;
			for(i=0;i<s1.n;i++)//������s1�г�����s2��Ԫ�ظ��Ƶ�s3
				if(s2.IsIn(s1.data[i]))
					s3.Insert(s1.data[i]);
			return s3;//���ؽ��� 
		}
		
		friend Set&operator-(Set &s1,Set &s2){//�� 
			int i;
			static Set s3;
			for(int i=0;i<s1.n;i++)//������s1��������s2�е�Ԫ�ظ��Ƶ�s3
				if(!s2.IsIn(s1.data[i]))
					s3.Insert(s1.data[i]);
			return s3;//���ز	
		} 
		
};
int main(){
	Set s1,s2,s3,s4,s5;//����Set���������
	s1.Insert(1);
	s1.Insert(2);
	s1.Insert(4);
	s1.Insert(6);
	s1.Insert(8);
	cout<<"����s1:";//����s1�в��� 1 2 4 6 8 
	s1.display();//��ӡ����s1
	s2.Insert(2);
	s2.Insert(3);
	s2.Insert(5);
	s2.Insert(6);
	cout<<"����s2:";//����s2�в���2 3 5 6
	s2.display();//��ӡ����s2
	cout<<"�󼯺�s1��s2�Ĳ���s3:"<<" ";
	s3=s1+s2;
	s3.display();
	cout<<"�󼯺�s1��s2�Ľ���s4:"<<" ";
	s4=s1*s2;
	s4.display();
	cout<<"�󼯺�s1��s2�Ĳs5:"<<" ";
	s5=s1-s2;
	s5.display();
	return 0;
} 
