/*�������⾫ѡ����������һ���������ܵ� huster��
   ÿ������ܼ۸�һ����prices[i]���������ڵ� i ��ļ� ��
   ��ֻ��һ�ν���(���� 1 ֻ������ 1 ֻ)�ܵõ����������
   �����������������֮����� �����ܣ��� 


	ʱ�临�Ӷ�Ҫ��O��n�� 

	������int maxIncome��int prices[ ],int n�� 
	
	���� 
	i          4
	prices[i]  4 1 2 3
	���
	2 
	������
	��¼������Ԫ���е���Сֵmin�͵�ǰ���������ֵd,Ȼ�����������һ��Ԫ��
	�Ⱥ͵�ǰ��Сֵmin�������d�������ֵС��min�������min 
*/ 

#include<iostream>
using namespace std;
int maxIncome(int prices[],int n);
int main(){
	int prices[150],i,n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&prices[i]);
	}
	k=maxIncome(prices,n);
	printf("%d",k);
	return 0;
} 

int maxIncome(int prices[],int n ){
	int min,max,i,j;
	max=prices[n-1];
	min=prices[0];
	i=0;j=n-1;
	while(i<j){
		if(prices[i+1]<prices[i]){
			min=prices[i+1];
		}
		if(prices[j-1]>prices[j]){
			max=prices[j];
		}
		i++;
		j--;
	}
	return (max-min);
}
