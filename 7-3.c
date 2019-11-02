#include<stdio.h>
#include<stdlib.h>
#define MAXEDGE 1000
#define MAX 2147483647
struct edge
{
	int num;
	int point;
	int weigh; 
	struct edge *next;
};
int n,e;
int visited[MAXEDGE]={};
int edges[MAXEDGE]={};
struct edge *map[MAXEDGE]={};
struct edge MIN={0,0,MAX,0};
void edgeAdd(int,int,int,int);
void prim(int,int,int);
int cmp(const void*,const void*);
int main()
{
	int i;
	int eno,v1,v2,weight;
	scanf("%d%d",&n,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d%d",&eno,&v1,&v2,&weight);
		edgeAdd(eno,v1,v2,weight);
		edgeAdd(eno,v2,v1,weight);
	}
	prim(0,0,0);
	return 0;
}
void edgeAdd(int eno,int v1,int v2,int weight)
{
	struct edge *p=NULL,*q=NULL,*r=NULL;
	p=(struct edge *)malloc(sizeof(struct edge));
	p->next=NULL;
	p->num=eno;
	p->point=v2;
	p->weigh=weight;
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
void prim(int v,int times,int weight)
{
	int i;
	visited[v]=1;
	if(times>=n-1)
	{
		printf("%d\n",weight);
		for(i=0;i<n-1;i++)
		{
			qsort(edges,n-1,sizeof(edges[0]),cmp);
			printf("%d ",edges[i]);
		}
	}
	else
	{
		struct edge *min=&MIN;
		struct edge *p=NULL;
		for(i=0;i<n;i++)
		{
			if(visited[i]==1)
			{
				p=map[i];
				while(p!=NULL)
				{
					if(p->weigh<min->weigh&&visited[p->point]==0)
					{
						min=p;
					}
					p=p->next;
				}
			}
		}
		edges[times]=min->num;
		prim(min->point,times+1,weight+min->weigh);
	}
	return;
}
int cmp(const void *a,const void *b)
{
	return *((int*) a)-*((int*)b);
}
