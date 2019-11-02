#include<stdio.h>
#define MAXSIZE 200
int main()
{
	int que[MAXSIZE];
	int rear=-1;
	int top=0;
	int window=3;
	int n;
	int tmp;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		for(j=0;j<tmp;j++)
		{
			++rear;
			que[rear]=0;
		}
		if(window<5&&(rear-top+1)/window>=7)
		while(window<5&&(rear-top+1)/window>=7) window++;
		else if(window>3&&(rear-top+1)/window<7) window--;
		j=1;
		while(top<=rear&&j<=window)	
		{
			top++;
			j++;
		}
		for(j=top;j<=rear;j++) que[j]++;
	}
	while(top<=rear)
	{
		if(window>3&&(rear-top+1)/window<7) window--;
		j=1;
		while(top<=rear&&j<=window)	
		{
			top++;
			j++;
		}
		for(j=top;j<=rear;j++) que[j]++;
	}
	for(i=0;i<=rear;i++) printf("%d : %d\n",i+1,que[i]);
	return 0;
	
}
