#include<stdio.h>
#include<string.h>
int main()
{
	char a[100]={0};
	scanf("%s",a);
	int i;
	int exp;
	int x=strlen(a);
	if((a[1]=='.'&&a[0]!='0')||(a[0]!='0'&&a[1]=='\0'))
	{
		printf("%se0",a);
	}
	else if(a[0]=='0'&&a[1]=='.')
	{
		for(i=2;i<=x-1;i++)
		{
			if(a[i]!='0') break;
		}
		exp=i-1;
		if(a[i+1]=='\0') printf("%ce-%d",a[i],exp);
		else
		{
			printf("%c.",a[i]);
			for(i=i+1;i<=x-1;i++) printf("%c",a[i]);
			printf("e-%d",exp);
		}
	}
	else
	{
		for(i=2;i<=x-1;i++)
		{
			if(a[i]=='.') break;
		}
		if(i==x)
		{
			printf("%c.",a[0]);
			for(i=1;i<=x-1;i++) printf("%c",a[i]);
			printf("e%d",x-1);
		}
		else
		{
			exp=i-1;
			printf("%c.",a[0]);
			for(i=1;i<=x-1;i++)
			{
				if(a[i]=='.') continue;
				printf("%c",a[i]);
			}
			printf("e%d",exp);
		}
	}
	return 0;
}
