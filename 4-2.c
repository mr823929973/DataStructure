#include<stdio.h>
typedef struct kuohao
{
	char b;
	int n;
} sign;
int main()
{
	sign k[201]={};
	sign stack[201]={};
	int top=0;
	char a[4]={};//a[0]=""a[1]=''a[2]=/* */ a[3]=//
	FILE *in;
	char s=0,t=0;
	int i=1,j=0;
	in=fopen("example.c","r");
	while((t=getc(in))!=EOF)
	{
		if(t=='\n')	
		{
			i++;
			continue;
		}
		if(a[0]||a[1]||a[2]||a[3])
		{
			if(a[3])
			{
				while((t=getc(in))!=EOF)
				{
					s=t;
					if(t=='\n') break;
				}
				a[3]=0;
				i++;
				
			}
			else if(a[0])
			{
				while((t=getc(in))!=EOF)
				{
					s=t;
					if(t=='"') break;
				}
				a[0]=0;
		
			}
			else if(a[1])
			{
				while((t=getc(in))!=EOF)
				{
					s=t;
					if(t=='\'') break;
				}
				a[1]=0;
			}
			else if(a[2])
			{
				while((t=getc(in))!=EOF)
				{
					if(t=='\\'||s=='*') break; 
					s=t;
				}
				a[2]=0;
			
			}	
		}
		else
		{
			if(t=='"')	a[0]=1;
			else if(t=='\'')	a[1]=1;
			else if(s=='/'&&t=='*')	a[2]=1;
			else if(s=='/'&&t=='/')	a[3]=1;
			else if(t=='{'||t=='}'||t=='('||t==')')
			{
				k[j].b=t;
				k[j].n=i;
				++j;
			}
		}
		s=t;	
	}
	fclose(in);
	for(i=0;i<j;i++)	//printf("%c %d\n",k[i].b,k[i].n);
	{
		if(top==0&&(k[i].b==')'||k[i].b=='}'))
		{
			printf("without maching '%c' at line %d",k[i].b,k[i].n);
			return 0;
		}
		++top;
		stack[top]=k[i];
		if((stack[top-1].b=='('&&stack[top].b=='}')||(stack[top-1].b=='{'&&stack[top].b==')'))
		{
			printf("without maching '%c' at line %d",stack[top].b,stack[top].n);
			return 0;		
		}
		if(stack[top-1].b=='('&&stack[top].b=='{')
		{
			printf("without maching '%c' at line %d",stack[top-1].b,stack[top-1].n);
			return 0;		
		}
		if((stack[top-1].b=='('&&stack[top].b==')')||(stack[top-1].b=='{'&&stack[top].b=='}'))
		{
			top-=2;		
		}
		
	}
	if(top) printf("without maching '%c' at line %d",stack[top].b,stack[top].n);
	else	
	for(i=0;i<j;i++) printf("%c",k[i].b);
	return 0;
}
