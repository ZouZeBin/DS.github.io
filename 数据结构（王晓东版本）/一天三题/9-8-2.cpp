/*2�㷨ʵ���� 1.2 ��������������
 	����������
	�󲿷ֵ����������Ա�ʾΪ����������������֮�͡�
 
 	ʵ������
	��������������Ҫ�������������������Ա���Ϊ���ٸ��������ϵ���������֮�͡�

	�������룺
	���ļ� input.txt �����������ݡ� ��һ����һ����������
	
	��������
	�����������Ӧ�����������ֽ���������ļ� output.txt��
	ʵ��Դ���룺
	1�� ����������.cpp
 	����������.cpp : Defines the entry point for the console application.*/ 

//	#include "stdafx.h"
//	#include "�������.h"
	#include <stdio.h>
	int a[SIZE];
	int main()
	{ 
		int length=load(a);
		int i,count;
		for(i=0;i<length;i++)
		{ 
			count=0;
			printf("\n\n%d=\n", a[i]);
			for(int n1=1; n1<=a[i]/2; n1++)// n1 Ϊ�Ȳ����е�һ��
			{ 
				for(int n2=n1+1; n2<a[i]; n2++)// n2 Ϊ�Ȳ��������һ��
				{ 
					if((n1+n2)*(n2-n1+1) == a[i]*2)// �õȲ����й�ʽ���
					{ //�����Ⱦ�������
						for(int t=n1; t<n2; t++) printf("%d+", t);
						printf("%d\n", t);
						count++;
					}
				}
			}
			printf("����%d �ַֽⷽʽ\n", count);
			save(count);
		}
	}

