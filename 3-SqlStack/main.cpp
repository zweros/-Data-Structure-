#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
#define MaxSize 100
typedef struct Stack{
	ElemType data[MaxSize];
	int top;
}SqStack;
extern void InitStack(SqStack *&S);
extern void ClearStack(SqStack *&S);
extern int StackLength(SqStack *S);
extern int EmptyStack(SqStack *S);
extern int Push(SqStack *&S,ElemType e);
extern int Pop(SqStack *&S,ElemType e);
extern int GetTop(SqStack *S,ElemType &e);
extern void DispStack(SqStack *S);
extern void Conversion(SqStack *S,int N,ElemType e);
void main()
{
	SqStack *S;
	SqStack *T;
	ElemType e;
	int i;
	printf("(1)��ʼ����ջS\n");
	InitStack(S);InitStack(T);
	printf("(2)�жϸ�ջS�Ƿ�Ϊ��:");
	if(	EmptyStack(S))
		printf("��ջSΪ��\n");
	else 
		printf("��ջS��Ϊ��");
	printf("(3)���ν�ջԪ��a,b,c,d,e\n");
	Push(S,'a');
	Push(S,'b');
	Push(S,'c');
	Push(S,'d');
	Push(S,'e');
	printf("(4)�жϸ�ջS�Ƿ�Ϊ��:");
	if(	EmptyStack(S))
		printf("��ջSΪ��\n");
	else 
		printf("��ջS��Ϊ��\n");
	printf("(5)���ջS�ĳ���:%d\n",StackLength(S));
	printf("(6)�����Sջ�е�����Ԫ��:");
	DispStack(S);
	printf("(7)�����վ����:");
	for(i=0;i<=S->top;i++)
		printf("%3d",i);
	printf("\n");
	printf("(8)�ж�ջ�Ƿ�Ϊ��:");
	if(	EmptyStack(S))
		printf("��SջΪ��\n");
	else 
		printf("��Sջ��Ϊ��\n");
	InitStack(T);
	printf("����ת��:\n");
	Conversion(T,117,e);
	ClearStack(S);
}	
