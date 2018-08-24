
#include<stdio.h>
#include<malloc.h>
#define Maxsize 100
typedef char ElemType;
typedef struct 
{
	ElemType Date[Maxsize];
	int length;
}SqList;
void InitList(SqList *&L)//˳����ʼ��
{
	L= (SqList*)malloc(sizeof(SqList));
	L->length =0;
}
void Desytory(SqList *L)//���ٱ�
{
	free(L);
}
int ListEmtpy(SqList *L)//�ж��Ƿ�Ϊ��
{
	if(L->length==0)
		return 1;
}
int ListLength(SqList *L)//����˳���ĳ���
{
	return L->length;
}
void DispList(SqList *L)//���˳����ֵ
{
	int i=0;
	for(i=0;i<=L->length;i++)
		printf("%s",L->Date[i]);
}
	
int GetElem(SqList *L,int i,ElemType &e) //���ҵ�i��Ԫ��
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

