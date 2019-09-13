/*13算法实验题 4.3 猴子分桃问题
     问题描述：
  动物园里的 n 只猴子编号为 1， 2， ……， n， 
  依次排成一队等待饲养员按规则分桃动物园的分桃
  规则是每只猴子可分得 m 个桃子， 但必须排队领取。 
  饲养员循环的每次取出 1 个，2 个， ……， k 个桃
  子放入筐里， 由排在队首的猴子领取。 取到筐中的桃
  子数为 k 后， 又重新从 1 开始。 当筐中的桃子数加
  上队首猴子已取得的桃子数不超过 m 时， 队首的猴子
  可以取得筐中现有的全部桃子。 取得桃子总数不足 m 
  个的猴子， 继续到队尾排队等候。 当筐中的桃子数加
  上队首猴子已取得的桃子数超过 m 时， 队首的猴子只
  能取满 m 个， 然后离开队列，筐中剩余的桃子由下一
  只猴子取用。 上述分桃过程一直进行到每只猴子都分到 
  m 个桃子。
  
 	 实验任务：
  对于给定的 n、 k 和 m， 模拟上述猴子分桃过程。
  
	 数据输入：
	由文件 input.txt 给出输入数据。 第 1 行是 3 个正整数 n、 k 和 m， 
	分别表示有 n 只猴子，每次最多取 k 个桃到筐中， 每只猴子最终都分
	到 m 个桃子。
	
     结果输出：
	将分桃过程中每只猴子离开队列的次序依次输出到文件 output.txt。
	（自行规定筐中尚有剩余桃子时饲养员停止继续放入桃子， 只有当
		筐已空时才可以继续放入）

源程序如下：
1、 猴子分桃.cpp（链队列）*/ 
#include "stdafx.h"
#include"stdio.h"
#include"stdlib.h"
#include"输入输出.h"
#include"malloc.h"
typedef int QItem;
typedef struct monkey
{ 
	int id;
	int PMonkey;
}Mky,*mky;//使用结构体定义猴子（编号， 取得的桃子数量）

typedef Mky QElemType;
#include"Lqueue.h" //加载链队列的头文件
Status visit(QElemType E)//定义遍历函数
{ 
	printf(" ID:%d,%d->",E.id,E.PMonkey);
	return OK;
}

void main()
{ 
	Mky monkey,tmpMon;
	int n,k,m,t=0;
	int PPerson,PBox=0;//定义饲养员放入桃子数量， 筐中尚存的桃子数量
	LinkQueue Q;
	InitQueue(Q);
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d",&n,&k,&m);
	printf("猴子数量为%d只,\n 每次放入不超过 %d 个桃子， \n 每只猴子需要领到 %d 个桃子出队\n",n,k,m);
	for(int i=1;i<=n;i++)
	{ 
		monkey.id=i;
		monkey.PMonkey=0;
		EnQueue(Q,monkey);
	}//将猴子按编号排序入队

	QueueTraverse(Q,*visit); printf("\n");
	while(!QueueEmpty(Q))
	{ 
		if(PBox==0) //规定筐非空则饲养员不放入桃子
		{ 
			t++;//记录循环次数
			PPerson=((t%k)==0)? k:t%k;//按次数确定饲养员放入筐中的桃子数量
			PBox+=PPerson;
		}//
		tmpMon=GetHead(Q);//队头猴子出队领取桃子
		tmpMon.PMonkey+=PBox;
		if(tmpMon.PMonkey<m)
		{ 
			PBox=0;
			DeQueue(Q);
			EnQueue(Q,tmpMon);
		}//如果取得筐中所有桃子后， 仍不满足 m 个， 则回到队尾继续排队
		else {
				PBox=tmpMon.PMonkey-m;
				printf("\n 出队猴子的编号为： %d\n\n",tmpMon.id);
				save(tmpMon.id);
				DeQueue(Q);
			}//反之桃子已取够数量， 则该猴子出队， 并将多出的桃子放回筐内
			printf("\n 下一时刻队列状态为： \n");
			QueueTraverse(Q,*visit);
			printf("\n\n");
	}
	if(QueueEmpty(Q))
	{
		printf("当前队列为空！ ");
		DestroyQueue(Q);
	}
	system("pause");
}

//2、 输入输出.h
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

//3、 猴子分桃.cpp（循环队列实现）
#include "stdafx.h"
#include"stdio.h"
#include"stdlib.h"
#include"输入输出.h"
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
	printf("猴子数量为 %d 只， \n 每次放入不超过 %d 个桃子， \n 每只猴子需要领到 %d 个桃子出队\n",n,k,m);
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
			printf("\n 出队猴子的编号为： %d\n\n",tmpMon.id);
			save(tmpMon.id);
			DeQueue(Q);
		}
		printf("\n 下一时刻队列状态为： \n");
		QueueTraverse(Q,*visit);
		printf("\n\n");
	}
	if(QueueEmpty(Q)) printf("当前队列为空！ \n\n");
}

