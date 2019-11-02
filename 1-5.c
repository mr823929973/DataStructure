#include<stdio.h>
#include<string.h>
int a[10];
int true[11];
void AllRange(int exp,int n)
{
	int i;
	if(exp==n)
	{
		for(i=0;i<n;i++) printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(true[i]==0)
		{
			true[i]=1;
			a[exp]=i;
			AllRange(exp+1,n);
			true[i]=0;
		}
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	AllRange(0,n);
	return 0;
}

