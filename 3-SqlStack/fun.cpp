

#include<stdio.h>
#include<iostream.h>
#include<malloc.h>
typedef char ElemType;
#define MaxSize 100
typedef struct Stack{
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack *&S)
{
	S=(SqStack*)malloc(sizeof(SqStack));
	S->top=-1;
}
void ClearStack(SqStack *&S)
{
	free(S);
}
int StackLength(SqStack *S)
{
	return (S->top+1);
}
int EmptyStack(SqStack *S)
{
	return (S->top==-1);
}
int Push(SqStack *&S,ElemType e)
{
	
	if(S->top==MaxSize) 
		return 0;
	S->top++;
	S->data[S->top]=e;
	return e;
}
int Pop(SqStack *&S,ElemType e)
{
	 if(S->top==-1)
		 return 0;
	 e=S->data[S->top];
	 S->top--;
	 return e;
}
int GetTop(SqStack *S,ElemType &e)
{	
	if(EmptyStack(S))
		return  0;
	e=S->data[S->top];
	return e;
}
void DispStack(SqStack *S)
{
	int i=0;
	while(i!=S->top+1)
	{
		printf("%c\t",S->data[i]);
		i++;
	}
	printf("\n");
}
void Conversion(SqStack *S,int N,ElemType e)
{
	while(N!=0)
	{
		Push(S,N%8);
		N=N/8;
	}
	printf("十进制转八进制:");
	while(S->top!=-1)
	{
		e=Pop(S,e);
		printf("%d",e);
	}
	printf("\n");
}
