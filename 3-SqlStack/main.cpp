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
	printf("(1)初始化该栈S\n");
	InitStack(S);InitStack(T);
	printf("(2)判断该栈S是否为空:");
	if(	EmptyStack(S))
		printf("该栈S为空\n");
	else 
		printf("该栈S不为空");
	printf("(3)依次进栈元素a,b,c,d,e\n");
	Push(S,'a');
	Push(S,'b');
	Push(S,'c');
	Push(S,'d');
	Push(S,'e');
	printf("(4)判断该栈S是否为空:");
	if(	EmptyStack(S))
		printf("该栈S为空\n");
	else 
		printf("该栈S不为空\n");
	printf("(5)输出栈S的长度:%d\n",StackLength(S));
	printf("(6)输出该S栈中的所有元素:");
	DispStack(S);
	printf("(7)输出出站序列:");
	for(i=0;i<=S->top;i++)
		printf("%3d",i);
	printf("\n");
	printf("(8)判断栈是否为空:");
	if(	EmptyStack(S))
		printf("该S栈为空\n");
	else 
		printf("该S栈不为空\n");
	InitStack(T);
	printf("进制转换:\n");
	Conversion(T,117,e);
	ClearStack(S);
}	
