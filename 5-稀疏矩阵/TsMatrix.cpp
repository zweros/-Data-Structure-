
#include<stdio.h>
#define N 4
#define MaxSize 100
typedef int ElemType;
typedef struct
{
	int r;
	int c;
	ElemType d;
}TupNode;//��Ԫ��
typedef struct 
{
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;//ϵ������
void CreateTup(TSMatrix &t,ElemType e[N][N])
{
	int i,j;t.nums=0;t.rows=t.cols=N;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(e[i][j]!=0)//ֻ�洢����Ԫ��
			{
				t.data[t.nums].r=i;
				t.data[t.nums].c=j;
				t.data[t.nums].d=e[i][j];
				t.nums++;
			}
}
void DispMa(TSMatrix t)
{
	if(t.nums==0)
		return;
	int i;
	printf("%3d%3d%3d\n",t.rows,t.cols,t.nums);
	for(i=0;i<t.nums;i++)
	{
		printf("(%3d,%3d,%3d)",t.data[i].r,t.data[i].c,t.data[i].d);
		printf("\n");
	}
	printf("\n");
}
void TranMat(TSMatrix t,TSMatrix &tb)
{
	int p,q=0,v;      				/*qΪtb.data���±�*/
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if (t.nums!=0) 
	{	
		for (v=0;v<t.cols;v++)		/*tb.data[q]�еļ�¼��c��Ĵ�������*/
			for (p=0;p<t.nums;p++) 	/*pΪt.data���±�*/
				if (t.data[p].c==v) 
				{	
					tb.data[q].r=t.data[p].c;
					tb.data[q].c=t.data[p].r;
					tb.data[q].d=t.data[p].d;
					q++;
				}
	}
}
int MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c)
{
	int i=0,j=0,k=0;
	ElemType v;
	if (a.rows!=b.rows || a.cols!=b.cols)
		return 0;				 /*��������������ʱ���ܽ����������*/
	c.rows=a.rows;c.cols=a.cols; /*c����������a����ͬ*/
	while (i<a.nums && j<b.nums) /*����a��b�е�ÿ��Ԫ��*/
	{	
		if (a.data[i].r==b.data[j].r)	/*�к����ʱ*/
		{	
			if(a.data[i].c<b.data[j].c) /*aԪ�ص��к�С��bԪ�ص��к�*/
			{	
				c.data[k].r=a.data[i].r;/*��aԪ����ӵ�c��*/
				c.data[k].c=a.data[i].c;
				c.data[k].d=a.data[i].d;
				k++;i++;
           	}
           	else if (a.data[i].c>b.data[j].c)/*aԪ�ص��кŴ���bԪ�ص��к�*/
			{	
				c.data[k].r=b.data[j].r;	/*��bԪ����ӵ�c��*/
               	c.data[k].c=b.data[j].c;
               	c.data[k].d=b.data[j].d;
               	k++;j++;
           	}
           	else	/*aԪ�ص��кŵ���bԪ�ص��к�*/
			{ 	
				v=a.data[i].d+b.data[j].d;
				if (v!=0)	/*ֻ����Ϊ0�Ľ����ӵ�c��*/
				{	
					c.data[k].r=a.data[i].r;
					c.data[k].c=a.data[i].c;
					c.data[k].d=v;
					k++;
				}
				i++;j++;
          	 }
		}
     	else if (a.data[i].r<b.data[j].r) /*aԪ�ص��к�С��bԪ�ص��к�*/
		{	
			c.data[k].r=a.data[i].r;	  /*��aԪ����ӵ�c��*/
			c.data[k].c=a.data[i].c;
			c.data[k].d=a.data[i].d;
			k++;i++;
		}
    	else							  /*aԪ�ص��кŴ���bԪ�ص��к�*/
		{	
			c.data[k].r=b.data[j].r;	  /*��bԪ����ӵ�c��*/
			c.data[k].c=b.data[j].c;
			c.data[k].d=b.data[j].d;
			k++;j++;
     	}
     	//c.nums=k;
	}
	if (i<a.nums)
		for(t=i;t<a.nums;t++)
		{ c.data[k].r=a.data[t].r;
	      c.data[k].c=a.data[t].c;
		  c.data[k].d=a.data[t].d;
		k++;}
	if (j<b.nums)
		for(t=j;t<b.nums;t++)
		{ c.data[k].r=b.data[t].r;
	      c.data[k].c=b.data[t].c;
		  c.data[k].d=b.data[t].d;
		k++;}
	c.nums=k;
	return 1;
}
int value(TSMatrix c,int i,int j)
{
    int k=0;
    while (k<c.nums && (c.data[k].r!=i || c.data[k].c!=j)) 
		k++;
    if (k<c.nums) 
		return(c.data[k].d);
    else 
		return(0);
}
int MatMul(TSMatrix a,TSMatrix b,TSMatrix &c)
{
    int i,j,k,p=0;
	ElemType s;
	if (a.cols!=b.rows)		/*a������������b������ʱ���ܽ����������*/
		return 0;
	for (i=0;i<a.rows;i++)
		for (j=0;j<b.cols;j++) 
		{
            s=0;
            for (k=0;k<a.cols;k++)
				s=s+value(a,i,k)*value(b,k,j);
            if (s!=0)     /*����һ����Ԫ��Ԫ��*/
            {
                c.data[p].r=i;
                c.data[p].c=j;
                c.data[p].d=s;
                p++;
            }
        }
	c.rows=a.rows; 
	c.cols=b.cols;
	c.nums=p;
	return 1;
}
void main()
{
	ElemType a1[N][N]={{1,0,3,0},{0,1,0,0},{0,0,1,0},{0,0,1,0}};
	ElemType b1[N][N]={{3,0,0,0},{0,4,0,0},{0,0,1,0},{0,0,0,2}};
	TSMatrix a,b,c;
	CreatMat(a,a1);
	CreatMat(b,b1);
	printf("a����Ԫ��:\n");DispMat(a);
	printf("b����Ԫ��:\n");DispMat(b);
	printf("aת��Ϊc\n");
	TranMat(a,c);
	printf("c����Ԫ��:\n");DispMat(c);
	printf("c=a+b\n");
	MatAdd(a,b,c);
	printf("c����Ԫ��:\n");DispMat(c);
	printf("c=a*b\n");
	MatMul(a,b,c);
	printf("c����Ԫ��:\n");DispMat(c);
}	
}
