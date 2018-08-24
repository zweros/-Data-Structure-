
#include <stdio.h>
#include <iostream.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;		        /*����Ԫ��*/
	struct node *lchild;		/*ָ������*/
	struct node *rchild;		/*ָ���Һ���*/
} BTNode;
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
void CreateBTNode2(BTNode *t)
{
	char ch;
	cin>>ch;
	if(ch=='#')  t=NULL;//�ݹ����
	else{
		t=(BTNode*)malloc(sizeof(BTNode));
		t->data=ch;
		CreateBTNode2(t->lchild);
		CreateBTNode2(t->rchild);
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
void Displeaf(BTNode *t)//��������������е�Ҷ��
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
int leaf=0;//���Ҷ�ӽ���ֵ
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
void InOrder(BTNode *t)//�������
{
	if(t!=NULL)
	{
		InOrder(t->lchild);
		cout<<t->data;
		InOrder(t->rchild);
	}
}
void PostOrder(BTNode *t)//�������
{
	if(t!=NULL)
	{
		PostOrder(t->lchild);
		PostOrder(t->rchild);
		cout<<t->data;
	}
}
void PreOrder(BTNode *t)//�������
{
	if(t!=NULL)
	{
		cout<<t->data;
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}
int n2=0;//ͳ�ƶ�Ϊ2�Ľ������
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
int Nodeno1(BTNode *t)//ͳ�ƽ��ĸ���
{
	int lno,rno;
	if(t==NULL) return 0;
	lno=Nodeno1(t->lchild);
	rno=Nodeno1(t->rchild);
	return lno+rno+1;
}

int d=0;
void Nodeno2(BTNode *t)//ͳ�ƽ��ĸ���
{
	if(t!=NULL)
	{
		Nodeno2(t->lchild);
		d++;
		Nodeno2(t->rchild);
	}
}
int DepthBTNode(BTNode *&t)//��������������
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
		top++;St[top]=t;//ָ����ڵ�
		while(top>-1)
		{
			p=St[top];top--;
			cout<<p->data;
			if(p->rchild!=NULL)/*����ջ�Ƚ�����Ĺ��ɣ��Һ����Ƚ�ȥ�����Ӻ��ȥ*/
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
	cout<<"(1)���ű�ʾ�����������:";DispBTNode(t);cout<<endl;
//	cout<<"(2)�����H���������Һ��ӽ���ֵ";Dispthenode(t,'H');cout<<endl;
	cout<<"(3)��������������: "<<DepthBTNode(t)<<endl;
	cout<<"(4)����������Ľ������: "; cout<<Nodeno1(t)<<endl;
	cout<<"(4)����������Ľ������: "; Nodeno2(t);cout<<d<<endl;
	cout<<"(4)�����Ϊ���Ľ������: ";CaNode2(t);cout<<n2<<endl;
	cout<<"(5)���Ҷ�ӽ��ĸ���: ";Displeafvalue(t);cout<<leaf<<endl;
	cout<<"�������: ";PreOrder(t);cout<<endl;
	cout<<"�ǵݹ�ģ��ջ�������: ";PreOrder1(t);cout<<endl;
	cout<<"�������: ";InOrder(t);cout<<endl;
	cout<<"�������: ";PostOrder(t);cout<<endl;


}