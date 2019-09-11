/*11算法实验题 4.1 组队列问题
	问题描述：
  组队列是一个特殊的抽象数据类型，它所支持的运算类似于队列运算， 
  所不同的是每个元素有附加的组属性。 
  因此入队运算 Enqueue(x)与通常定义的运算不同。 
  在组队列中Enqueue(x)运算将元素 x 加入当前队列中与元素 x 属于同一组的元素的尾部。 
  组队列的其他运算与通常定义的队列运算相同。
  


	实验任务：
  设计并实现抽象数据类型组队列基本运算的算法。
	
	数据输入：
  由文件 input.txt 给出输入数据。 
  第 1 行是正整数 n，表示有 n 组数据元素。 
  接下来的n行每行给出一组数据元素。 
  每行的第 1 个正整数 t 表示该组数据元素个数， 
  接下来的 t 个正整数表示该组中的 t 个元素。 
  再接着的各行，每行给出 1 个队列运算。 
  ENQUEUE x 表示将元素 x 加入组队列， DEQUEUE 表示删除队首元素。 
  文件最后以 STOP 结尾。
	
	结果输出：
  将每个 DEQUEUE 运算删除的队首元素依次输出到文件 output.txt。
源程序如下：
1、 组队列.cpp
*/ 
// 组队列.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include "stdio.h"
#include "string.h"
//#include "输入输出.h"
#include "malloc.h"

#define SIZE 50
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


typedef struct list
{ 
	int id;
	int data;
	struct list * next;
}Node;

typedef Node * link;

link head,tail=NULL;

int count,L=0;

void Insert(int m,int n)
{ 
	link ptr,p,q;
	if(head==NULL)
	{ 
		head=(link)malloc(sizeof(Node));
		head->next=NULL;
		head->id=m;
		head->data=n;
	}
	else {
			p=ptr=head;
			q=(link)malloc(sizeof(Node));
			q->id=m;
			q->data=n;
			while((ptr->data<q->data)&&(ptr->next!=NULL))
			{
		     	p=ptr;
				ptr=ptr->next;
			}
			if(ptr->data>q->data)
			{ 	
				q->next=ptr;
				p->next=q;
			}
			else {
					ptr->next=q;
					q->next=NULL;
				}
			}
		}//通过查找比较插入结点建立有序链表

int delete_node()
{ 
	link q,ptr;
	q=ptr=head;
	printf("队列 ID： %d 出队列元素 值： %d\n",ptr->id,ptr->data);
	int i=ptr->data;
	ptr=ptr->next;
	head=ptr;
	free(q);
	return i;
}//删除队头元素并返回值
 
void display()
{ 
	link p=head;
	printf("\n 当前队列工作状态为： \n");
	while(p)
	{ 
		printf("队列 ID： %d,元素值： %d\n",p->id,p->data);
		p=p->next;
	}
}

int main()
{ 
	FILE *fp;
	char a[SIZE];
	int que;
	int k,cnt;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&cnt);
	printf("系统中一共有%d 组队列在工作\n",cnt);
	fscanf(fp,"%s",a);
	while(strcmp(a,"STOP")!=0)
	{ 
		if(strcmp(a,"ENQUEUE")==0)
		{
			printf("%s:\n",a);	
			fscanf(fp,"%d",&que);
			Insert(que/100,que);
			display();
		}
		if(strcmp(a,"DEQUEUE")==0)
		{ 
			printf("%s:\n",a);
			k=delete_node();
			save(k);
			display();
		}
		fscanf(fp,"%s",a);
	}//通过字符串比较确定语句实现的队列操作并相应调用函数进行模拟

	fclose(fp);
	getchar();
	return 0;
}






