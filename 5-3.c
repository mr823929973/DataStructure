#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXLINE BUFSIZ
typedef struct shizi
{
	int type;
	int n;
	char t;
	struct shizi *left;
	struct shizi *right;
}form,*forp;
void travel(forp);
int main()
{
	char a[MAXLINE]={};
	form b[MAXLINE]={};
	forp s1[MAXLINE]={};
	forp s2[MAXLINE]={};
	int top1=-1,top2=-1;
	fgets(a,MAXLINE,stdin);
	int i=0,j=0;
//	int tmp=0;
//	char s=0,t=0; 
	while(a[i]!=0)
	{
		if(a[i]=='=') break;
		else if(isdigit(a[i]))
		{
			b[j].n+=a[i]-'0';
			if(isdigit(a[i+1])>0) b[j].n*=10;
			else
			{
				b[j].type=1;
				j++;
			}
		}
		else if(a[i]=='+'||a[i]=='-')
		{
			b[j].t+=a[i];
			b[j].type=-1;
			j++;
		}
		else if(a[i]=='('||a[i]==')')
		{
			b[j].t+=a[i];
			b[j].type=-2;
			j++;
		}
		else if(a[i]=='*'||a[i]=='/')
		{
			b[j].t+=a[i];
			b[j].type=0;
			j++;
		}
	 i++;	
	}
	for(i=0;i<j;i++)
	{
		if(b[i].type>0) 
		{
			++top2;
			s2[top2]=&b[i];
		}
		else
		{
			if(top1==-1||b[i].type==-2)
			{
				top1++;
				s1[top1]=&b[i];
				if(b[i].t==')')
				{
					--top1;
					while(s1[top1]->t!='(')
					{
						++top2;
						s2[top2]=s1[top1];
						--top1;
					}
					--top1;
				}
			}
			else 
			{
				while(top1>-1&&b[i].type<=s1[top1]->type)
				{
					++top2;
					s2[top2]=s1[top1];
					--top1;
				}
				++top1;
				s1[top1]=&b[i];
			}
		}
	}
	while(top1>-1)
	{
		++top2;
		s2[top2]=s1[top1];
		--top1;
	}
	top1=-1;
	for(i=0;i<=top2;i++)
	{
		if(s2[i]->type>0)
		{
			top1++;
			s1[top1]=s2[i];
		}
		else
		{
			s2[i]->right=s1[top1];
			--top1;
			s2[i]->left=s1[top1];
			s1[top1]=s2[i];
		}
	}
	if(s1[0]!=NULL)
	{
		if(s1[0]->type>0) printf("%d",s1[0]->n);
		else printf("%c",s1[0]->t);
		if(s1[0]->left!=NULL)
		{
			if(s1[0]->left->type>0) printf(" %d",s1[0]->left->n);
			else printf(" %c",s1[0]->left->t);
		}
		if(s1[0]->right!=NULL)
		{
			if(s1[0]->right->type>0) printf(" %d",s1[0]->right->n);
			else printf(" %c",s1[0]->right->t);	
		}
	}
	printf("\n");
	travel(s1[0]);
	printf("%d",s1[0]->n);
/*	for(i=0;i<=top2;i++)
	{
		if(s2[i].type>0) 
		{
			top1++;
			s1[top1]=s2[i]; 
		//	printf("%d ",s2[i].n);
		}
		else 
		{
			tmp=s1[top1].n;
			top1--;
			switch (s2[i].t)
			{
				case '+': tmp=s1[top1].n+tmp; break;
				case '-': tmp=s1[top1].n-tmp; break;
				case '*': tmp=s1[top1].n*tmp; break;
				case '/': tmp=s1[top1].n/tmp; break;
				case '%': tmp=s1[top1].n%tmp; break;
			}
			s1[top1].n=tmp; 
		//	printf("%c ",s2[i].t);
		}
	}
	printf("%d",s1[0].n); */
	return 0;
} 
void travel(forp p)
{
	if(p==NULL) return;
	travel(p->left);
	travel(p->right);
	if(p->type<=0)
	{
		switch(p->t)
		{
			case '+': p->n=p->left->n+p->right->n; break;
			case '-': p->n=p->left->n-p->right->n; break;
			case '*': p->n=p->left->n*p->right->n; break;
			case '/': p->n=p->left->n/p->right->n; break;
		}
	}
	return;
}
