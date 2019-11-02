#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct library
{
	char book[51];
	char aut[21];
	char pre[31];
	char year[11];
	struct library *link;
}lib,*libptr;
libptr Initialise()
{
	FILE *in;
	int i=0;
	in=fopen("books.txt","r");
	libptr p=NULL,q=NULL,r=NULL,head=NULL;
	p=(libptr)malloc(sizeof(lib));
	while(fscanf(in,"%s%s%s%s",p->book,p->aut,p->pre,p->year)!=EOF)
	{
		if(head==NULL||(strcmp(head->book,p->book)>0))
		{
		 	p->link=head;
		 	head=p;
		}
		else
		{
			q=head;
			while(q!=NULL&&(strcmp(p->book,q->book)>0))
			{
				r=q;
				q=q->link;
			}
			p->link=q;
			r->link=p;
		}
		for(i=strlen(p->book);i<50;i++)
			p->book[i]=' ';
		for(i=strlen(p->aut);i<20;i++)
			p->aut[i]=' ';
		for(i=strlen(p->pre);i<30;i++)
		    p->pre[i]=' ';	
		p->book[50]=p->aut[20]=p->pre[30]=0;
		p=(libptr)malloc(sizeof(lib));
	}
	free(p);
	fclose(in);
	return head;
}
void Save(libptr head)
{
	libptr temp;
	FILE *out;
	out=fopen("ordered.txt","w");
	while(head!=NULL)
	{
		fputs(head->book,out);
		fputs(head->aut,out);
		fputs(head->pre,out);
		fputs(head->year,out);
		fputs("\n",out);
		temp=head->link;
		free(head);
		head=temp;
	}
	fclose(out);
	return;
}
libptr Add(libptr head)
{
   int i;
   libptr p=NULL,q=NULL,r=NULL;
   p=(libptr)malloc(sizeof(lib));
   scanf("%s%s%s%s",p->book,p->aut,p->pre,p->year);
   if(head==NULL||(strcmp(head->book,p->book)>0))
	{
		p->link=head;
		head=p;
	}
	else
	{
		q=head;
		while(q!=NULL&&(strcmp(p->book,q->book)>0))
		{
			r=q;
			q=q->link;
		}
		p->link=q;
		r->link=p;
	}
	for(i=strlen(p->book);i<50;i++)
			p->book[i]=' ';
	for(i=strlen(p->aut);i<20;i++)
			p->aut[i]=' ';
	for(i=strlen(p->pre);i<30;i++)
			p->pre[i]=' ';	
	p->book[50]=p->aut[20]=p->pre[30]=0;
	return head;
}
void Search(libptr head)
{
	char a[50];
	scanf("%s",a);
	libptr p=head;
	while(p!=NULL)
	{
		if(strstr(p->book,a)!=NULL)
		{
		fputs(p->book,stdout);
		fputs(p->aut,stdout);
		fputs(p->pre,stdout);
		fputs(p->year,stdout);
		fputs("\n",stdout);
		}
		p=p->link;
	}
	
}
libptr Remove(libptr head)
{
	char a[50];
	scanf("%s",a);
	libptr p,q=head;
	p=head->link;
	while(p!=NULL)
	{
		if(strstr(p->book,a)!=NULL)
		{
			q->link=p->link;
			free(p);
			p=q->link;
		}
		else
		{
			q=p;
			p=p->link;
		}
	}
	if(strstr(head->book,a))
	{
		q=head;
		head=head->link;
		free(q);
	}
	return head;
}
int main()
{
   libptr head; 
   head=Initialise();
   int a;
   while(scanf("%d",&a)!=EOF)
   {
   	if(a==0)
	{
	   	Save(head);
	   	break;
	 }
	if(a==1)
	{
		head=Add(head);
	 } 
	if(a==2)
	{
		Search(head); 
	 }
	 if(a==3)
	{
	 	head=Remove(head); 
	 } 
	 a=-1;  
   }
   return 0;
 } 
