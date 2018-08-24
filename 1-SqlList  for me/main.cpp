
#include<stdio.h>
#include<malloc.h>
#define Maxsize 100
typedef char ElemType;
typedef struct 
{
	ElemType Date[Maxsize];
	int length;
}SqList;
extern void InitList(SqList *&L);//À≥–Ú±Ì≥ı ºªØ
extern void Desytory(SqList *L);
extern int ListEmtpy(SqList *L);
extern int ListLength(SqList *L);
extern void DispList(SqList *L);
extern void GetElem(SqList *L,int i,ElemType &e);
extern void LocateElem(SqList *L,ElemType e);
extern void ListInsert(SqList *&L,int i,ElemType e);
extern int ListDelete(SqList *&L,int i,ElemType &e);
void main()
{
	
}

