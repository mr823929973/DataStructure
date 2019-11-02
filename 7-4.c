#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXS 1000
#define INF 65535
char nameData[MAXS][21]={};
int edge[MAXS][MAXS]={};
int spath[MAXS]={};
int path[MAXS]={};
int sweight[MAXS]={};
int wfound[MAXS]={}; 
int preid=0;
void setupMap(void);
int addStation(char*,int);
void addEdge(int,int,int);
int search(char*);
void Dijkstra(int,int);
void printPath(int,int);
int main()
{
	setupMap();
	char dep[21]={};
	char arr[21]={};
	scanf("%s%s",dep,arr);
	Dijkstra(search(dep),search(arr));
	return 0;
}
void setupMap(void)
{
	FILE *in;
	in=fopen("bgstations.txt","r");
	int m,line,trans,st;
	int i,j;
	int lid=-1,id=-1;
	char name[21]={};
	fscanf(in,"%d",&m);
	for(i=0;i<m;i++)
	{
		fscanf(in,"%d%d",&line,&st);
		for(j=0;j<st;j++)
		{
			fscanf(in,"%s%d",name,&trans);
			id=addStation(name,trans);
			if(j>0)
			{
				addEdge(id,lid,line);
			}
			lid=id;
			id=-1;
		}
		lid=-1;
	}
	fclose(in);
	return;
}
int addStation(char *name,int trans)
{

	int i;
	for(i=0;i<preid;i++)
	{
		if(strcmp(nameData[i],name)==0)
		{
			return i;
		}
	}
	if(i==preid)
	{
		strcpy(nameData[preid],name);
		preid++;
		return preid-1;
	}
	return -1;
}
void addEdge(int id1,int id2,int line)
{
	edge[id1][id2]=line;
	edge[id2][id1]=line;
	return;
}
int search(char* name)
{
	int i;
	for(i=0;i<preid;i++)
	{
		if(strcmp(nameData[i],name)==0)
		{
			return i;
		}
	}
	return -1;
}
void Dijkstra(int v0,int v1)
{
	int i,j,v,minweight;
	for(i=0;i<preid;i++)
	{
		sweight[i]=INF;
		if(edge[v0][i]!=0)
		{
			sweight[i]=1;
			spath[i]=v0;
		}
	}
	sweight[v0]=0;
	wfound[v0]=1;
	v=0;
	for(i=0;i<preid-1;i++)
	{
		minweight=INF;
		for(j=0;j<preid;j++)
		{
			if(wfound[j]==0&&(sweight[j]<minweight))
			{
				v=j;
				minweight=sweight[v];
			}
		}
		wfound[v]=1;
		for(j=0;j<preid;j++)
		{
 			if(j!=v0&&wfound[j]==0&&edge[v][j]!=0&&(minweight+1<sweight[j]||sweight[j]==0))
			{
				sweight[j]=minweight+1;
				spath[j]=v;
			}
		}
		if(wfound[v1]==1) break;
	}
	printPath(v0,v1);
	return;
}
void printPath(int v0,int v1)
{
	int v=v1,i,line;
	while(v!=v0)
	{
		path[spath[v]]=v;
		v=spath[v];
	}
	v=v0;
	printf("%s",nameData[v0]);
	line=edge[v][path[v]];
	i=0;
	while(v!=v1)
	{
		if(line!=edge[v][path[v]])
		{
			printf("-%d(%d)-%s",line,i,nameData[v]);
			i=0;
			line=edge[v][path[v]];
		}
		i++;
		v=path[v];	
		if(v==v1)
		{
			printf("-%d(%d)-%s",line,i,nameData[v1]);
		}
	}
	return;
}
