#include<stdio.h>
#include<malloc.h>
#define N 10
typedef char ElemType;

typedef struct Node
{
    ElemType date;
	struct Node *next;
}LinkList;

extern void InitList(LinkList *&L);
extern void DestoryList(LinkList *&L);
extern int ListLength(LinkList *L);
extern void DispList(LinkList *L);
extern int ListEmpty(LinkList *L);
extern int  ListInsert(LinkList *&L,int i,ElemType e);
extern int GetElem(LinkList *L,int i,ElemType &e);
extern int LocateElem(LinkList *L,ElemType e);
extern int ListDelete(LinkList *&L,int i,ElemType &e);
extern void CreateList_H(LinkList *&L,ElemType a[N]);
extern void CreateList_R(LinkList *&L,ElemType a[N]);
extern void rotory(LinkList *L);
void main()
{
	char a[N]={'a','b','c','d'};
	Node *L;
	ElemType e;
    InitList(L);
	ListInsert(L,1,'a');
	ListInsert(L,2,'b');
	ListInsert(L,3,'c');
	ListInsert(L,4,'d');
    DispList(L);
	printf("输出链表的长度:%d\n",ListLength(L));
	if(!ListEmpty(L))
		printf("为空\n");
	else 
		printf("不为空\n");
	GetElem(L,3,e);
	printf("第三个元素的值为%c\n",e);
	printf("a的位置为%d\n",LocateElem(L,'a'));
	ListInsert(L,4,'f');
	DispList(L);
	ListDelete(L,5,e);
	printf("删除最后一个元素\n");
	DispList(L);
	DestoryList(L);
	printf("前插法\n");
	CreateList_H(L,a);
	DispList(L);
	DestoryList(L);
	CreateList_R(L,a);
	printf("后插法:\n");
	DispList(L);
	printf("就地逆置:\n");
	rotory(L);
	DispList(L);
	DestoryList(L);
}
