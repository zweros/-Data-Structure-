
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct 
{
	ElemType elem[MaxSize];
   	int length;
} SqList;
void InitList(SqList *&L)
{
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void DestroyList(SqList *L)
{
	free(L);
}
int ListEmpty(SqList *L)
{
	return(L->length==0);
}
int ListLength(SqList *L)
{
	return(L->length);
}
void DispList(SqList *L)
{
	int i;
	if (ListEmpty(L)) return;
	for (i=0;i<L->length;i++)
		printf("%c",L->elem[i]);
	printf("\n");
}
int GetElem(SqList *L,int i,ElemType &e)
{
	if (i<1 || i>L->length)
		return 0;
	e=L->elem[i-1];
	return 1;
}
int LocateElem(SqList *L, ElemType e)
{
	int i=0;
	while (i<L->length && L->elem[i]!=e) i++;
	if (i>=L->length)
		return 0;
	else
		return i+1;
}
int ListInsert(SqList *&L,int i,ElemType e)
{
	int j;
	if (i<1 || i>L->length+1)
		return 0;
	i--;							/*将顺序表位序转化为elem下标*/
	for (j=L->length;j>i;j--)		/*将elem[i]及后面元素后移一个位置*/
		L->elem[j]=L->elem[j-1];
	L->elem[i]=e;
	L->length++;					/*顺序表长度增1*/
	return 1;
}
int ListDelete(SqList *&L,int i,ElemType &e)
{
	int j;
	if (i<1 || i>L->length)
		return 0;
	i--;							/*将顺序表位序转化为elem下标*/
	e=L->elem[i];
	for (j=i;j<L->length-1;j++)
		L->elem[j]=L->elem[j+1];
	L->length--;
	return 1;
}