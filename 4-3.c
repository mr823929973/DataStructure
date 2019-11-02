#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXLINE 101
typedef struct shizi
{
	int type;
	int n;
	char t;
}form;
int main()
{
	char a[MAXLINE]={};
	form b[MAXLINE]={};
	form s1[MAXLINE]={};
	form s2[MAXLINE]={};
	int top1=-1,top2=-1;
	while(fgets(a,MAXLINE,stdin)!=NULL)
{
	
	int i=0,j=0;
	int tmp=0;
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
		else if(a[i]=='*'||a[i]=='/'||a[i]=='%')
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
			s2[top2]=b[i];
		}
		else
		{
			if(top1==-1||b[i].type==-2)
			{
				if((b[i].t=='-'&&i==0)||(b[i].t=='-'&&b[i-1].t)=='(')
				{
					if(b[i+1].type>0) b[i+1].n=-b[i+1].n;
				}
				else
				{
					top1++;
					s1[top1]=b[i];
					if(b[i].t==')')
					{
						--top1;
						while(s1[top1].t!='(')
						{
							++top2;
							s2[top2]=s1[top1];
							--top1;
						}
						--top1;
					}		
				}
			}
			else 
			{
				if((b[i].t=='-'&&i==0)||(b[i].t=='-'&&b[i-1].t=='('))
				{
					if(b[i+1].type>0) b[i+1].n=-b[i+1].n;
				}
				else 
				{
				while(top1>-1&&b[i].type<=s1[top1].type)
				{
					++top2;
					s2[top2]=s1[top1];
					--top1;
				}
				++top1;
				s1[top1]=b[i];
				}
			}
		}
	}
	while(top1>-1)
	{
		++top2;
		s2[top2]=s1[top1];
		--top1;
	}
	for(i=0;i<=top2;i++)
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
	printf("%d\n",s1[0].n);
	top1=-1;
	top2=-1;
	memset(a,0,MAXLINE);
	memset(b,0,MAXLINE*sizeof(form));
	memset(s1,0,MAXLINE*sizeof(form));
	memset(s2,0,MAXLINE*sizeof(form));
}
	return 0;
} 
