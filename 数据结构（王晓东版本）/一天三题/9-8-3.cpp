/*算法实验题 2.1 向量分类问题
	问题描述：
	给定 m 个 n 维向量 a1， a2……am， 要求将相同的向量划分为同一类。 试用抽象数据类型表
	设计向量分类问题的有效算法。

	实验任务：
	给定 m 个 n 维向量， 计算这 m 个 n 维向量可分为多少个类？
 
 	数据输入：
	由文件 input.txt 给出输入数据。 
	第一行有 2 个正整数 m 和 n， 分别表示给定的向量个数和每个向量的维数。 
	接下来的 m 行中， 每行有 n 个整数， 表示相应的 n 维向量。

	结果输出：
	将计算出的向量等价类数输出到文件 output.txt。
	源程序如下：*/ 
//1、 向量分类.cpp
// 向量.cpp : 定义控制台应用程序的入口点。
//
//#include"stdafx.h"
//#include"stdio.h"
//#include"malloc.h"
//#include"string.h"
//#include"输入输出.h"
#include<cstdio> 
#define SIZE 50
int N[SIZE];
typedef struct Rect
{ 
	char n[SIZE];
	struct Rect* next;
}Node;

typedef Node* link;//起别名 

link head,tail;

int count=0,num=0;

void display() //链表遍历
{ 
	link p=head;
	printf("\n 第%d 次遍历结果如下： \n",num);
	while(p)
	{ 
		printf("%s\n",p->n);
		p=p->next;
	}
	printf("\n 一共有%d 类向量\n",count);
}

void Init(char a[])//链表初始化
{ 
	link tmp;
	head=(link)malloc(sizeof(Node));
	tmp=head;
	strcpy(head->n,a);
	head->next=NULL;
	tail=head;
	count++;
	num++;
}

void Insert(char a[]) //通过插入结点建立链表
{ 
	link tmp1,tmp2;
	tmp1=tail;
	tmp2=(link)malloc(sizeof(Node));
	strcpy(tmp2->n,a);
	tmp2->next=NULL;	
	tmp1->next=tmp2;
	tmp1=tmp1->next;
	tail=tmp2;
	count++;
}

void compare(char a[]) //通过字符串比较确定向量分类
{ 
	link tmp=head;
	int flag=0;
	while(tmp)
	{ 
		if(strcmp(tmp->n,a)==0)//不相等 
		{
			flag=1;break;
		}
		tmp=tmp->next;
	}
	if((flag==0)&&tmp==NULL)
	Insert(a);
	display();
}

int main()
{ 
	char str[SIZE];
	FILE *fp;
	fp=fopen("input.txt","r");
	fgets(str,SIZE,fp);
	Init(str);
	display();
	while(!feof(fp))
	{ 
		fgets(str,SIZE,fp);
		num++;
		compare(str);
	}
	fclose(fp);
	save(count); 
	getchar(); 
	return 0;
}

