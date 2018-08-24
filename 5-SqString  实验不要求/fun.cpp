#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef struct {
	char data[MaxSize];
	int Length;
}SqString;
void InitStr(SqString *&s)
{
	s=(SqString*)malloc(sizeof(SqString));
	s->Length=0;
}
void ClearStr(SqString *&s)
{
	free(s);
}
int EmptyStr(SqString *s)
{
	return s->Length==0;
}
int StrLength(SqString *s)
{
	return s->Length;
}
void DispStr(SqString *s)
{
	int i;
	for(i=0;i!='\0';i++)
		printf("元素%3c",s->data[i]);
	printf("\n");
}
int EnStr(SqString *s,char e[])
{
	if(StrLength(s)==MaxSize)
		return 0;
	int i;
	for(i=0;i!='\0';i++)
		s->data[i]=e[i];
	printf("\n");
	return 0;
}
int InsertStr(SqString *s,int i,char e)
{
	if(StrLength(s)==MaxSize)
		return 0;	
	i--;
	int j=0;
	for(j=StrLength(s);j>i;j--)
		s->data[j]=s->data[j-1];
	s->data[i]=e;
	s->Length++;
	printf("\n");
	return 1;
}
int DeleteStr(SqString *s,int i,char e)
{
	if(EmptyStr(s))
		return 0;
	i--;
	e=s->data[i];
	for(int j=StrLength(s);j>i;j--)
		s->data[j]=s->data[j];
	s->Length--;
	printf("\n");
	return 1;
}
/*int Concat(SqString *&T,s1,s2){}*/
/*给两个串，一个串s，一个串t，eg:s="abcde",t="ab"*/
int stronp(SqString *s,SqString *t)
{
	int commLen;
	int i;
	if(StrLength(s)>StrLength(t)) commLen=StrLength(s);
	else commLen=StrLength(t);
	for(i=0;i<commLen;i++)
	{
		if(s->data[i]>t->data[i]) return -1;
		if(s->data[i]<t->data[i]) return 1;
		if(s->Length>t->Length)  return 1;
		else 
		{
			if(s->Length<t->Length) return -1;
			else return 0;
		}
	}
}
void main()
{
	SqString *s,*t;
	InitStr(s);
	InsertStr(s,1,'a');
	DispStr(s);
//	EnStr(s,t1);
	//EnStr(t,t1);
	//stronp(s,t);
}
