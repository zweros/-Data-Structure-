#include <stdio.h>
#include <malloc.h>
#include "graph.h"
int visited[MAXV];						/*ȫ������*/
void DFS(ALGraph *G,int v) 
{
	ArcNode *p;
	visited[v]=1;                   	/*���ѷ��ʱ��*/
	printf("%3d",v); 					/*��������ʶ���ı��*/
	p=G->adjlist[v].firstarc;      		/*pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���*/
	while (p!=NULL) 
	{	
		if (visited[p->adjvex]==0)		/*��p->adjvex����δ����,�ݹ������*/
			DFS(G,p->adjvex);    
		p=p->nextarc;              		/*pָ�򶥵�v����һ�����Ļ�ͷ���*/
	}
}
void DFS1(ALGraph *G,int v)
{
	int i,visited[MAXV],St[MAXV],top=-1;
	ArcNode *p;
    for (i=0;i<G->n;i++) 
		visited[i]=0;				/*�����ʱ�־���ó�0*/
    printf("%3d",v);				/*���ʶ���v*/
	top++;							/*v��ջ*/
	St[top]=v;
	visited[v]=1;
	while (top>=-1)					/*ջ����ʱѭ��*/
	{
		v=St[top];top--;			/*ȡջ������*/
		p=G->adjlist[v].firstarc;
        while (p!=NULL && visited[p->adjvex]==1)
    		   p=p->nextarc;
        if (p==NULL)				/*��û���˵�ǰһ��*/
			top--;
		else						/*����,ѡ��һ��*/
		{
			v=p->adjvex;
			printf("%3d",v);		/*���ʶ���*/
			visited[v]=1;
			top++;					/*��ջ*/
			St[top]=v;
		}
	}
	printf("\n");
}   
void BFS(ALGraph *G,int v)  
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;			/*����ѭ�����в���ʼ��*/
	int visited[MAXV];            			/*�����Ž��ķ��ʱ�־������*/
	int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;		/*���ʱ�־�����ʼ��*/
	printf("%3d",v); 						/*��������ʶ���ı��*/
	visited[v]=1;              				/*���ѷ��ʱ��*/
	rear=(rear+1)%MAXV;
	queue[rear]=v;             				/*v����*/
	while (front!=rear)       				/*�����в���ʱѭ��*/
	{	
		front=(front+1)%MAXV;
		w=queue[front];       				/*���Ӳ�����w*/
		p=G->adjlist[w].firstarc; 			/*���붥��w�ڽӵĵ�һ������*/
		while (p!=NULL) 
		{	
			if (visited[p->adjvex]==0) 		/*����ǰ�ڽӶ���δ������*/
			{	
				printf("%3d",p->adjvex);  	/*�������ڶ���*/
				visited[p->adjvex]=1;		/*�øö����ѱ����ʵı�־*/
				rear=(rear+1)%MAXV;			/*�ö������*/
				queue[rear]=p->adjvex; 		
           	}
           	p=p->nextarc;              		/*����һ���ڽӶ���*/
		}
	}
	printf("\n");
}
