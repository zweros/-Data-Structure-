
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
	printf("(1)初始化循环队列q\n");
	InitQueue(q);
	printf("(2)判断循环队列q是否为空:");
	if(EmptyQueue(q))	printf("空\n");
	else printf("不空\n");
	printf("(3)依次入队的元素a,b,c\n");
	EnQueue(q,'a');
	EnQueue(q,'b');
	EnQueue(q,'c');
	printf("(4)出队一个元素,输出该元素:");
	DeQueue(q,e);
	printf("%c",e);
	printf("\n(5)输出队列q中的元素的个数:");
	printf("%d\n",QueueLength(q));
	printf("(6)依此进队列元素d,e,f\n");
	EnQueue(q,'d');
	EnQueue(q,'e');
	EnQueue(q,'f');
	printf("(7)输出队列q中的元素的个数:");
	printf("%d\n",QueueLength(q));
	printf("(8)输出出队序列:");
	while(q->front!=q->rear)
	{
		DeQueue(q,e);
		printf("%4c",e);}
	printf("\n(9)释放队列\n");
	ClearQueue(q);
	/*N个人报数问题*/
	//printf("请输入一个数:");
	//scanf("%d\n",&n);
	number(n);
		
	Angel();

}
