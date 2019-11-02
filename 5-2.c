#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct danci
{
	char word[31];
	int num;
	struct danci *left;
	struct danci *right;
}word,*wdp;
void travel(wdp);

int main()
{
	wdp p=NULL,head=NULL,q=NULL;
	FILE *in;
	in=fopen("article.txt","r");
	char t=0,s=0;
	int i=0;
	while((t=getc(in))!=0)
	{
		if(s==-1) break;
		t=tolower(t);
		if(isalpha(s)==0&&isalpha(t)>0)
		{
		   p=(wdp)malloc(sizeof(word));
		   p->num=1;
		   p->right=NULL;
		   p->left=NULL;
		   memset(p->word,0,31);
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
			if(head==NULL)
			{
				head=p;
			}
			else
			{
				q=head;
				while(1)
				{
					if(strcmp(p->word,q->word)<0)
						if(q->left!=NULL)
							q=q->left;
						else
						{
							q->left=p;
							break;
						}
					else if(strcmp(p->word,q->word)>0)
					{
						if(q->right!=NULL)
							q=q->right;
						else
						{
							q->right=p;
							break;
						}
					}
					else
					{
						q->num+=1;
						free(p);
						break;
					}		
				}	
			}
		}
		s=t;
	}
	fclose(in);
	if(head->right->right!=NULL) printf("%s %s %s\n",head->word,head->right->word,head->right->right->word);
	else if(head->right!=NULL) printf("%s %s\n",head->word,head->right->word);
	else if(head!=NULL) printf("%s\n",head->word);
	travel(head);	
	return 0;
	}
void travel(wdp p)
{
	if(p==NULL) return;
	else
	{
		travel(p->left);
		printf("%s %d\n",p->word,p->num);
		travel(p->right);
	}
	return;
}
