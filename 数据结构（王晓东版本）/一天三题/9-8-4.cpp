/*�㷨ʵ���� 2.2 ����ͼ��������
 	����������
	�� x ����ˮƽ������ n ������ͼ������ͼ��������ȥ�� n ������ͼ�������ߺ�õ���ͼ
	�Ρ� ÿ������ͼ�� 3 Ԫ�飨Li�� Hi�� Ri�� ��ʾ��
	Li�� Ri �ֱ��ʾ����ͼ�������ߵ�x����ֵ��
	Hi Ϊ����ͼ�ĸ߶ȡ� 
	����ͼ������������������v1�� v2�� ����vm�� ��ʾ�� 
	
	�� i Ϊ����ʱ��vi ��ʾ����ͼ������һ�����ߵ� x ����ֵ�� 
	�� i Ϊż��ʱ��vi ��ʾ����ͼ������һ�����ߵĸ߶ȡ�
	
 	ʵ������
	���ڸ����� n ������ͼ�� ����������ͼ������
 
 	�������룺
	���ļ� input.txt �����������ݡ� 
	ÿ���� 3 ����������Li�� Hi�� Ri���� 
	Li�� Ri �ֱ��ʾ����ͼ�������ߵ� x ����ֵ�� Hi Ϊ����ͼ�ĸ߶ȡ�
 
 	��������
	�������������ͼ��������������ļ� output.txt��
	Դ�������£�
	1�� ����ͼ����.cpp*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LBound (-3000)//��߽� 
#define UBound 3000	//�ұ߽� 
#define Cod2Idx(x) ((x)-LBound)
#define Size Cod2Idx(UBound+1)//SIZE=UBound-LBound+1 ���
 
int main()
{
	int hs[Size], n;
	int i, l, r, h, i0, i1;
	memset(hs, 0, sizeof(*hs) * Size);
	//�ڴ������� ʹ��"0" ��� hs ��С�� SIZE ���ڴ浥Ԫ
	printf("��������ͼ�ĸ����� \n");
	scanf("%d", &n);
	for (i0=UBound, i1=LBound; n>0; n--)
	{ 
		printf("��������ͼ����߽�����ꡢ ����ͼ�ĸ߶ȡ� �ұ߽�����꣬ �Կո������ \n");
		scanf("%d %d %d", &l, &h, &r);
		if (l < i0) i0 = l;//�������ֵ������߽�ֵ�����丳ֵΪ��߽� 
		if (r > i1) i1 = r;//��������ұ߽磬���丳Ϊ�ұ߽� 
		for (i=l; i<r; i++)
			if (hs[Cod2Idx(i)] < h)//������ 
			hs[Cod2Idx(i)] = h;
	}
	printf("\n ���ߺ������ͼ�߽����£� \n");
	for (i=i0, h=0; i<i1; i++)
	if (hs[Cod2Idx(i)] != h)
		printf("%d %d ", i, h=hs[Cod2Idx(i)]);
	printf("%d %d\n", i, 0);
	return 0;
}

