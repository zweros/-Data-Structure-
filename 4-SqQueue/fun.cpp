
#include<stdio.h>
#include<malloc.h>
#define MaxSize 10
typedef int ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int front;//ָ������е�һ��Ԫ�ص�ǰһ��Ԫ��
	int rear;//ָ����������һ��Ԫ��
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
	if((q->rear+1)%MaxSize==q->front)//�ж϶���������
		return 0;
	else{
		q->rear=(q->rear+1)%MaxSize;//ע��Ҫȡ��
		q->data[q->rear]=e;
		return 1;
	}	
}
int DeQueue(SqQueue *q,ElemType &e)
{//ElemType�����&����ʡ��
	if(q->front==q->rear)
		return 0;	e=q->data[q->front];
	q->front=(q->front+1)%MaxSize;//ע��Ҫȡ��

	/*�������еĴ����ܸı�*/
	return 1;
}
/*N���˱�������*/
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
	printf("������������ǵ�����:");
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
