/*(2018���ִ�ѧ941)һ������Ϊ n �������ɸ�����0��������ɡ�
��д������������������Ϊǰ�ζ��Ǹ�������ξ�Ϊ�Ǹ����Ľṹ��
Ҫ��ʱ�临�Ӷ�Ϊ O(n)��  
���ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��*/ 

/*��һ����д���㷨˼· 
	ʹ������ָ�룬�ֱ�ָ��˳����ͷ��β
	��ǰ�������˳���
	������ýڵ�Ϊ���� ������ͷָ�뽻����ͷָ��ָ����һ���ڵ㣬�ӽ����ĺ�һ���ڵ㿪ʼ����
		  �ýڵ�Ϊ0��ʲô������
		  �ýڵ�Ϊ������������βָ�뽻����βָ��ָ��ǰһ�ڵ㣬�ӽ���ǰ�Ľڵ�ָ�봦��ʼ����
		  ��ֹ��������Ԫ�ظ����������鳤��ʱ������ѭ��*/

#include<iostream>
using namespace std;

void sort(int A[],int length){//���룺����A[],���鳤��length 
	int head,rear,count;//ͷβָ�� countΪ����Ƚϵ�Ԫ�ظ���
	head=0;count=0; 
	rear=length-1;//��ʼ��
	for(int i=head;count<length;){//��ֹ���� 
		if(A[i]>0){//����ýڵ�Ϊ������������βָ�뽻��
			int temp;
			temp=A[i];
			A[i]=A[rear];
			A[rear]=temp; 
			rear--;
			count++;//������һ 
		}
		if(A[i]==0){//����ýڵ�Ϊ0��ʲô���������������� 
			i++;
			count++;
		}
		if(A[i]<0){//����ڵ�Ϊ������������ͷָ�뽻�� 
			int temp;
			temp=A[i];
			A[i]=A[head];
			A[head]=temp; 
			head++;
			i++;
			count++;//������һ 
		} 
		 
	} 
}
int print(int A[],int length){
	int n=length;
	for(int i=0;i<n;i++){
		cout<<i<<':'<<A[i]<<endl;
	}
}
int main(){
	int A[]={1,-2,-3,4,0,-1,2,3,5,-2};
	int length=10;
	sort(A,length);
	print(A,length);
	return 0;
} 
