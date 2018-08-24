	
#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;
void CreateBTNode(BTNode *&b,char *str)		/*��str������������*///�������Ž����Һ��ӣ����������ŷ�ջ��K=1�������ӣ�eg,�����ұ�����ջ��Ԫ�س�ջһ������ʱK=2�����Һ��ӡ�Whileѭ��������ȡ�ַ���ֱ��������\0������str[j]�ַ������飬default�����������������ĸ��
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  //����ջ
	char ch;
	b=NULL;				/*�����Ķ�������ʼʱΪ��*/
	ch=str[j];
	while (ch!='\0')	/*strδɨ����ʱѭ��*/
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		/*Ϊ����*/
		case ')':top--;break;
		case ',':k=2; break;                      	/*Ϊ�ҽ��*/
		default:p=(BTNode *)malloc(sizeof(BTNode));
			p->data=ch;p->lchild=p->rchild=NULL;
		         	if (b==NULL)                    /*pָ��������ĸ����*/
						b=p;
					else  							/*�ѽ��������������*/
					{	
						switch(k) 
						{
						case 1:St[top]->lchild=p;break;
						case 2:St[top]->rchild=p;break;
						}
					}
		}
		j++;
		ch=str[j];
	}
}
void DispBTNode(BTNode *b)	/*�����ű�ʾ�����������*///�ݹ��㷨
{
	if (b!=NULL)//b���ڵ�ָ��
	{
		printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispBTNode(b->lchild);
			if (b->rchild!=NULL) printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}
void  CreateTree(BTNode *t)
{
	char ch;
	cin>>ch;
	if(ch=='#')   t=NULL;
	else
	{
		t=(BTNode*)malloc(sizeof(BTNode));
		t->data=ch;
		CreateTree(t->lchild);
		CreateTree(t->rchild);
	}
}

int node=0;
void nonode(BTNode *t)//������������еĽ��ĸ���
{
	if(t!=NULL)
	{
		nonode(t->lchild);	
		node++;
		nonode(t->rchild);
	}
}
int  nonodes(BTNode *t)//������������еĽ��ĸ���
{
	if(t==NULL) return 0;//�ݹ����
	return nonodes(t->lchild)+nonodes(t->rchild)+1;
}
int nonodes1(BTNode *t)//������������ж�Ϊ1�Ľ��
{
	if(t==NULL) return 0;
	if((t->lchild==NULL&&t->rchild!=NULL)||(t->lchild!=NULL&&t->rchild==NULL)) 
		return nonodes1(t->lchild)+nonodes1(t->rchild)+1;
	else
     	return nonodes1(t->lchild)+nonodes1(t->rchild);
}
int node1=0;
void nonode1(BTNode *t)//������������ж�Ϊ1�Ľ��
{
	if(t)
	{
		if(t->lchild&&!t->rchild||(!t->lchild&&t->rchild))
			node1++;
		nonode1(t->rchild);
		nonode1(t->lchild);	
	
	}
}
int node2=0;
void nonode2(BTNode *t)//������������ж�Ϊ2�Ľ��
{
	if(t!=NULL)
	{	
		nonode2(t->rchild);
		if(t->lchild!=NULL&&t->rchild!=NULL)
			node2++;
		nonode2(t->lchild);
		
	}
}
int nonodes2(BTNode *t)
{
	if(t==NULL) return 0;
	if(t->lchild!=NULL&&t->rchild!=NULL) 
		return nonodes2(t->lchild)+nonodes2(t->rchild)+1;
	else
     	return nonodes2(t->lchild)+nonodes2(t->rchild);
}
int deaf=0;
void Deafnode(BTNode *t)//������������е�Ҷ�ӽ��
{
	if(t!=NULL)
	{
		
		if(t->lchild==NULL&&t->rchild==NULL)
			  cout<<t->data;
		else
		{
			Deafnode(t->lchild);
			Deafnode(t->rchild);
		}
	
	}
}

void Deafnodes(BTNode *t)//������������е�Ҷ�ӽ��ĸ���
{	
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
			  deaf++;
		else
		{
			Deafnodes(t->lchild);
			Deafnodes(t->rchild);
		}
	}
}
int Deafnodess(BTNode *t)//������������е�Ҷ�ӽ��ĸ���
{	
	if(t==NULL) return 0;
		if(t->lchild==NULL&&t->rchild==NULL)
			  return Deafnodess(t->lchild)+Deafnodess(t->rchild)+1;
		else
			return Deafnodess(t->lchild)+Deafnodess(t->rchild);
}
void main()
{
	BTNode *t;
	char *str="A((B(D,E(H(J,K(L,M(,N)))))),C(F,G(,I)))";
	CreateBTNode(t,str);
	cout<<"���������: ";DispBTNode(t);cout<<endl;
	cout<<"������������е�Ҷ��:";Deafnode(t);cout<<endl;
	Deafnodes(t);cout<<"������������е�Ҷ�ӽ��:"<<deaf<<endl;
				cout<<"������������е�Ҷ�ӽ��:"<<Deafnodess(t)<<endl;

	nonode(t);cout<<"������������еĽ��ĸ���:"<<node<<endl;
	          cout<<"������������еĽ��ĸ���:"<<nonodes(t)<<endl;

	nonode2(t); cout<<"������������ж�Ϊ2�Ľ�����:"<<node2<<endl;
				cout<<"������������ж�Ϊ2�Ľ�����:"<<nonodes2(t)<<endl;
				
 				
	nonode1(t);cout<<"������������ж�Ϊ1�Ľ�����:"<<node1<<endl;
          cout<<"������������ж�Ϊ1�Ľ�����:"<<nonodes1(t)<<endl;
	

			
}
