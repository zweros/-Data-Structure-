
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
extern void InitQueue(SqQueue *&q);
extern void ClearQueue(SqQueue *&q);
extern int EmptyQueue(SqQueue *q);
extern int QueueLength(SqQueue *q);
extern int EnQueue(SqQueue *q,ElemType e);
extern int DeQueue(SqQueue *q,ElemType &e);
extern void number(int n);
extern int get(SqQueue *q,int x);
void  Angel();
void main()
{
	SqQueue *q;
	int n=10;
	ElemType e;
	printf("(1)��ʼ��ѭ������q\n");
	InitQueue(q);
	printf("(2)�ж�ѭ������q�Ƿ�Ϊ��:");
	if(EmptyQueue(q))	printf("��\n");
	else printf("����\n");
	printf("(3)������ӵ�Ԫ��a,b,c\n");
	EnQueue(q,'a');
	EnQueue(q,'b');
	EnQueue(q,'c');
	printf("(4)����һ��Ԫ��,�����Ԫ��:");
	DeQueue(q,e);
	printf("%c",e);
	printf("\n(5)�������q�е�Ԫ�صĸ���:");
	printf("%d\n",QueueLength(q));
	printf("(6)���˽�����Ԫ��d,e,f\n");
	EnQueue(q,'d');
	EnQueue(q,'e');
	EnQueue(q,'f');
	printf("(7)�������q�е�Ԫ�صĸ���:");
	printf("%d\n",QueueLength(q));
	printf("(8)�����������:");
	while(q->front!=q->rear)
	{
		DeQueue(q,e);
		printf("%4c",e);}
	printf("\n(9)�ͷŶ���\n");
	ClearQueue(q);
	/*N���˱�������*/
	//printf("������һ����:");
	//scanf("%d\n",&n);
	number(n);
		
	Angel();

}
