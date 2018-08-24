
#include<stdio.h>
#include<malloc.h>
#define MaxSize 10
typedef int ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int front;//指向队列中第一个元素的前一个元素
	int rear;//指向队列中最后一个元素
}SqQueue;
void InitQueue(SqQueue *&q)
{
	q=(SqQueue*)malloc(sizeof(SqQueue));
	q->front=q->rear=0; 
}
void ClearQueue(SqQueue *&q)
{
	free(q);
}
int EmptyQueue(SqQueue *q)
{
	return (q->front==q->rear);
}
int QueueLength(SqQueue *q)
{
	int count=0;
	int i=q->front;
	while(i!=q->rear)
	{
		i++;
		count=count+1;
	}
	return count;
}
int EnQueue(SqQueue *q,ElemType e)
{
	if((q->rear+1)%MaxSize==q->front)//判断队满的条件
		return 0;
	else{
		q->rear=(q->rear+1)%MaxSize;//注意要取余
		q->data[q->rear]=e;
		return 1;
	}	
}
int DeQueue(SqQueue *q,ElemType &e)
{//ElemType后面的&不可省略
	if(q->front==q->rear)
		return 0;	e=q->data[q->front];
	q->front=(q->front+1)%MaxSize;//注意要取余

	/*上面两行的次序不能改变*/
	return 1;
}
/*N个人报数问题*/
void number(int n)
{	
	ElemType e;
	SqQueue *q;
	InitQueue(q);
	for(int i=1;i<=n;i++){
		EnQueue(q,i);
		printf("%4d",q->data[i]);}
	printf("\n");
	while(!EmptyQueue(q))
	{
		DeQueue(q,e);
		printf("%4d",e);
		if(!EmptyQueue(q))
		{
			DeQueue(q,e);	
			EnQueue(q,e);
		}	
	}
	ClearQueue(q);
	printf("\n");
}
int get(SqQueue *q,int x)
{
	if(q->front==q->rear)
		return 0;
	else
	{
		x=q->data[q->front];
		return 1;
	}
}
void  Angel()
{
	SqQueue *q;
	int n,m,i,x,y;
	InitQueue(q);
	printf("请输入杨辉三角的行数:");
	scanf("%d",&m);
	EnQueue(q,1);
	for(n=2;n<=m;n++)
	{
		EnQueue(q,1);
		for(i=1;i<=n-2;i++)
		{
			DeQueue(q,x);
			printf("%d ",x);
			get(q,y);
			y=y+x;
			EnQueue(q,y);
		}
		DeQueue(q,x);
		printf("%d",x);
		printf("\n");
		EnQueue(q,1);
	}
	while(q->front!=q->rear)
	{
		DeQueue(q,x);
		printf("%d ",x);
	}
}
