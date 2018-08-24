#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       /*INF表示∞*/
void MatToList(MGraph g,ALGraph *&G)
/*将邻接矩阵g转换成邻接表G*/
{
	int i,j,n=g.vexnum;					/*n为顶点数*/
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<n;i++)					/*给邻接表中所有头结点的指针域置初值*/
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)					/*检查邻接矩阵中每个元素*/
		for (j=n-1;j>=0;j--)
			if (g.edges[i][j]!=0)				/*邻接矩阵的当前元素不为0*/
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));	/*创建一个结点*p*/
				p->adjvex=j;
				p->info=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		/*将*p链到链表后*/
				G->adjlist[i].firstarc=p;
			}
	G->n=n;G->e=g.arcnum;
}
void ListToMat(ALGraph *G,MGraph &g)
/*将邻接表G转换成邻接矩阵g*/
{
	int i,j,n=G->n;
	ArcNode *p;
	for (i=0;i<n;i++)      	/*g.edges[i][j]赋初值0*/
	   	for (j=0;j<n;j++)
			g.edges[i][j]=0;
	for (i=0;i<n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=p->info;
		    p=p->nextarc;
		}
	}
	g.vexnum=n;g.arcnum=G->e;
}
void DispMat(MGraph g)
/*输出邻接矩阵g*/
{
	int i,j;
	for (i=0;i<g.vexnum;i++)
	{
		for (j=0;j<g.vexnum;j++)
			if (g.edges[i][j]==INF)
				printf("%3s","∞");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj(ALGraph *G)
/*输出邻接表G*/
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		if (p!=NULL) printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
