#include<stdio.h>
#include<stdlib.h>
typedef struct mk
{
	int num;
    struct mk *link;
}monkey,*mknode;
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	int i;
	mknode head=NULL,p=NULL,r=NULL;
	for(i=1;i<=n;i++)
	{
		p=(mknode)malloc(sizeof(monkey));
		p->num=i;
		p->link=NULL;
		if(head==NULL)
		{
			head=p;
			p->link=p;
		}
		else 
		{
			r->link=p;
			p->link=head;
			
		}
		r=p;
	}
//	p->link=head; 
	p=head;
	while(p->num!=q)
	{
		p=p->link;
	}
	while(head->link!=head)
	{
		for(i=0;i<m-1;i++)
		{
		  p=p->link;
		}
		if(p==head)
		{
			r=head;
			while(r->link!=head)
			{
				r=r->link;
			}
			r->link=p->link;
			head=p->link;
			free(p);
			p=r->link;
		}
		else
		{
			r=head;
			while(r->link!=p)
			{
				r=r->link;
			}
			r->link=p->link;
			free(p);
			p=r->link;
		}
	}
	printf("%d",head->num);
	return 0;
}
