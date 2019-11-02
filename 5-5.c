#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct huffman
{
	int a;
	int cnt;
	struct huffman *next;
	struct huffman *left;
	struct huffman *right;
}cod,*code;
char huffman[128][32]={};
char tmp[32]={};
int output[8]={};
int comp(const void*,const void*);
void travel(code,int);
int main()
{
	FILE *in,*out;
	code a[128]={};
	code head=NULL,p=NULL,q=NULL,r=NULL;
	int t;
	int i=0,j=0;
	int tmp16=0;
	in=fopen("input.txt","r");
	//printf("%d\n",in); 
	while((t=getc(in))!=EOF)
	{
		if(t=='\n') continue;
		if(a[t]==NULL)
		{
			a[t]=(code)malloc(sizeof(cod));
			a[t]->a=t;
			a[t]->cnt=1;
			a[t]->left=NULL;
			a[t]->right=NULL;
			a[t]->next=NULL;
		}
		else
		{
			a[t]->cnt+=1;
		}	
	}
	fclose(in);
	a[0]=(code)malloc(sizeof(cod));
	a[0]->a=0;
	a[0]->cnt=1;
	a[0]->left=NULL;
	a[0]->right=NULL;
	a[0]->next=NULL; 
	qsort(a,128,sizeof(a[0]),comp);
	head=a[0]; 
	while(a[i]!=NULL)
	{
		a[i]->next=a[i+1];
		i++;
	}
	while(head->next!=NULL)
	{
		p=(code)malloc(sizeof(cod));
		p->a=-1;
		p->cnt=head->cnt+head->next->cnt;
		p->left=head;
		p->right=head->next;
		p->next=NULL;
		if(head->next->next!=NULL)
			head=head->next->next;
		else
		{
			head=p;
			continue;
		}
		if(p->cnt<head->cnt)
		{
			p->next=head;
			head=p;
		}
		else
		{
			q=head;
			while(q!=NULL&&p->cnt>=q->cnt)
			{
				r=q;
				q=q->next;
			}
			p->next=q;
			r->next=p;
		}
	}
	travel(head,0);
	in=fopen("input.txt","r");
	out=fopen("output1.txt","w");
	while((t=getc(in))!=EOF)
	{
		if(t=='\n') continue;
		i=0;
		while(huffman[t][i]!=0)
		{
			if(huffman[t][i]=='0') output[j]=0;
			if(huffman[t][i]=='1') output[j]=1;
			if(j>=7)
			{
				for(j=7,tmp16=0;j>=0;j--)
				{
					tmp16+=pow(2,7-j)*output[j];
				}
				j=-1;
				printf("%x",tmp16&0xff);
				fprintf(out,"%x",tmp16&0xff);
			}
			j++;
			i++;
		}	
	}
	fclose(in);
	i=0;
	t=0;
	while(huffman[t][i]!=0)
	{
		if(huffman[t][i]=='0') output[j]=0;
		if(huffman[t][i]=='1') output[j]=1;
		if(j>=7)
		{
			for(j=7,tmp16=0;j>=0;j--)
			{
				tmp16+=pow(2,7-j)*output[j];
			}
			j=-1;
			printf("%x",tmp16&0xff);
			fprintf(out,"%x",tmp16&0xff);
		}
		j++;
		i++;
	}
	if(j!=0) 
	{
		while(j<=7)
		{
			output[j]=0;
			j++;
		}
		for(j=7,tmp16=0;j>=0;j--)
			{
				tmp16+=pow(2,7-j)*output[j];
			}
			j=-1;
			printf("%x",tmp16&0xff);
			fprintf(out,"%x",tmp16&0xff);
	}
	fclose(out);
	getchar();
	return 0;
}
int comp(const void *a,const void *b)
{
	code a1,b1;
	a1=*(code*)a;
	b1=*(code*)b;
	if(a1==NULL&&b1!=NULL) return 1;
	else if(a1!=NULL&&b1==NULL) return -1;
	else if(a1==NULL&&b1==NULL) return 0;
	else
	{
		if(a1->cnt!=b1->cnt) return (a1->cnt-b1->cnt);
		else return a1->a-b1->a;
	}
}
void travel(code p,int i)
{
	if(p->a>=0)
	{
		strcpy(huffman[p->a],tmp);
		return;
	}
	tmp[i]='0';
	++i;
	travel(p->left,i);
	tmp[i]=0;
	--i;
	tmp[i]='1';
	++i;
	travel(p->right,i);
	tmp[i]=0;
	--i;
	return;
}
