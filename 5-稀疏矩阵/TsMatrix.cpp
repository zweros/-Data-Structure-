
#include<stdio.h>
#define N 4
#define MaxSize 100
typedef int ElemType;
typedef struct
{
	int r;
	int c;
	ElemType d;
}TupNode;//三元组
typedef struct 
{
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;//系数矩阵
void CreateTup(TSMatrix &t,ElemType e[N][N])
{
	int i,j;t.nums=0;t.rows=t.cols=N;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(e[i][j]!=0)//只存储非零元素
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
	int p,q=0,v;      				/*q为tb.data的下标*/
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if (t.nums!=0) 
	{	
		for (v=0;v<t.cols;v++)		/*tb.data[q]中的记录以c域的次序排列*/
			for (p=0;p<t.nums;p++) 	/*p为t.data的下标*/
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
		return 0;				 /*行数或列数不等时不能进行相加运算*/
	c.rows=a.rows;c.cols=a.cols; /*c的行列数与a的相同*/
	while (i<a.nums && j<b.nums) /*处理a和b中的每个元素*/
	{	
		if (a.data[i].r==b.data[j].r)	/*行号相等时*/
		{	
			if(a.data[i].c<b.data[j].c) /*a元素的列号小于b元素的列号*/
			{	
				c.data[k].r=a.data[i].r;/*将a元素添加到c中*/
				c.data[k].c=a.data[i].c;
				c.data[k].d=a.data[i].d;
				k++;i++;
           	}
           	else if (a.data[i].c>b.data[j].c)/*a元素的列号大于b元素的列号*/
			{	
				c.data[k].r=b.data[j].r;	/*将b元素添加到c中*/
               	c.data[k].c=b.data[j].c;
               	c.data[k].d=b.data[j].d;
               	k++;j++;
           	}
           	else	/*a元素的列号等于b元素的列号*/
			{ 	
				v=a.data[i].d+b.data[j].d;
				if (v!=0)	/*只将不为0的结果添加到c中*/
				{	
					c.data[k].r=a.data[i].r;
					c.data[k].c=a.data[i].c;
					c.data[k].d=v;
					k++;
				}
				i++;j++;
          	 }
		}
     	else if (a.data[i].r<b.data[j].r) /*a元素的行号小于b元素的行号*/
		{	
			c.data[k].r=a.data[i].r;	  /*将a元素添加到c中*/
			c.data[k].c=a.data[i].c;
			c.data[k].d=a.data[i].d;
			k++;i++;
		}
    	else							  /*a元素的行号大于b元素的行号*/
		{	
			c.data[k].r=b.data[j].r;	  /*将b元素添加到c中*/
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
	if (a.cols!=b.rows)		/*a的列数不等于b的行数时不能进行相乘运算*/
		return 0;
	for (i=0;i<a.rows;i++)
		for (j=0;j<b.cols;j++) 
		{
            s=0;
            for (k=0;k<a.cols;k++)
				s=s+value(a,i,k)*value(b,k,j);
            if (s!=0)     /*产生一个三元组元素*/
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
	printf("a的三元组:\n");DispMat(a);
	printf("b的三元组:\n");DispMat(b);
	printf("a转置为c\n");
	TranMat(a,c);
	printf("c的三元组:\n");DispMat(c);
	printf("c=a+b\n");
	MatAdd(a,b,c);
	printf("c的三元组:\n");DispMat(c);
	printf("c=a*b\n");
	MatMul(a,b,c);
	printf("c的三元组:\n");DispMat(c);
}	
}
