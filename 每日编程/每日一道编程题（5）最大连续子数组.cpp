/*�������⾫ѡ���ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
	����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�

	����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
	��λСƤƤ��ʲô�õĽⷨ�أ�(�������ĳ���������1)
*/ 

#include<iostream>
using namespace std;


int FindGreatestSumOfSubArray (int array[],int size) {
	int max = 0, sum = 0;
	for(int i = 0; i < size; ++i) {
		sum += array[i];
		//�ۼ�
		if(sum > max)
			max = sum;
		//
		if(sum < 0) sum = 0;
		//��sumС��0ʱ���Ͳ�Ҫ�ڼ��������ۼ��ˣ���Ϊ����ֻ��Խ��ԽС��
	}
	return max;
}

int main(){
	int array[]={6,-3,-2,7,-15,1,2,2};
	int size=8;
	cout<<FindGreatestSumOfSubArray (array,size); 
	return 0;
}
 
