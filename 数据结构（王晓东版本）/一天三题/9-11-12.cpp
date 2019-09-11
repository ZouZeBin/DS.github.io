/* 
12设计用 2 个栈实现一个队列的算法， 并分析队列运算的计算时间复杂度。
  实验任务：
对于给定的队列运算序列， 计算所有 FIRST( ) 运算返回的结果。
 
  数据输入：
由文件 input.txt 给出输入数据。 
 第 1 行是正整数 n， 表示有 n 个队列运算。 
 接下来的每行给出一个队列运算。
其中， ENQUEUE x 表示为 E x； 
	   DEQUEUE(x)运算表示为 D； 
	   FIRST( )  运算表示为 F。
 
  结果输出：
  
将输入数据给出的队列运算中 FIRST( )运算返回的结果依次输出到文件 output.txt。
3、 Input.txt
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
4、 Output.txt
42
24
0
0

源程序如下：
1、 双栈队列.cpp*/ 
// 双栈队列.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include "stdio.h"
#include "string.h"
//#include "输入输出.h"
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
	SqStack *SIn,*SOut;//建立两个堆栈模拟队列操作， 一为压入， 一为弹出
	FILE *fp;
	char a[SIZE];
	int que,e,cnt;
	InitStack(&SIn);
	InitStack(&SOut);
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&cnt);
	printf("系统中一共有%d 组队列在工作\n",cnt);
	while(!feof(fp)) //通过字符串比较确定进行的操作
	{ 
		fscanf(fp,"%s",a);
		switch(a[0]){
						case 'E':
							printf("\n\n 当前操作为%s:入队列， 元素值： ",a);
							fscanf(fp,"%d",&que);
							printf("%d\n",que);
							while(!StackEmpty(*SOut))
							{ 
								Pop(SOut,&e);
								Push(SIn,e);
							} //当有数据元素进队， 将弹出栈所有元素依序导入压入栈
							Push(SIn,que);//将当前元素进队
							while(!StackEmpty(*SIn))
							{ 
								Pop(SIn,&e);
								Push(SOut,e);
							}//将所有压入栈元素重新依序导入弹出栈
							break;
					
						case 'D':
							printf("\n\n 当前操作为%s:出队列， 元素值： ",a);
							Pop(SOut,&e);
							printf("%d\n",e);
							break;//出队操作， 直接将弹出栈栈顶元素出队
						
						case 'F':
							printf("\n\n 当前操作为%s:取队头元素， 值： ",a);
							e=GetTop(*SOut);
							printf("%d\n",e);
							save(e);
							break;
			
						default:continue;
					}//取得队头元素
		if(!StackEmpty(*SOut))
		{ 
			printf("当前队列工作状态为： \n");
			StackTraverse(*SOut,visit);
		}
		else printf("当前队列为空!\n");
	}//队列的遍历
	fclose(fp);
	DestroyStack(SIn);
	DestroyStack(SOut);
	getchar();
	return 0;
}



