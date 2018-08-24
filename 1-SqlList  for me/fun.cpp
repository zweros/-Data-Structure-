
#include<stdio.h>
#include<malloc.h>
#define Maxsize 100
typedef char ElemType;
typedef struct 
{
	ElemType Date[Maxsize];
	int length;
}SqList;
void InitList(SqList *&L)//顺序表初始化
{
	L= (SqList*)malloc(sizeof(SqList));
	L->length =0;
}
void Desytory(SqList *L)//销毁表
{
	free(L);
}
int ListEmtpy(SqList *L)//判断是否为空
{
	if(L->length==0)
		return 1;
}
int ListLength(SqList *L)//返回顺序表的长度
{
	return L->length;
}
void DispList(SqList *L)//输出顺序表的值
{
	int i=0;
	for(i=0;i<=L->length;i++)
		printf("%s",L->Date[i]);
}
	
int GetElem(SqList *L,int i,ElemType &e) //查找第i个元素
{
	if(i<0||i>L->length)
		return 0;
	return L->Date[i-1];
}
int LocateElem(SqList *L,ElemType e)
{
		int j=0;
	for(j=0;j<L->length;j++)
	{
		if(e==L->Date[j-1])
			return 1;
		else
			return 0;
	}
}
int  ListInsert(SqList *&L,int i,ElemType e)
{
	if(i<0||i>L->length)return 0;

	for(i;i<=L->length+1;i++)
		L->Date[i]=L->Date[i-1];

	L->Date[i-1]=e;
	L->length+=1;
	return 1;
}
int ListDelete(SqList *&L,int i,ElemType &e)
{
	if(i<0||i>L->length)
		return 0;

	for(i=i-1;i<L->length-1;i++)
		L->Date[i-1]=L->Date[i];
	
	L->length-=1;
	return 1;
}

