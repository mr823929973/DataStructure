#include<stdio.h>
#include<stdlib.h>
#define MAXEDGE 1000
struct edge
{
	int num;
	int point;
	struct edge *next;
};
struct edge *map[MAXEDGE]={};
int route[MAXEDGE]={};
int visited[MAXEDGE]={};
void edgeAdd(int,int,int);
void DFS(int,int,int);
int main()
{
	int n,e,i;
	int eno,v1,v2;
	scanf("%d%d",&n,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&eno,&v1,&v2);
		edgeAdd(eno,v1,v2);
		edgeAdd(eno,v2,v1);
	}
	DFS(0,n-1,-1);	
	return 0;
}
void edgeAdd(int eno,int v1,int v2)
{
	struct edge *p=NULL,*q=NULL,*r=NULL;
	p=(struct edge *)malloc(sizeof(struct edge));
	p->next=NULL;
	p->num=eno;
	p->point=v2;
	if(map[v1]==NULL||eno<map[v1]->num) 
	{
		p->next=map[v1];
		map[v1]=p;
	}
	else
	{
		q=map[v1];
		while(q!=NULL&&eno>q->num)
		{
			r=q;
			q=q->next;
		}
		r->next=p;
		p->next=q;
	}
	return;
}
void DFS(int sta,int des,int len)
{
	visited[sta]=1;
	int i;
	struct edge *p=NULL;
	p=map[sta];
	while(p!=NULL)
	{
		if(visited[p->point]==0)
		{
			len++;
			route[len]=p->num;
			DFS(p->point,des,len);
			len--;
		}
		p=p->next;
	}
	if(sta==des)
	{
		for(i=0;i<=len;i++) printf("%d ",route[i]);
		printf("\n");
	}
	visited[sta]=0;
	return;
}
