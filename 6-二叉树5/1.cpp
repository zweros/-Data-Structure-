
#include <stdio.h>
#include <iostream.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;		        /*数据元素*/
	struct node *lchild;		/*指向左孩子*/
	struct node *rchild;		/*指向右孩子*/
} BTNode;
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
void CreateBTNode2(BTNode *t)
{
	char ch;
	cin>>ch;
	if(ch=='#')  t=NULL;//递归出口
	else{
		t=(BTNode*)malloc(sizeof(BTNode));
		t->data=ch;
		CreateBTNode2(t->lchild);
		CreateBTNode2(t->rchild);
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
void Displeaf(BTNode *t)//输出二叉树中所有的叶子
{
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
			cout<<t->data;
		else{
			Displeaf(t->lchild);
			Displeaf(t->rchild);
		}
	}
}
int leaf=0;//输出叶子结点的值
void Displeafvalue(BTNode *t)
{
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
			leaf++;
		else{
			Displeafvalue(t->lchild);
			Displeafvalue(t->rchild);
		}
	}
}
void leftvalue(BTNode *t)
{
	if(t!=NULL)
	{
		if(t->lchild->data=='H')
				cout<<t->lchild->data<<'\t'<<t->rchild->data<<endl;
		leftvalue(t->lchild->lchild);
		leftvalue(t->rchild->rchild);		
	}

}
void InOrder(BTNode *t)//中序遍历
{
	if(t!=NULL)
	{
		InOrder(t->lchild);
		cout<<t->data;
		InOrder(t->rchild);
	}
}
void PostOrder(BTNode *t)//后序遍历
{
	if(t!=NULL)
	{
		PostOrder(t->lchild);
		PostOrder(t->rchild);
		cout<<t->data;
	}
}
void PreOrder(BTNode *t)//先序遍历
{
	if(t!=NULL)
	{
		cout<<t->data;
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}
int n2=0;//统计度为2的结点总数
void CaNode2(BTNode *t)
{
	if(t!=NULL)
	{
		CaNode2(t->lchild);
		if(t->lchild!=NULL&&t->rchild!=NULL)
					n2++;
		CaNode2(t->rchild);
	}
}
int Nodeno1(BTNode *t)//统计结点的个数
{
	int lno,rno;
	if(t==NULL) return 0;
	lno=Nodeno1(t->lchild);
	rno=Nodeno1(t->rchild);
	return lno+rno+1;
}

int d=0;
void Nodeno2(BTNode *t)//统计结点的个数
{
	if(t!=NULL)
	{
		Nodeno2(t->lchild);
		d++;
		Nodeno2(t->rchild);
	}
}
int DepthBTNode(BTNode *&t)//计算二叉树的深度
{
	int m=0,n=0;
	if(t==NULL) return 0;
	m=DepthBTNode(t->lchild);
	n=DepthBTNode(t->rchild);
	return m>n?m+1:n+1;
				
}
void PreOrder1(BTNode *t)
{
	BTNode *St[MaxSize],*p;
	int top=-1;
	if(t!=NULL)
	{
		top++;St[top]=t;//指向根节点
		while(top>-1)
		{
			p=St[top];top--;
			cout<<p->data;
			if(p->rchild!=NULL)/*根据栈先进后出的规律，右孩子先进去，左孩子后进去*/
			{
				top++;St[top]=p->rchild;
			}
			if(p->lchild!=NULL)
			{
				top++;
				St[top]=p->lchild;
			}
		}
	}
}
void main()
{
	BTNode *t;
	char *str="A((B(D,E(H(J,K(L,M(,N)))))),C(F,G(,I)))";
	CreateBTNode(t,str);
	cout<<"(1)括号表示法输出二叉树:";DispBTNode(t);cout<<endl;
//	cout<<"(2)输出‘H’结点的左、右孩子结点的值";Dispthenode(t,'H');cout<<endl;
	cout<<"(3)输出二叉树的深度: "<<DepthBTNode(t)<<endl;
	cout<<"(4)输出二叉树的结点总数: "; cout<<Nodeno1(t)<<endl;
	cout<<"(4)输出二叉树的结点总数: "; Nodeno2(t);cout<<d<<endl;
	cout<<"(4)输出度为二的结点总数: ";CaNode2(t);cout<<n2<<endl;
	cout<<"(5)输出叶子结点的个数: ";Displeafvalue(t);cout<<leaf<<endl;
	cout<<"先序遍历: ";PreOrder(t);cout<<endl;
	cout<<"非递归模拟栈先序遍历: ";PreOrder1(t);cout<<endl;
	cout<<"中序遍历: ";InOrder(t);cout<<endl;
	cout<<"后序遍历: ";PostOrder(t);cout<<endl;


}