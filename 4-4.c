#include<stdio.h>
#include<string.h>
#define MAXSIZE 513
typedef struct zhan
{
	int op;
	int pos;
	char str[500];
}operation;
int main()
{
	char a[MAXSIZE]={};
	operation Stack[100]={};
	int top=-1;
	int n;
	int i;
	fgets(a,MAXSIZE,stdin);
	a[strlen(a)-1]=0;
	scanf("%d",&n);
	int tmp=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		switch(tmp)
		{
			case 1:	++top;
					Stack[top].op=tmp;
					scanf("%d%s",&Stack[top].pos,Stack[top].str);
					break;
			case 2:	++top;
					Stack[top].op=tmp;
					scanf("%d%s",&Stack[top].pos,Stack[top].str);
					break;
			case 3: --top;
					break;		
		}
	}
	fflush(stdin);
	int s=0,t=0,x=0;
	int del=0;
	while(1)
	{
		scanf("%d",&tmp);
		if(tmp==-1) break;
		switch(tmp)
		{
			case 1:	++top;
					Stack[top].op=tmp;
					scanf("%d%s",&Stack[top].pos,Stack[top].str);
					x=strlen(a);
					s=strlen(a+Stack[top].pos);
					t=strlen(Stack[top].str);
					for(i=x-1;i>=Stack[top].pos;i--) 
					{
							a[i+t]=a[i];
					}
					for(i=0;i<t;i++) a[Stack[top].pos+i]=Stack[top].str[i];
					a[x+t]=0;
					break;
			case 2:	++top;
					Stack[top].op=tmp;
					scanf("%d%d",&Stack[top].pos,&del);
					x=strlen(a);
					s=strlen(a+Stack[top].pos);
					if(s<del) del=s;
					strncpy(Stack[top].str,a+Stack[top].pos,del);
					Stack[top].str[del]=0;
					for(i=Stack[top].pos+del;i<x;i++) a[i-del]=a[i];
					a[x-del]=0;
					break;
			case 3:	if(Stack[top].op==1)
					{
						x=strlen(a);
						del=strlen(Stack[top].str);
						for(i=Stack[top].pos+del;i<x;i++) a[i-del]=a[i];
						a[x-del]=0;
						--top;
						break;
					}
					else if(Stack[top].op==2)
					{
						x=strlen(a);
						s=strlen(a+Stack[top].pos);
						t=strlen(Stack[top].str);
						for(i=x;i>=Stack[top].pos;i--) a[i+t]=a[i];
						for(i=0;i<t;i++) a[Stack[top].pos+i]=Stack[top].str[i];
						a[x+t]=0;
						top--;
						break;
					}
		}
	}
	printf("%s",a);
	return 0;
}
