/*16�㷨ʵ���� 6.3 ���͹ܵ�����
�� ����������
 ĳʯ�͹�˾�ƻ�����һ���ɶ������������͹ܵ��� 
 �ùܵ�Ҫ����һ���� n ���;������ 
 ��ÿ���;���Ҫ��һ�����͹ܵ������·�������ϻ򱱣� �����ܵ������� 
 �������n���;���λ�ã� �����ǵ� x ���꣨������ �� y ���꣨�ϱ��򣩣� 
 Ӧ���ȷ�����ܵ�������λ�ã� ʹ���;������ܵ�֮������͹ܵ������ܺ���С�� 
 ֤����������ʱ����ȷ�����ܵ�������λ�á�
 
�� ʵ������
 ���� n ���;���λ�ã� ������;������ܵ�֮������͹ܵ���С�����ܺ͡�

�� �������룺
 ���ļ� input.txt �����������ݡ� 
 �ļ��ĵ� 1 �����;��� n��n<10000���� ������ n �����;���λ�á� 
 ÿ�� 2 ������ x �� y��-10000<x,y<10000����
 
�� ��������
 ��������������ļ� output.txt �С� 
 �ļ���һ���е���ʮ�;������ܵ�֮�����С�����ܺ͡�
������ת��Ϊ�� n �ԺͲ��ȵ����ݰ���С��������λ�� k �����⣩
Դ�������£�
1�� ���͹ܵ�.cpp*/ 
// ���͹ܵ�����.cpp : Defines the entry point for the console application.
//TransportOil.cpp
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct Point
{ 
	double x;
	double y;
};

void Insert_Sort(Point *p, int left, int right)//�������� 
{ 
	Point temp;
	for(int i=left+1; i<=right; i++)
	{ 
		temp=p[i];
		for(int j=i-1; j >=left; j--)
		{
			if(p[j].y > temp.y)
				p[j+1]=p[j];
			else break;
		}
		p[j+1] = temp;
	}	
}

//�Ľ��Ŀ�������
void Quick_Sort(Point *p, int left, int right)
{ 
	Point temp;
	int partition;
	int i=left, j=right;
	if((right - left) < 5)
	{ 
		Insert_Sort(p, left, right);
		return;
	}/**��������Ԫ�صĸ���С�� 5 ����ʱ�� �͵��ò�����������������ٶ�*/
	partition=(right-left)/2;
	while(i<j)
	{ 
		do{
			i++;
		}while(p[i].y < p[partition].y);
		do{
			j--;
		}while(p[j].y > p[partition].y);
		if(i<j)//����������н���
		{ 
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
	}
	Quick_Sort(p, left, j);
	Quick_Sort(p, j+1, right);
}

int main(int argc, char* argv[])
{
	int n, y, m, i=1;
	cout<<"�������;��ĸ���: ";
	cin>>n;
	m=n;
	Point *p =new Point[n];
	while(n)
	{ 
		cin>>p[i].x>>p[i].y;
		n--;
		i++;
	} //�Ե� p[]���������������
	Quick_Sort(p, 1, m);
	int sum = 0;
	for(i = 1; i <= m/2; i++)
	sum += fabs(p[m-i+1].y - p[i].y); //������ҵ���λ�� k
	y = p[(m+1)/2].y;
	cout<<sum<<endl;	
	system("pause");
	return 0;
}

