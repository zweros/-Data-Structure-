
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
{//��ʼ������
	L=(LinkList*)malloc(sizeof(LinkList));
	L->next=NULL;
}
void DestoryList(LinkList *&L)
{//��������
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
{//���������Ƿ�Ϊ��
	if(L==NULL)
		return 0;
}
int ListLength(LinkList *L)//���ַ�������
{//��������ĳ���
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
{//���������Ԫ��
	LinkList *p;
	p=L->next;
	printf("��������е��ַ�:");
	while(p!=NULL)
	{
		printf("%c",p->data);
		printf("\t");
		p=p->next;
	}
	printf("\n");
}
int GetElem(LinkList *L,int i,ElemType &e)
{//��ȡ�����е�i��Ԫ�ص�ֵ
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
{//��λ��������ĳ���ض���Ԫ��
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
{//�ڵ�����ĵ�iλ���ϲ���һ��Ԫ��
	LinkList *p,*q;
	int j=0;
	p=L;
	while(p!=NULL&&j<i-1)
	{//�ҵ�����λ�õ�ǰһ��
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
{//ɾ���������еĵ�iλ�õ�Ԫ��
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
{//	ǰ�巨
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
{//��巨
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
	r->next=NULL;//ע��:��עβ��
}
void rotory(LinkList *L)
{//�͵ص���
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
