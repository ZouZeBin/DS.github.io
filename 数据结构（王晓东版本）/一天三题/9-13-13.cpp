/*13�㷨ʵ���� 4.3 ���ӷ�������
     ����������
  ����԰��� n ֻ���ӱ��Ϊ 1�� 2�� ������ n�� 
  �����ų�һ�ӵȴ�����Ա��������Ҷ���԰�ķ���
  ������ÿֻ���ӿɷֵ� m �����ӣ� �������Ŷ���ȡ�� 
  ����Աѭ����ÿ��ȡ�� 1 ����2 ���� ������ k ����
  �ӷ����� �����ڶ��׵ĺ�����ȡ�� ȡ�����е���
  ����Ϊ k �� �����´� 1 ��ʼ�� �����е���������
  �϶��׺�����ȡ�õ������������� m ʱ�� ���׵ĺ���
  ����ȡ�ÿ������е�ȫ�����ӡ� ȡ�������������� m 
  ���ĺ��ӣ� ��������β�ŶӵȺ� �����е���������
  �϶��׺�����ȡ�õ����������� m ʱ�� ���׵ĺ���ֻ
  ��ȡ�� m ���� Ȼ���뿪���У�����ʣ�����������һ
  ֻ����ȡ�á� �������ҹ���һֱ���е�ÿֻ���Ӷ��ֵ� 
  m �����ӡ�
  
 	 ʵ������
  ���ڸ����� n�� k �� m�� ģ���������ӷ��ҹ��̡�
  
	 �������룺
	���ļ� input.txt �����������ݡ� �� 1 ���� 3 �������� n�� k �� m�� 
	�ֱ��ʾ�� n ֻ���ӣ�ÿ�����ȡ k ���ҵ����У� ÿֻ�������ն���
	�� m �����ӡ�
	
     ��������
	�����ҹ�����ÿֻ�����뿪���еĴ�������������ļ� output.txt��
	�����й涨��������ʣ������ʱ����Աֹͣ�����������ӣ� ֻ�е�
		���ѿ�ʱ�ſ��Լ������룩

Դ�������£�
1�� ���ӷ���.cpp�������У�*/ 
#include "stdafx.h"
#include"stdio.h"
#include"stdlib.h"
#include"�������.h"
#include"malloc.h"
typedef int QItem;
typedef struct monkey
{ 
	int id;
	int PMonkey;
}Mky,*mky;//ʹ�ýṹ�嶨����ӣ���ţ� ȡ�õ�����������

typedef Mky QElemType;
#include"Lqueue.h" //���������е�ͷ�ļ�
Status visit(QElemType E)//�����������
{ 
	printf(" ID:%d,%d->",E.id,E.PMonkey);
	return OK;
}

void main()
{ 
	Mky monkey,tmpMon;
	int n,k,m,t=0;
	int PPerson,PBox=0;//��������Ա�������������� �����д����������
	LinkQueue Q;
	InitQueue(Q);
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d",&n,&k,&m);
	printf("��������Ϊ%dֻ,\n ÿ�η��벻���� %d �����ӣ� \n ÿֻ������Ҫ�쵽 %d �����ӳ���\n",n,k,m);
	for(int i=1;i<=n;i++)
	{ 
		monkey.id=i;
		monkey.PMonkey=0;
		EnQueue(Q,monkey);
	}//�����Ӱ�����������

	QueueTraverse(Q,*visit); printf("\n");
	while(!QueueEmpty(Q))
	{ 
		if(PBox==0) //�涨��ǿ�������Ա����������
		{ 
			t++;//��¼ѭ������
			PPerson=((t%k)==0)? k:t%k;//������ȷ������Ա������е���������
			PBox+=PPerson;
		}//
		tmpMon=GetHead(Q);//��ͷ���ӳ�����ȡ����
		tmpMon.PMonkey+=PBox;
		if(tmpMon.PMonkey<m)
		{ 
			PBox=0;
			DeQueue(Q);
			EnQueue(Q,tmpMon);
		}//���ȡ�ÿ����������Ӻ� �Բ����� m ���� ��ص���β�����Ŷ�
		else {
				PBox=tmpMon.PMonkey-m;
				printf("\n ���Ӻ��ӵı��Ϊ�� %d\n\n",tmpMon.id);
				save(tmpMon.id);
				DeQueue(Q);
			}//��֮������ȡ�������� ��ú��ӳ��ӣ� ������������ӷŻؿ���
			printf("\n ��һʱ�̶���״̬Ϊ�� \n");
			QueueTraverse(Q,*visit);
			printf("\n\n");
	}
	if(QueueEmpty(Q))
	{
		printf("��ǰ����Ϊ�գ� ");
		DestroyQueue(Q);
	}
	system("pause");
}

//2�� �������.h
void save(int n)
{ 
	FILE *fp;
	int i;
	if((fp=fopen("output.txt","a"))==NULL)
	{ 
		printf("cannot open file.\n");
		return;
	}
	fprintf(fp,"%d ",n);
	fclose(fp);
}

//3�� ���ӷ���.cpp��ѭ������ʵ�֣�
#include "stdafx.h"
#include"stdio.h"
#include"stdlib.h"
#include"�������.h"
#include"malloc.h"
typedef struct monkey
{ 
	int id;
	int PMonkey;
}Mky,*mky;

typedef Mky QItem;
#include"Aqueue.h"
Status visit(QItem E)
{ 
	printf(" ID:%d,%d->",E.id,E.PMonkey);
	return OK;
}
void main()
{ 
	Mky monkey,tmpMon;
	int n,k,m,t=0;
	int PPerson,PBox=0;
	SqQueue Q;
	QueueInit(Q);
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d",&n,&k,&m);
	printf("��������Ϊ %d ֻ�� \n ÿ�η��벻���� %d �����ӣ� \n ÿֻ������Ҫ�쵽 %d �����ӳ���\n",n,k,m);
	for(int i=1;i<=n;i++)
	{ 
		monkey.id=i;
		monkey.PMonkey=0;
		EnQueue(Q,monkey);
	}
	while(!QueueEmpty(Q))
	{ 
		if(PBox==0)
		{
			t++;
			PPerson=((t%k)==0)? k:t%k;
			PBox+=PPerson;
		}
		tmpMon= QueueFirst(Q);
		tmpMon.PMonkey+=PBox;
		if(tmpMon.PMonkey<m)
		{ 
			PBox=0;
			DeQueue(Q);
			EnQueue(Q,tmpMon);
		}
		else
		{ 
			PBox=tmpMon.PMonkey-m;
			printf("\n ���Ӻ��ӵı��Ϊ�� %d\n\n",tmpMon.id);
			save(tmpMon.id);
			DeQueue(Q);
		}
		printf("\n ��һʱ�̶���״̬Ϊ�� \n");
		QueueTraverse(Q,*visit);
		printf("\n\n");
	}
	if(QueueEmpty(Q)) printf("��ǰ����Ϊ�գ� \n\n");
}

