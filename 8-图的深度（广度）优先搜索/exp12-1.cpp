#include <stdio.h>
#include <malloc.h>
#include "graph.h"
extern void MatToList(MGraph,ALGraph *&);	/*�����ⲿ������algo9-1.cpp��*/
extern void DispAdj(ALGraph *G);
extern void DFS(ALGraph *G,int v);			/*�����ⲿ������algo9-2.cpp��*/
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
	for (i=0;i<g.vexnum;i++)		/*����ͼ9.1���ڽӾ���*/
		for (j=0;j<g.vexnum;j++)
			g.edges[i][j]=A[i][j];
	G=(ALGraph *)malloc(sizeof(ALGraph));
	MatToList(g,G);					/*ͼG���ڽӾ���ת�����ڽӱ�*/
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);
	printf("�Ӷ���0��ʼ��DFS(�ݹ��㷨):\n");
	DFS(G,0);printf("\n");
	printf("�Ӷ���0��ʼ��DFS(�ǵݹ��㷨):\n");
	DFS1(G,0);
	printf("�Ӷ���0��ʼ��BFS(�ݹ��㷨):\n");
	BFS(G,0);printf("\n");
}
