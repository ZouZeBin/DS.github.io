/* 
12����� 2 ��ջʵ��һ�����е��㷨�� ��������������ļ���ʱ�临�Ӷȡ�
  ʵ������
���ڸ����Ķ����������У� �������� FIRST( ) ���㷵�صĽ����
 
  �������룺
���ļ� input.txt �����������ݡ� 
 �� 1 ���������� n�� ��ʾ�� n ���������㡣 
 ��������ÿ�и���һ���������㡣
���У� ENQUEUE x ��ʾΪ E x�� 
	   DEQUEUE(x)�����ʾΪ D�� 
	   FIRST( )  �����ʾΪ F��
 
  ��������
  
���������ݸ����Ķ��������� FIRST( )���㷵�صĽ������������ļ� output.txt��
3�� Input.txt
10
E 42
E 24
F
D
E 0
F
D
F
F
D
4�� Output.txt
42
24
0
0

Դ�������£�
1�� ˫ջ����.cpp*/ 
// ˫ջ����.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include "stdio.h"
#include "string.h"
//#include "�������.h"
#include "malloc.h"
#include "stdlib.h"


#include <stack>
typedef int SElemType;



Status visit(SElemType *E)
{ 
	printf("%d->",*E);
	return 0;
}
void save(int m)
{ 
	FILE *fp;
	if((fp=fopen("output.txt","a"))==NULL)
	{ 
		printf("cannot open file.\n");
		return;
	}
	
	fprintf(fp,"%d\n",m);
	fclose(fp);
}
int main()
{ 
	SqStack *SIn,*SOut;//����������ջģ����в����� һΪѹ�룬 һΪ����
	FILE *fp;
	char a[SIZE];
	int que,e,cnt;
	InitStack(&SIn);
	InitStack(&SOut);
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&cnt);
	printf("ϵͳ��һ����%d ������ڹ���\n",cnt);
	while(!feof(fp)) //ͨ���ַ����Ƚ�ȷ�����еĲ���
	{ 
		fscanf(fp,"%s",a);
		switch(a[0]){
						case 'E':
							printf("\n\n ��ǰ����Ϊ%s:����У� Ԫ��ֵ�� ",a);
							fscanf(fp,"%d",&que);
							printf("%d\n",que);
							while(!StackEmpty(*SOut))
							{ 
								Pop(SOut,&e);
								Push(SIn,e);
							} //��������Ԫ�ؽ��ӣ� ������ջ����Ԫ��������ѹ��ջ
							Push(SIn,que);//����ǰԪ�ؽ���
							while(!StackEmpty(*SIn))
							{ 
								Pop(SIn,&e);
								Push(SOut,e);
							}//������ѹ��ջԪ�����������뵯��ջ
							break;
					
						case 'D':
							printf("\n\n ��ǰ����Ϊ%s:�����У� Ԫ��ֵ�� ",a);
							Pop(SOut,&e);
							printf("%d\n",e);
							break;//���Ӳ����� ֱ�ӽ�����ջջ��Ԫ�س���
						
						case 'F':
							printf("\n\n ��ǰ����Ϊ%s:ȡ��ͷԪ�أ� ֵ�� ",a);
							e=GetTop(*SOut);
							printf("%d\n",e);
							save(e);
							break;
			
						default:continue;
					}//ȡ�ö�ͷԪ��
		if(!StackEmpty(*SOut))
		{ 
			printf("��ǰ���й���״̬Ϊ�� \n");
			StackTraverse(*SOut,visit);
		}
		else printf("��ǰ����Ϊ��!\n");
	}//���еı���
	fclose(fp);
	DestroyStack(SIn);
	DestroyStack(SOut);
	getchar();
	return 0;
}



