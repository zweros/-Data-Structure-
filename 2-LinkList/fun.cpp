
#include<stdio.h>
#include<malloc.h>
#define N 10
typedef char ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;
 
void InitList(LinkList *&L)
{//初始化链表
	L=(LinkList*)malloc(sizeof(LinkList));
	L->next=NULL;
}
void DestoryList(LinkList *&L)
{//销毁链表
	LinkList *p,*q;
	p=L;
	q=L->next;
	while(q!=NULL)
	{
		free(p);
		p=q;
		q=q->next;
	}
	free(p);
}
int ListEmpty(LinkList *L)
{//返回链表是否为空
	if(L==NULL)
		return 0;
}
int ListLength(LinkList *L)//两种方法都行
{//返回链表的长度
	LinkList *p;
	p=L; //p=L->next
	int i=0;
	while(p->next!=NULL)//p!=NULL
	{
		i++;
		p=p->next;
	}
	return i;
}
void DispList(LinkList *L)
{//输出链表中元素
	LinkList *p;
	p=L->next;
	printf("输出链表中的字符:");
	while(p!=NULL)
	{
		printf("%c",p->data);
		printf("\t");
		p=p->next;
	}
	printf("\n");
}
int GetElem(LinkList *L,int i,ElemType &e)
{//获取链表中第i个元素的值
	LinkList *p;
	p=L->next;
	int j=1;
	while(p&&j<i)
	{
		j++;
		p=p->next;
	}
	if(!p||j>i)
		return 0;

	e=p->data;
	return e;
}
int LocateElem(LinkList *L,ElemType e)
{//定位单链表中某个特定的元素
	LinkList *p;
	int i=0;
	p=L->next;
	while(p&&e!=p->data)
	{
		p=p->next;
		i++;
	}
	return i+1;
}
int ListInsert(LinkList *&L,int i,ElemType e)
{//在单链表的第i位置上插入一个元素
	LinkList *p,*q;
	int j=0;
	p=L;
	while(p!=NULL&&j<i-1)
	{//找到插入位置的前一个
		j++;
		p=p->next;//p++;
	}
	q = new Node;
	q->data=e;
	q->next=p->next;
	p->next=q;
	return 1;
}
int ListDelete(LinkList *&L,int i,ElemType &e)
{//删除单链表中的第i位置的元素
	LinkList *p,*q;
	int j=0;
	p=L;
	while(p->next!=NULL&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1))
		return 0;
	q=p->next;
	p->next=q->next;
	delete q;
	return 1;
}
void CreateList_H(LinkList *&L,ElemType a[N])
{//	前插法
	int i=0;
	LinkList *s;
	L=(LinkList*)malloc(sizeof(LinkList));
	L->next=NULL;
	for(i=0;a[i-1]!='\0';i++)
	{
	   s=(LinkList*)malloc(sizeof(LinkList));
	   s->data=a[i];
	   s->next=L->next;
	   L->next=s;
	}
	s->data='\0';
}
void CreateList_R(LinkList *&L,ElemType a[N])
{//后插法
	int i;
	LinkList *s,*r;
	r=L;
	L=(LinkList*)malloc(sizeof(LinkList));
	L->next=NULL;
	for(i=0;a[i]!='\0';i++)
	{
		s=(LinkList*)malloc(sizeof(LinkList));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;//注意:标注尾巴
}
void rotory(LinkList *L)
{//就地倒置
	LinkList *p,*q;
	p=L->next;
	L->next=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
	}
}
