#include<stdio.h>
typedef struct{
	int x1,y1,x2,y2;
	int number;
}lin;
int main()
{
	int n,m=0;
	int i,j,k;
	lin line[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);	
	}
	for(i=0;i<n;i++)
	{
		line[i].number=0;
		k=i;
		for(j=0;j<=n;j++)
		{
			if(line[j].x1==line[k].x2&&line[j].y1==line[k].y2)
			{
				k=j;
				j=-1;
				line[i].number+=1;
			}
		}
	}
	int x1=0,y1=0;
	for(i=0;i<n;i++)
	{
	  if(line[i].number>m)
	  {
	  	m=line[i].number;
	  	x1=line[i].x1;
	  	y1=line[i].y1;
	  }
	}
	printf("%d %d %d",m+1,x1,y1);
	return 0;
}
