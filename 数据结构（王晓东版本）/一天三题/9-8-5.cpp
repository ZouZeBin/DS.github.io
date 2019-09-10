//5 实现堆栈的头文件 stack.h（清华大学 严蔚敏版（C 语言描述数据结构））
//Stack.h
#include<malloc.h>
#include<stdlib.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
struct STACK
{
	SElemType *base;
	SElemType *top;
	int stacksize;
};//栈ADT的定义

typedef struct STACK SqStack;
typedef struct STACK *pSqStack;

Status InitStack(SqStack **S);//初始化 
Status DestroyStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack S);//判空 
Status StackLength(SqStack S);//栈的大小 
SElemType GetTop(SqStack S);//返回栈顶 
Status Push(SqStack *S, SElemType *e);//压栈 
Status Pop(SqStack *S,SElemType *e);//弹栈 
Status StackTraverse(SqStack S, Status(*visit) (SElemType *e) );

Status InitStack(SqStack **S)//初始化堆栈
{ 
	(*S) =(SqStack*) malloc(sizeof(SqStack) );
	(*S) ->base=(SElemType *) malloc(STACK_INIT_SIZE *sizeof(SElemType) );
	if(!(*S) ->base) exit(OVERFLOW);
		(*S) ->top=(*S) ->base;
		(*S) ->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack *S) //栈的销毁操作
{
	free(S->base);
	free(S) ;
	return OK;
}

Status ClearStack(SqStack *S) //栈的清空操作
{
	S->top=S->base;
	return OK;
}

Status StackEmpty(SqStack S)//判断栈是否为空
{
	if(S.top==S. base)return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)//计算堆栈大小
{	
	int i;
	SElemType *p;
	i=0;
	p=S.top;
	while(p!=S. base)
	{
		p++;
		i++;
	}
	return i;
}

SElemType GetTop(SqStack S) //取得栈顶元素
{
	if(S.top==S. base) return ERROR;
	return *(S. top-1) ;
}

Status Push(SqStack *S, SElemType e) //将元素e压栈
{
	if(S->top - S->base>=S->stacksize)
	{
		S->base=(SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) *sizeof(SElemType) );
		if(!S->base)exit(OVERFLOW);
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*(S->top++) =e;
	return OK;
}

Status Pop(SqStack *S,SElemType *e) //出栈操作，使用变量e接收出栈元素
{
	if(S->top==S->base)return ERROR;
	*e=*(--(S->top) );
	return OK;
}

Status StackTraverse(SqStack S, Status (*visit)(SElemType *e))//堆栈的遍历，其中visit函数需自行定义
{
	while (S.top>S.base)
	visit(--S.top);
	return OK;
}

