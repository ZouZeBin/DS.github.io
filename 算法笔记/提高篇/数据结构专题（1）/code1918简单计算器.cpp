/*��Ŀ����
	����һ��ֻ���� +, -, *, / �ķǸ�����������ʽ������ñ��ʽ��ֵ��

����
	��������������ɲ���������ÿ����������ռһ�У�ÿ�в�����200���ַ���
	�����������֮����һ���ո�ָ���û�зǷ����ʽ��
	��һ����ֻ��0ʱ�����������Ӧ�Ľ����Ҫ�����

���
	��ÿ�������������1�У����ñ��ʽ��ֵ����ȷ��С�����2λ��

��������
	30 / 90 - 26 + 97 - 5 - 6 - 13 / 88 * 6 + 51 / 29 + 79 * 87 + 57 * 92
	0
�������
12178.21
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node{
	double num;//������
	char op;//������
	bool flag;//true��ʾ��������false��ʾ������ 
};

string str;
stack<node> s;//������ջ
queue<node> q;//��׺���ʽ����
map<char,int> op;

//��׺ת��׺
void change(){
	double num;
	node temp;
	for(int i=0;i<str.length();){
		if(str[i]>='0'&&str[i]<='9'){//��������� 
			temp.flag=true;//���Ϊ����λ 
			temp.num=str[i++]-'0';//��¼�������ĵ�һ����λ
			while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
				temp.num=temp.num*10+(str[i]-'0');//�����������������¸ò�����
				i++; 
			} 
			q.push(temp);//�����º�������������������׺������ 
		}else{//����ǲ����� 
			temp.flag=false;//���Ϊ������
			//ֻҪ������ջ�����ȼ��ȸò��������ȼ���
			//�Ѳ�������ջ��������׺���ʽ�Ķ�����
			while(!s.empty()&&op[str[i]]<=op[s.top().op]){
				q.push(s.top());//��ջ��������������� 
				s.pop();//��ջ��Ԫ�ص��� 
			}
			temp.op=str[i];
			s.push(temp);//�Ѹò�����ѹ�������ջ��
			i++; 
		} 
	}
	//���������ջ���в��������Ͱ�����������׺���ʽ���е���
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	} 	
} 

//�����׺���ʽ
double Cal(){
    double temp1,temp2;
	node cur,temp;
	while(!q.empty()){//ֻҪ��׺����б�ǿ� 
		cur=q.front();//cur��¼����Ԫ��
		q.pop();
		if(cur.flag==true) s.push(cur);//����ǲ�����ֱ��ѹ��ջ
		else{//����ǲ�����
			temp2=s.top().num;//�����ڶ��������� 
			s.pop();
			temp1=s.top().num;//������һ��������
			s.pop();
			temp.flag=true;//��¼��ʱ������
			if(cur.op=='+') temp.num=temp1+temp2;//�� 
			else if(cur.op=='-') temp.num=temp1-temp2;//�� 
			else if(cur.op=='*') temp.num=temp1*temp2;//�� 
			else temp.num=temp1/temp2;//�� 
			s.push(temp);//����������ջ 
		} 
	}
	return s.top().num;//ջ�����Ǻ�׺���ʽ��ֵ 
} 

//������ 
int main(){
	op['+']=op['-']=1;//�������������ȼ�
	op['*']=op['/']=2;
	while(getline(cin,str),str!="0"){//0 ���� 
		for(string::iterator it=str.end();it!=str.begin();it--){
			if(*it==' ') str.erase(it);//���ո�ȥ�� 
		}
		while(!s.empty()) s.pop();//��ʼ��ջ 
		change();//��׺ת��׺
		printf("%.2f\n",Cal());//�����׺���ʽ 
	} 
	return 0; 
} 





