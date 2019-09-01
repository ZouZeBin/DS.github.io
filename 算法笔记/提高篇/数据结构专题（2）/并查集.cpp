#include<iostream>
using namespace std;
const int N=100;
//1����ʼ�� ÿ��Ԫ�ض���һ������ 
int father[N];
for(int i=1;i<=N;i++){
	father[i]=i;
} 

//2������
int findFather(int x){
	while(x!=father[x]){
		//������Ǹ��ڵ㣬����ѭ��
		x=father[x];//��ȡ�Լ��ĸ��׽ڵ� 
	}
	return x; 
}
//���߿����õݹ� 
int findFather2(int x){
	if(x==father[x]) return x;//�Ҳ������ڵ㷵�ظ��ڵ���x
	else return findFather2(father[x]);//�ݹ���� 
}

//3���ϲ�
void Union(int a,int b){
	int faA=findFather(a);//����a�ĸ��ڵ㣬��ΪfaA
	int faB=findFather(b);//����b�ĸ��ڵ㣬��ΪfaB
	if(faA!=faB){
		father[faA]=faB;//�ϲ� 
	} 
} 

//4��·��ѹ��
/*
	����1����ԭ�ȵ�д�����x�ĸ��ڵ�r
	����2�����´�x��ʼ��һ��Ѱ�Ҹ��ڵ�Ĺ��̣�
	       ��·���Ͼ��������нڵ�ĸ���ȫ����Ϊ���ڵ� 
*/ 
int findFather11(int x){
	//����x������while���ɸ��ڵ㣬�ȱ���һ��
	int a=x;
	while(x!=father[x]){
		//Ѱ�Ҹ��ڵ�
		x=father[x]; 
	} 
	//x��ŵ��Ǹ��ڵ㣬�����·���ϵ����нڵ��father���ĳɸ��ڵ�
	while(a!=father[a]){
		int z=a;//��ΪaҪ��father���ǣ������ȱ���a��ֵ�����޸�father[a]
		a=father[a];//a���ݸ��׽ڵ�
		father[z]=x; 
	} 
	return x;//���ظ��ڵ� 
}

//�ݹ�д��
int  findFather22(int v){
	if(v==father[v]) return v;//�ҵ����ڵ�
	else{
		int F=findFather22(father[v]);
		father[v]=F;//�����ڵ�F����father[v]
		return F;//���ظ��ڵ� 
	} 
} 



 

