/*算法实验题 3.3 多栈模拟问题

	问题描述：
	设当前系统中有多个栈在工作， 多栈模拟问题要求模拟当前系统中各栈的工作状态。
	
 	实验任务：
	对于给定的栈操作， 模拟系统中各栈的工作状态。
	
	数据输入：
	由文件 input.txt 给出输入数据。 第 1 行是正整数 n， 表示有 n 个栈操作。 
	接下来的 n 行，每行给出一个栈操作指令。 
	指令"PUSH A B" 表示将正整数 B 加入到编号为 A 的栈顶， 
	指令"POP A" 表示输出编号为 A 的栈顶元素。
	
    结果输出：
	将输入数据中 POP 指令的输出结果依次输出到文件 output.txt。 
	当编号为 A 的栈为空时，栈操作指令"POP A" 输出 0。
源程序如下：
1、 多栈模拟.cpp
// 多线模拟.cpp : 定义控制台应用程序的入口点。*/ 
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "输入输出.h"
#include "malloc.h"
typedef struct list
{	
	int id;
	int data;
	struct list * next;
}Node;

//定义工作链表
typedef Node * link;
link head,tail=NULL;
int count,L=0;

void Insert(int m,int n)
{ 
	link ptr,q;
	if(head==NULL)
	{ 
		head=(link)malloc(sizeof(Node));
		head->next=NULL;
		head->id=m;
		head->data=n;
	}
	else
	{ 
		ptr=head;
		q=(link)malloc(sizeof(Node));
		q->id=m;
		q->data=n;
		q->next=ptr;
		head=q;
	}	
}//通过插入结点建立链表

int delete_node(int n)
{ 
	link q,ptr=head;
	if(head->id==n)
	{ 
		printf("堆栈 ID： %d 弹出 值： %d\n",ptr->id,ptr->data);
		head=head->next;
		return ptr->data;
		free(ptr);
	}//如果待出栈结点是第一个结点， 将头指针后移
	else
	{ 
		while((ptr->id!=n)&&ptr->next!=NULL)
		{ 
			q=ptr;
			ptr=ptr->next;
			if(ptr->id==n)
			{ 
				printf("堆栈 ID： %d 弹出 值： %d\n",ptr->id,ptr->data);
				q->next=ptr->next;
				return ptr->data;
				free(ptr);
			}
		}
	}
	return 0;
}//如果待出栈的结点位于链表中间， 查找之， 找到后将其删除

void display()
{ 
	link p=head;
	printf("\n 当前堆栈工作状态为： \n");
	while(p)
	{ 
		printf("堆栈 ID： %d,值： %d\n",p->id,p->data);
		p=p->next;
	}
}//打印当前堆栈工作状态

void main()
{ 
	FILE *fp;
	char a[SIZE];
	int out[SIZE];
	int i=0,k,num;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&count);
	printf("系统中一共有%d 个栈在工作\n",count);
	while(!feof(fp))
	{ 
		fscanf(fp,"%s",a);
		if(strcmp(a,"push")==0)
		{	
			printf("%s:\n",a);
			fscanf(fp,"%d%d",&k,&num);
			Insert(k,num);
			display();
		}
		if(strcmp(a,"pop")==0)
		{ 
			fscanf(fp,"%d",&k);
			printf("%s:\n",a);
			i=delete_node(k);
			save(i);
			display();
		}
	}//按行读取输入文件， 通过字符串比较确定堆栈操作， 调用相应函数
	fclose(fp);
	getchar();
}

