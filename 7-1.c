#include<stdio.h>
#include<stdlib.h>
#define MAXPOINT 100 
struct map
{
	int point;
	struct map *next;	
};
struct map *map[MAXPOINT]={};
int visited[MAXPOINT]={};
void addEdge(int,int);
void DFS(int);
void BFS(int);
int main()
{
	int m,n,i;
	scanf("%d%d",&m,&n);
	int pt1=0,pt2=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&pt1,&pt2);
		addEdge(pt1,pt2);
		addEdge(pt2,pt1); 
	}
	int del;
	scanf("%d",&del);
	DFS(0);
	printf("\n");
	for(i=0;i<m;i++) visited[i]=0;
	BFS(0);
	printf("\n");
	for(i=0;i<m;i++) visited[i]=0;
	map[del]=NULL;
	visited[del]=1;
	DFS(0);
	printf("\n");
	for(i=0;i<m;i++) visited[i]=0;
	visited[del]=1;
	BFS(0);
	return 0;
}
void addEdge(int pt1,int pt2)
{
	struct map *p=NULL,*q=NULL,*r=NULL;
	p=(struct map*)malloc(sizeof(struct map));
	p->point=pt2;
	p->next=NULL;
	if(map[pt1]==NULL||pt2<map[pt1]->point)
	{
		p->next=map[pt1];
		map[pt1]=p;
	}
	else
	{
		r=map[pt1];
		q=map[pt1]->next;
		while(q!=NULL&&pt2>q->point)
		{
			r=q;
			q=q->next;
		}
		r->next=p;
		p->next=q;
	}
	return;
}
void DFS(int pt)
{
	if(visited[pt]==0)
	{
		visited[pt]=1;
		printf("%d ",pt);
		struct map *p=NULL;
		p=map[pt];
		while(p!=NULL)
		{
			DFS(p->point);
			p=p->next;
		}
	}
	return;
}
void BFS(int pt)
{
	int queue[MAXPOINT]={};
	int front=-1,rear=-1;
	rear++;
	queue[rear]=pt;
	visited[pt]=1;
	struct map *p=NULL;
	while(front!=rear)
	{
		front++;
		p=map[queue[front]];
		printf("%d ",queue[front]);
		while(p!=NULL)
		{
			if(visited[p->point]==0)
			{
				rear++;
				queue[rear]=p->point;
				visited[p->point]=1;
			}
			p=p->next;
		}
	}
	return; 
}
