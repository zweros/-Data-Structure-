#include <stdio.h>
#include <malloc.h>
#include "graph.h"
extern void MatToList(MGraph,ALGraph *&);	/*以下外部函数在algo9-1.cpp中*/
extern void DispAdj(ALGraph *G);
extern void DFS(ALGraph *G,int v);			/*以下外部函数在algo9-2.cpp中*/
extern void DFS1(ALGraph *G,int v);
extern void BFS(ALGraph *G,int v);
void main()
{
	int i,j;
	MGraph g;
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
	G=(ALGraph *)malloc(sizeof(ALGraph));
	MatToList(g,G);					/*图G的邻接矩阵转换成邻接表*/
	printf("图G的邻接表:\n");
	DispAdj(G);
	printf("从顶点0开始的DFS(递归算法):\n");
	DFS(G,0);printf("\n");
	printf("从顶点0开始的DFS(非递归算法):\n");
	DFS1(G,0);
	printf("从顶点0开始的BFS(递归算法):\n");
	BFS(G,0);printf("\n");
}
