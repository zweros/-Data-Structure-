#include <stdio.h>
#include <malloc.h>
#include "graph.h"
extern void MatToList(MGraph,ALGraph *&);	/*以下外部函数在algo9-1.cpp中*/
extern void ListToMat(ALGraph *,MGraph &);
extern void DispMat(MGraph);
extern void DispAdj(ALGraph *);
void main()
{
	int i,j;
	MGraph g,g1;
	ALGraph *G;
	int A[MAXV][6]={
		{0,5,0,7,0,0},
		{0,0,4,0,0,0},
		{8,0,0,0,0,9},
		{0,0,5,0,0,6},
		{0,0,0,5,0,0},
		{3,0,0,0,1,0}};
	g.vexnum=6;g.arcnum=10;
	for (i=0;i<g.vexnum;i++)		/*建立图9.1的邻接矩阵*/
		for (j=0;j<g.vexnum;j++)
			g.edges[i][j]=A[i][j];
	printf("\n");
	printf(" 有向图G的邻接矩阵:\n");
	DispMat(g);
	G=(ALGraph *)malloc(sizeof(ALGraph));
	printf(" 图G的邻接矩阵转换成邻接表:\n");
	MatToList(g,G);
	DispAdj(G);
	printf(" 图G的邻接表转换成邻接邻阵:\n");
	ListToMat(G,g1);
	DispMat(g1);
	printf("\n");
}