	
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
void CreateBTNode(BTNode *&b,char *str)		/*由str串创建二叉链*///遇到逗号建立右孩子，遇到左括号放栈里K=1代表左孩子，eg,遇到右边括号栈顶元素出栈一个，此时K=2代表右孩子。While循环代表不断取字符，直到遇到’\0’结束str[j]字符串数组，default即其他情况即遇到字母了
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  //代表栈
	char ch;
	b=NULL;				/*建立的二叉树初始时为空*/
	ch=str[j];
	while (ch!='\0')	/*str未扫描完时循环*/
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		/*为左结点*/
		case ')':top--;break;
		case ',':k=2; break;                      	/*为右结点*/
		default:p=(BTNode *)malloc(sizeof(BTNode));
			p->data=ch;p->lchild=p->rchild=NULL;
		         	if (b==NULL)                    /*p指向二叉树的根结点*/
						b=p;
					else  							/*已建立二叉树根结点*/
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
void DispBTNode(BTNode *b)	/*以括号表示法输出二叉树*///递归算法
{
	if (b!=NULL)//b根节点指针
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
void nonode(BTNode *t)//求二叉树中所有的结点的个数
{
	if(t!=NULL)
	{
		nonode(t->lchild);	
		node++;
		nonode(t->rchild);
	}
}
int  nonodes(BTNode *t)//求二叉树中所有的结点的个数
{
	if(t==NULL) return 0;//递归出口
	return nonodes(t->lchild)+nonodes(t->rchild)+1;
}
int nonodes1(BTNode *t)//求二叉树中所有度为1的结点
{
	if(t==NULL) return 0;
	if((t->lchild==NULL&&t->rchild!=NULL)||(t->lchild!=NULL&&t->rchild==NULL)) 
		return nonodes1(t->lchild)+nonodes1(t->rchild)+1;
	else
     	return nonodes1(t->lchild)+nonodes1(t->rchild);
}
int node1=0;
void nonode1(BTNode *t)//求二叉树中所有度为1的结点
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
void nonode2(BTNode *t)//求二叉树中所有度为2的结点
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
void Deafnode(BTNode *t)//求二叉树中所有的叶子结点
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

void Deafnodes(BTNode *t)//求二叉树中所有的叶子结点的个数
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
int Deafnodess(BTNode *t)//求二叉树中所有的叶子结点的个数
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
	cout<<"输出二叉树: ";DispBTNode(t);cout<<endl;
	cout<<"求二叉树中所有的叶子:";Deafnode(t);cout<<endl;
	Deafnodes(t);cout<<"求二叉树中所有的叶子结点:"<<deaf<<endl;
				cout<<"求二叉树中所有的叶子结点:"<<Deafnodess(t)<<endl;

	nonode(t);cout<<"求二叉树中所有的结点的个数:"<<node<<endl;
	          cout<<"求二叉树中所有的结点的个数:"<<nonodes(t)<<endl;

	nonode2(t); cout<<"求二叉树中所有度为2的结点个数:"<<node2<<endl;
				cout<<"求二叉树中所有度为2的结点个数:"<<nonodes2(t)<<endl;
				
 				
	nonode1(t);cout<<"求二叉树中所有度为1的结点个数:"<<node1<<endl;
          cout<<"求二叉树中所有度为1的结点个数:"<<nonodes1(t)<<endl;
	

			
}
