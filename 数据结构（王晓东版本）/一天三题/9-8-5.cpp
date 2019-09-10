//5 ʵ�ֶ�ջ��ͷ�ļ� stack.h���廪��ѧ ��ε���棨C �����������ݽṹ����
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
};//ջADT�Ķ���

typedef struct STACK SqStack;
typedef struct STACK *pSqStack;

Status InitStack(SqStack **S);//��ʼ�� 
Status DestroyStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack S);//�п� 
Status StackLength(SqStack S);//ջ�Ĵ�С 
SElemType GetTop(SqStack S);//����ջ�� 
Status Push(SqStack *S, SElemType *e);//ѹջ 
Status Pop(SqStack *S,SElemType *e);//��ջ 
Status StackTraverse(SqStack S, Status(*visit) (SElemType *e) );

Status InitStack(SqStack **S)//��ʼ����ջ
{ 
	(*S) =(SqStack*) malloc(sizeof(SqStack) );
	(*S) ->base=(SElemType *) malloc(STACK_INIT_SIZE *sizeof(SElemType) );
	if(!(*S) ->base) exit(OVERFLOW);
		(*S) ->top=(*S) ->base;
		(*S) ->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack *S) //ջ�����ٲ���
{
	free(S->base);
	free(S) ;
	return OK;
}

Status ClearStack(SqStack *S) //ջ����ղ���
{
	S->top=S->base;
	return OK;
}

Status StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ��
{
	if(S.top==S. base)return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)//�����ջ��С
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

SElemType GetTop(SqStack S) //ȡ��ջ��Ԫ��
{
	if(S.top==S. base) return ERROR;
	return *(S. top-1) ;
}

Status Push(SqStack *S, SElemType e) //��Ԫ��eѹջ
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

Status Pop(SqStack *S,SElemType *e) //��ջ������ʹ�ñ���e���ճ�ջԪ��
{
	if(S->top==S->base)return ERROR;
	*e=*(--(S->top) );
	return OK;
}

Status StackTraverse(SqStack S, Status (*visit)(SElemType *e))//��ջ�ı���������visit���������ж���
{
	while (S.top>S.base)
	visit(--S.top);
	return OK;
}

