#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
typedef struct danci
{
	char word[21];
	int num;
	struct danci *link;
}word,*wdp;
int main()
{
	wdp head=NULL,p=NULL,q=NULL,r=NULL;
	FILE *in;
	in=fopen("article.txt","r");
	char t=0,s=0;
	int i=0;
	while((t=getc(in))!=EOF)
	{
		t=tolower(t);
		if(isalpha(s)==0&&isalpha(t)>0)
		{
		   p=(wdp)malloc(sizeof(word));
		   p->num=0;
		   p->link=NULL;
		   i=0;
		}
		if(isalpha(t)>0)
		{
			p->word[i]=t;
			i++;
		}
		else if(isalpha(s)>0&&isalpha(t)==0)
		{
			p->word[i]=0;
			if(head==NULL||strcmp(p->word,head->word)<0)
			{
				p->link=head;
				head=p;
				p->num+=1;
			}
			else
			{
				q=head;
				while(q!=NULL&&strcmp(q->word,p->word)<0)
				{
					r=q;
					q=q->link;
				}
				if(q==NULL)
				{
					p->link=q;
					r->link=p;
					p->num+=1;
				}
				else
				{
					if(strcmp(q->word,p->word)>0)
					{
						p->link=q;
						r->link=p;
						p->num+=1;
					}
					else if(strcmp(p->word,q->word)==0)
					{
				
						q->num+=1;
						free(p);	
					}
				}
			}
		}
		s=t;
	}
	fclose(in); 
	p=head;
	while(p!=NULL)
	{
		printf("%s %d\n",p->word,p->num);
		p=p->link;
	}
	return 0;
}
