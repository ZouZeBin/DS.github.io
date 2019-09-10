//10实现链队列的头文件 LQueue.h（清华大学 严蔚敏版）
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
} QNode, *QueuePtr; //队列结点的定义

typedef struct
{ 
	QueuePtr front;
	QueuePtr rear;
} LinkQueue; //队列的ADT定义

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q) ;
Status ClearQueue(LinkQueue &Q) ;
Status QueueEmpty(LinkQueue Q);
Status QueueLength(LinkQueue Q) ;
Status GetHead(LinkQueue &Q,QElemType &e) ;
Status EnQueue(LinkQueue &Q,QElemType e);
Status DeQueue(LinkQueue &Q,QElemType &e) ;
Status QueueTraverse(LinkQueue Q, Status(*visit) () );

Status InitQueue(LinkQueue &Q)//队列的初始化
{ 
	Q.front=Q.rear=(QueuePtr) malloc(sizeof(QNode) );
	if(!Q.front)exit(OVERFLOW);
	Q. front->next=NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q) //队列的销毁
{ 
	while(Q.front)
	{
		Q. rear=Q.front->next;
		free(Q. front) ;
		Q.front=Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue &Q) //队列的清空操作
{ 
	Q. front=Q. rear;
	return OK;
}

Status QueueEmpty(LinkQueue Q)//判断队列是否为空队列
{ 
	if(Q. front==Q. rear) return TRUE;
	else
	return FALSE;
}

Status EnQueue(LinkQueue &Q,QElemType e)//将元素e进队列
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

Status DeQueue(LinkQueue &Q)//出队操作
{ 
	QueuePtr p;
	if(Q. front==Q. rear) return ERROR;
	p=Q. front->next;
	Q. front->next=p->next;
	if(Q. rear==p) Q. rear=Q. front;
	free(p) ;
	return OK;
}

Status QueueLength(LinkQueue Q) //求队列的长度
{ 
	return(Q. rear-Q. front) ;
}

QElemType GetHead(LinkQueue &Q) //取得队首元素
{
	if(Q. front==Q. rear) printf(ERROR) ;
	else return Q.front->next->data;
}

Status QueueTraverse(LinkQueue Q, Status(*visit) (QElemType e)) //队列的遍历
{ 
	QueuePtr p=Q. front->next;
	while (p!=NULL)
	{ 
		visit(p->data) ;
		p=p->next;
	}
	return OK;
}

//实现循环队列的头文件 AQueue.h（清华大学 严蔚敏版）
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
} *Queue, SqQueue; //循环队列的ADT定义

Status QueueInit(SqQueue &Q);
Status QueueLength(Queue Q) ;
Status QueueEmpty(SqQueue Q);
Status QueueFull(SqQueue Q) ;
QItem QueueFirst(SqQueue Q);
QItem QueueLast(Queue Q) ;
Status EnQueue(SqQueue &Q,QItem e);
QItem DeQueue(SqQueue &Q);
Status QueueTraverse(Queue Q, Status(*visit) () );

Status QueueInit(SqQueue &Q)//循环队列的初始化
{ //Q. data=(QItem * ) malloc(MAXQSIZE * sizeof(QItem) ) ;
	Q. maxsize= MAXQSIZE;
	Q. front=Q. rear=0;
	return OK;
}

Status QueueLength(SqQueue Q) 
{
	return((Q. rear-Q. front+MAXQSIZE) % MAXQSIZE) ;
}

Status QueueEmpty(SqQueue Q)//判断队列空
{
	return Q. front==Q. rear;
}
Status QueueFull(SqQueue Q) //判断循环队列是否满（使用循环数组， 因此需要判断队列是否发生溢出）
{
	return(((Q. rear+1) %Q. maxsize == Q. front) ? 1: 0) ;
}

Status EnQueue(SqQueue &Q,QItem e)//入队操作
{
	if(QueueFull(Q) ) printf("Queue is full") ;
	Q. data[Q. rear]=e;
	Q. rear=(Q. rear+1) %Q. maxsize;
	return OK;
}

QItem DeQueue(SqQueue &Q) //出队操作， 返回出队的元素e
{ 
	if(QueueEmpty(Q) ) printf("Queue is empty") ;
	QItem &e=Q. data[Q. front];
	Q. front=(Q. front+1) %Q. maxsize;
	return e;
}

Status QueueTraverse(SqQueue Q, Status(*visit) (QItem e)) //循环队列的遍历操作
{ 
	int p=Q. front;
	while (p%Q. maxsize<Q. rear)
	{ 
		visit(Q. data[p%Q. maxsize]) ;
		p++;
	}
	return OK;
}

QItem QueueFirst(SqQueue Q) //取得队首元素
{ 
	if(QueueEmpty(Q) ) printf("Queue is empty") ;
	return Q. data[(Q. front) %Q. maxsize];
}

QItem QueueLast(SqQueue Q) //取得队尾元素
{ 
	if(QueueEmpty(Q) ) printf("Queue is empty") ;
	return Q. data[Q. rear];
}

