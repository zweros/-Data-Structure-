#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       /*INF��ʾ��*/
void MatToList(MGraph g,ALGraph *&G)
/*���ڽӾ���gת�����ڽӱ�G*/
{
	int i,j,n=g.vexnum;					/*nΪ������*/
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<n;i++)					/*���ڽӱ�������ͷ����ָ�����ó�ֵ*/
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)					/*����ڽӾ�����ÿ��Ԫ��*/
		for (j=n-1;j>=0;j--)
			if (g.edges[i][j]!=0)				/*�ڽӾ���ĵ�ǰԪ�ز�Ϊ0*/
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));	/*����һ�����*p*/
				p->adjvex=j;
				p->info=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		/*��*p���������*/
				G->adjlist[i].firstarc=p;
			}
	G->n=n;G->e=g.arcnum;
}
void ListToMat(ALGraph *G,MGraph &g)
/*���ڽӱ�Gת�����ڽӾ���g*/
{
	int i,j,n=G->n;
	ArcNode *p;
	for (i=0;i<n;i++)      	/*g.edges[i][j]����ֵ0*/
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
/*����ڽӾ���g*/
{
	int i,j;
	for (i=0;i<g.vexnum;i++)
	{
		for (j=0;j<g.vexnum;j++)
			if (g.edges[i][j]==INF)
				printf("%3s","��");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj(ALGraph *G)
/*����ڽӱ�G*/
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
