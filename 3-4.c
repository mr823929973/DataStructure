#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct crpyt
{
	char a;
	struct crpyt *link;
}cr,*crp;
int main()
{
	crp head=NULL,p,q,r=NULL;
	char c;
	while(isprint(c=getchar())>0)
	{
		p=(crp)malloc(sizeof(cr));
		p->a=c;
		p->link=NULL;
		if(head==NULL)
		{
			head=p;
			r=p;
		}
		else
		{
			q=head;
			while(q!=NULL)
			{
				if(p->a==q->a)
				{
					free(p);
					p=NULL;
					break;
				}
				q=q->link;
			}
			if(p==NULL) continue;
			else
			{
				r->link=p;
				r=p;
			}
		}
	}
	for(c=32;c<=126;c++)
	{
		p=(crp)malloc(sizeof(cr));
		p->a=c;
		p->link=NULL;
		q=head;
		while(q!=NULL)
		{
			if(p->a==q->a)
			{
				free(p);
				p=NULL;
				break;
			}
			q=q->link;
		}
		if(p==NULL) continue;
		else
		{
			r->link=p;
			r=p;
		}
	}
	r->link=head;
    p=head;
  /* while(1)
    {
    	printf("%c",p->a);
    	p=p->link;
    	if(p==head) break;
    	
	}
	printf("\n"); */
	char b[95]={0};
	p=head;
	char t;
	t=head->a;
	char s=0;
	int i=0;
	while(head->link!=head)
	{
		s=p->a;
		if(p==head)
		{
			q=p;
			p=p->link;
			head=head->link;
			r=head;
			while(r->link!=q)
			{
				r=r->link;
			}
			r->link=head;
			free(q);
			q=NULL;
		}
		else
		{
			q=p;
			p=p->link;
			while(r->link!=q)
			{
				r=r->link;
			}
			r->link=p;
			free(q);
			q=NULL;
			
		}
		for(i=1;i<s;i++)
		{
			p=p->link;
		}
		b[s-32]=p->a;
		s=p->a;
	}
	b[s-32]=t;
/*	for(i=0;i<=95;i++)
	printf("%c",b[i]); */
	FILE *in,*out;
	in=fopen("in.txt","r");
	out=fopen("in_crpyt.txt","w");
	while((t=getc(in))!=EOF)
	{
		if(isprint(t)>0)
		putc(b[t-32],out);
		else
		putc(t,out);
		
	}
	fclose(in);
	fclose(out);
	return 0;
}
