#include<stdio.h>
#define MAXSIZE 100
int Stack[MAXSIZE];
int main()
{
	int top=-1;
	int Opt,Num; 
	while(1)
	{
		scanf("%d",&Opt);
		if(Opt==-1) break;
		else if(Opt==1)
		{
			scanf("%d",&Num);
			if(top==MAXSIZE-1)
			{
				printf("error ");
				continue;
			}
			++top;
			Stack[top]=Num;
		}
		else if(Opt==0)
		{
			if(top==-1)
			{
				printf("error ");
				continue;
			}
			printf("%d ",Stack[top]);
			--top;
		}
	}
	return 0;
}
