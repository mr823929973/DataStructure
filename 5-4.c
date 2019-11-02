#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ren
{
	char name[21];
	int depth;
	struct ren *lc;
	struct ren *rc;
	struct ren *fa;
}people,*peo;
void add(peo,char*,char*,char*);
void search(peo,char*);
peo cpr1=NULL,cpr2=NULL;
int main()
{
	FILE *in;
	in=fopen("in.txt","r");
	char father[21]={};
	char lchild[21]={};
	char rchild[21]={};
	char name1[21]={};
	char name2[21]={};
	peo root=NULL,p=NULL;
	peo fa1=NULL,fa2=NULL;
	int n,i;
	fscanf(in,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(in,"%s%s%s",father,lchild,rchild);
		if(root==NULL)
		{
			p=(peo)malloc(sizeof(people));
			strcpy(p->name,father);
			p->fa=NULL;
			p->lc=NULL;
			p->lc=NULL;
			p->depth=1;
			root=p;
			p->lc=(peo)malloc(sizeof(people));
			strcpy(p->lc->name,lchild);
			p->lc->fa=p;
			p->lc->lc=NULL;
			p->lc->rc=NULL;
			p->lc->depth=p->depth+1;
			if(strcmp(rchild,"NULL")!=0)
			{
				p->rc=(peo)malloc(sizeof(people));
				strcpy(p->rc->name,rchild);
				p->rc->fa=p;
				p->rc->lc=NULL;
				p->rc->rc=NULL;
				p->rc->depth=p->depth+1;
			}
		}
		else
		{
			add(root,father,lchild,rchild);
		}
	}
	fclose(in);
	scanf("%s%s",name1,name2);
	search(root,name1);
	search(root,name2);
	if(cpr1->depth>cpr2->depth)
	{
		printf("%s %s %d",cpr1->name,cpr2->name,cpr1->depth-cpr2->depth);
	}
	else if(cpr1->depth<cpr2->depth)
	{
		printf("%s %s %d",cpr2->name,cpr1->name,cpr2->depth-cpr1->depth);
	}
	else
	{
		fa1=cpr1;
		fa2=cpr2;
		while(fa1!=fa2)
		{
			fa1=fa1->fa;
			fa2=fa2->fa;
		}
		printf("%s %s %d\n",fa1->name,name1,cpr1->depth-fa1->depth);
		printf("%s %s %d",fa2->name,name2,cpr2->depth-fa2->depth);
	}
	return 0;
} 
void add(peo p,char *a,char *lc,char *rc)
{
	if(p==NULL) return;
	if(strcmp(p->name,a)==0) 
	{
		p->lc=(peo)malloc(sizeof(people));
		strcpy(p->lc->name,lc);
		p->lc->fa=p;
		p->lc->lc=NULL;
		p->lc->rc=NULL;
		p->lc->depth=p->lc->fa->depth+1;
		if(strcmp(rc,"NULL")!=0)
		{
			p->rc=(peo)malloc(sizeof(people));
			strcpy(p->rc->name,rc);
			p->rc->fa=p;
			p->rc->lc=NULL;
			p->rc->rc=NULL;
			p->rc->depth=p->rc->fa->depth+1;
		}
		return;
	}
	else
	{
		add(p->lc,a,lc,rc);
		add(p->rc,a,lc,rc);
	}
	return;
}
void search(peo p,char *a)
{
	if(p==NULL) return;
	if(strcmp(p->name,a)==0)
	{
		if(cpr1==NULL) cpr1=p;
		else cpr2=p;
		return;
	}
	search(p->lc,a);
	search(p->rc,a);
	return;
}
