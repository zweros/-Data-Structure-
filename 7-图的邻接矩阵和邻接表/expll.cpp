#include <stdio.h>
#include <malloc.h>
#include "graph.h"
extern void MatToList(MGraph,ALGraph *&);	/*�����ⲿ������algo9-1.cpp��*/
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
	for (i=0;i<g.vexnum;i++)		/*����ͼ9.1���ڽӾ���*/
		for (j=0;j<g.vexnum;j++)
			g.edges[i][j]=A[i][j];
	printf("\n");
	printf(" ����ͼG���ڽӾ���:\n");
	DispMat(g);
	G=(ALGraph *)malloc(sizeof(ALGraph));
	printf(" ͼG���ڽӾ���ת�����ڽӱ�:\n");
	MatToList(g,G);
	DispAdj(G);
	printf(" ͼG���ڽӱ�ת�����ڽ�����:\n");
	ListToMat(G,g1);
	DispMat(g1);
	printf("\n");
}