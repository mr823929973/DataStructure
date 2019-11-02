#include<stdio.h>
#include<stdlib.h>
typedef struct duoxiangshi
{
	int a;
	int exp;
	struct duoxiangshi *link;
}dxs,*dxspt;
int main()
{
	int a,exp;
	char c;
	dxspt head1=NULL,head2=NULL,headans=NULL,p,q,r,s,t;
	while(~scanf("%d %d%c",&a,&exp,&c))
	{
		p=(dxspt)malloc(sizeof(dxs));
		p->a=a;
		p->exp=exp;
		p->link=NULL;
		if(head1==NULL)
		{
			head1=p;
			q=p;
		}
		else
		{
			q->link=p;
			q=p;
		}
		if(c=='\n') break;
	}
	while(~scanf("%d %d%c",&a,&exp,&c))
	{
		p=(dxspt)malloc(sizeof(dxs));
		p->a=a;
		p->exp=exp;
		p->link=NULL;
		if(head2==NULL)
		{
			head2=p;
			q=p;
		}
		else
		{
			q->link=p;
			q=p;
		}
		if(c=='\n') break;
	}
	p=head1;
	while(p!=NULL)
	{
		q=head2;
		while(q!=NULL)
		{
			r=(dxspt)malloc(sizeof(dxs));
			r->a=(p->a)*(q->a);
			r->exp=(p->exp)+(q->exp);
			r->link=NULL;
			if(headans==NULL)
			{
				headans=r;
			}
			else
			{
				s=headans;
				while(s!=NULL&&(r->exp)<(s->exp))
				{
					t=s;
					s=s->link;
				}
				if(s==NULL||(r->exp)>(s->exp))
				{
					r->link=s;
					t->link=r;
				}
				else
				{
					s->a=(s->a)+(r->a);
					free (r);
				}
			}
			q=q->link;
		}
		p=p->link;
	}
	p=headans;
	while(p!=NULL)
	{
		printf("%d %d ",p->a,p->exp);
		p=p->link;
	}
	return 0;
}
