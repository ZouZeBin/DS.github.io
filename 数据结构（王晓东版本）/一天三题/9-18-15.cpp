/*15�㷨ʵ���� 6.2 DNA ��������
  ����������
���ڸ�����ȫ��������Ԫ������ A={a1�� a2�� ������ an}�� 
A ���������̻������е�������̶ȡ� 
������ԽС�� ���� A ��������̶�Խ�ߡ�
������Ϣѧ���ڽ��з��Ӽ����о� DNA ����ʱ�� ��Ҫ�����ɳ�����ͬ�� DNA ��������������С�������� 
DNA �����������Ҫ�Ը����ĳ�����ͬ�� DNA ��������������

  ʵ������
���ڸ����ĳ�����ͬ�� DNA ���� ������������С��������
  
  �������룺
���ļ� input.txt �����������ݡ� 
�������ݰ����������ݿ顣 
ÿ�����ݿ�ĵ� 1 ���� 2 �������� L �� n�� �ֱ��ʾ���ݿ��� DNA ���ĳ��Ⱥ͸����� 
������ n ���У� ÿ���� 1 ���ɴ�дӢ����ĸ A�� C�� G�� T ��ɵĳ���Ϊ L �� DNA ���� 
�ļ������ 2 �� 0 ������
  
  ��������
�������ݿ��е� DNA ��������������������ļ� output.txt �С� 
ÿ�����ݿ�֮����һ�����зָ���
Դ�������£�
1�� DNA ����.cpp*/ 
// DNA ����.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#define SIZE 50
char a[SIZE+1][SIZE+1];
typedef struct {
	int seq;
	int inv;
}pair;

pair t[SIZE+1];
int main()
{ 
	int len, N, i, j, k, p,cnt;
	pair temp;
	t[0].seq = 0;
	t[0].inv = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &len,&N);
	printf("%d,%d\n",len,N);
	for (i=1; i<=N; i++)
	{ 
		scanf("%s",a[i]);
		cnt = 0;
		for (j=len-1; j>=1; j--)
		{ 
			for (k=0; k<j; k++)
			{
				if (a[i][k]>a[i][j]) cnt++;
			}//�����ַ���������������
		}
		temp.seq = i;
		temp.inv = cnt;
		for (k=i-1;k>=0 && t[k].inv>temp.inv; k--) t[k+1] = t[k];
		t[k+1] = temp;
	}//�����������������ַ�������
	for (p=1; p<=N; p++)
	printf("%s\n\n", a[t[p].seq]);
	freopen("output.txt", "w", stdout);
	for (p=1; p<=N; p++)
	printf("%s\n\n", a[t[p].seq]);
	return 0;
}

