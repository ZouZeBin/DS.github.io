//10ʵ�������е�ͷ�ļ� LQueue.h���廪��ѧ ��ε���棩
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define QUEUE_INIT_SIZE 100
#define QUEUEINCREMENT 10
typedef int Status;
typedef struct QNode
{ 
	QElemType data;
	struct QNode *next;
} QNode, *QueuePtr; //���н��Ķ���

typedef struct
{ 
	QueuePtr front;
	QueuePtr rear;
} LinkQueue; //���е�ADT����

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q) ;
Status ClearQueue(LinkQueue &Q) ;
Status QueueEmpty(LinkQueue Q);
Status QueueLength(LinkQueue Q) ;
Status GetHead(LinkQueue &Q,QElemType &e) ;
Status EnQueue(LinkQueue &Q,QElemType e);
Status DeQueue(LinkQueue &Q,QElemType &e) ;
Status QueueTraverse(LinkQueue Q, Status(*visit) () );

Status InitQueue(LinkQueue &Q)//���еĳ�ʼ��
{ 
	Q.front=Q.rear=(QueuePtr) malloc(sizeof(QNode) );
	if(!Q.front)exit(OVERFLOW);
	Q. front->next=NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q) //���е�����
{ 
	while(Q.front)
	{
		Q. rear=Q.front->next;
		free(Q. front) ;
		Q.front=Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue &Q) //���е���ղ���
{ 
	Q. front=Q. rear;
	return OK;
}

Status QueueEmpty(LinkQueue Q)//�ж϶����Ƿ�Ϊ�ն���
{ 
	if(Q. front==Q. rear) return TRUE;
	else
	return FALSE;
}

Status EnQueue(LinkQueue &Q,QElemType e)//��Ԫ��e������
{ 
	QueuePtr p;
	p=(QueuePtr) malloc(sizeof(QNode) ) ;
	if(!p) exit(OVERFLOW) ;
	p->data=e;
	p->next=NULL;
	Q. rear->next=p;
	Q. rear=p;
	return OK;
}

Status DeQueue(LinkQueue &Q)//���Ӳ���
{ 
	QueuePtr p;
	if(Q. front==Q. rear) return ERROR;
	p=Q. front->next;
	Q. front->next=p->next;
	if(Q. rear==p) Q. rear=Q. front;
	free(p) ;
	return OK;
}

Status QueueLength(LinkQueue Q) //����еĳ���
{ 
	return(Q. rear-Q. front) ;
}

QElemType GetHead(LinkQueue &Q) //ȡ�ö���Ԫ��
{
	if(Q. front==Q. rear) printf(ERROR) ;
	else return Q.front->next->data;
}

Status QueueTraverse(LinkQueue Q, Status(*visit) (QElemType e)) //���еı���
{ 
	QueuePtr p=Q. front->next;
	while (p!=NULL)
	{ 
		visit(p->data) ;
		p=p->next;
	}
	return OK;
}

//ʵ��ѭ�����е�ͷ�ļ� AQueue.h���廪��ѧ ��ε���棩
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXQSIZE 100
typedef int Status;
typedef struct Aque
{ 
	int maxsize;
	int front;
	int rear;
//QItem *data;
	QItem data[MAXQSIZE];
} *Queue, SqQueue; //ѭ�����е�ADT����

Status QueueInit(SqQueue &Q);
Status QueueLength(Queue Q) ;
Status QueueEmpty(SqQueue Q);
Status QueueFull(SqQueue Q) ;
QItem QueueFirst(SqQueue Q);
QItem QueueLast(Queue Q) ;
Status EnQueue(SqQueue &Q,QItem e);
QItem DeQueue(SqQueue &Q);
Status QueueTraverse(Queue Q, Status(*visit) () );

Status QueueInit(SqQueue &Q)//ѭ�����еĳ�ʼ��
{ //Q. data=(QItem * ) malloc(MAXQSIZE * sizeof(QItem) ) ;
	Q. maxsize= MAXQSIZE;
	Q. front=Q. rear=0;
	return OK;
}

Status QueueLength(SqQueue Q) 
{
	return((Q. rear-Q. front+MAXQSIZE) % MAXQSIZE) ;
}

Status QueueEmpty(SqQueue Q)//�ж϶��п�
{
	return Q. front==Q. rear;
}
Status QueueFull(SqQueue Q) //�ж�ѭ�������Ƿ�����ʹ��ѭ�����飬 �����Ҫ�ж϶����Ƿ��������
{
	return(((Q. rear+1) %Q. maxsize == Q. front) ? 1: 0) ;
}

Status EnQueue(SqQueue &Q,QItem e)//��Ӳ���
{
	if(QueueFull(Q) ) printf("Queue is full") ;
	Q. data[Q. rear]=e;
	Q. rear=(Q. rear+1) %Q. maxsize;
	return OK;
}

QItem DeQueue(SqQueue &Q) //���Ӳ����� ���س��ӵ�Ԫ��e
{ 
	if(QueueEmpty(Q) ) printf("Queue is empty") ;
	QItem &e=Q. data[Q. front];
	Q. front=(Q. front+1) %Q. maxsize;
	return e;
}

Status QueueTraverse(SqQueue Q, Status(*visit) (QItem e)) //ѭ�����еı�������
{ 
	int p=Q. front;
	while (p%Q. maxsize<Q. rear)
	{ 
		visit(Q. data[p%Q. maxsize]) ;
		p++;
	}
	return OK;
}

QItem QueueFirst(SqQueue Q) //ȡ�ö���Ԫ��
{ 
	if(QueueEmpty(Q) ) printf("Queue is empty") ;
	return Q. data[(Q. front) %Q. maxsize];
}

QItem QueueLast(SqQueue Q) //ȡ�ö�βԪ��
{ 
	if(QueueEmpty(Q) ) printf("Queue is empty") ;
	return Q. data[Q. rear];
}

