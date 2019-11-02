#include<stdio.h>
#include<string.h>
int compare(char a[],int x,char b[],int y,int *p,int *la,int *lb)
{
	int len_a,len_b,cpr;
	
	for(len_a=0;len_a<x;len_a++)
	{
		if(a[len_a]!='0') break;
	 }
	len_a=x-len_a; //jisuan a b de youxiao changdu
	
	for(len_b=0;len_b<y;len_b++)
	{
		if(b[len_b]!='0') break;
	 }
	len_b=y-len_b;
	if(len_a>len_b) cpr=1;
	else if(len_a<len_b) cpr=-1 ;
	else  //weishuxiangtong de bijiao
	{
		int i,j;
		for(i=x-len_a,j=y-len_b;a[i]!='\0';i++,j++)
		{
			if(a[i]>b[j]) 
			{
				cpr=1; 
			    break;
			}
			else if(a[i]<b[j]) 
			{
				cpr=-1;
				break;
			}
		}
		if(a[i]=='\0') cpr=0;
	}
	*la=len_a;
	*lb=len_b;
	*p=cpr;
	return 0;
 }
 
int main()
{
	char a[81]={0};
	char b[81]={0};
	int min[81]={0};
	scanf("%s",a);
	scanf("%s",b);
	int n,len_a,len_b,x,y;
	x=strlen(a);
	y=strlen(b);
	int *p=&n;
	int *la=&len_a;
	int *lb=&len_b;
	int i,j,k;
	compare(a,x,b,y,p,la,lb);
	if(n==0)
    {
   		printf("0");
	}
	else if(n==1)
	{
		
		for(i=x-1,j=y-1,k=len_a-1;i>=x-len_a;i--,j--,k--)
		{
			if(j>=0)
			{
			
				min[k]=min[k]+(a[i]-b[j]);
				if(min[k]<0)
				{
					min[k]+=10;
					min[k-1]-=1;
				}
			}
			else
			{
				min[k]=min[k]+(a[i]-'0');
				if(min[k]<0)
				{
					min[k]+=10;
					min[k-1]-=1;
				}
			}
		}
	    i=0;
	    while(min[i]==0) i++;
	    for(i=i;i<=len_a-1;i++) printf("%d",min[i]);
	}
	else if(n==-1)
	{
		for(i=y-1,j=x-1,k=len_b-1;i>=y-len_b;i--,j--,k--)
		{
			if(j>=0)
			{
			
				min[k]=min[k]+(b[i]-a[j]);
				if(min[k]<0)
				{
					min[k]+=10;
					min[k-1]-=1;
				}
			}
			else
			{
				min[k]=min[k]+(b[i]-'0');
				if(min[k]<0)
				{
					min[k]+=10;
					min[k-1]-=1;
				}
			}
		}
	    i=0;
	    while(min[i]==0) i++;
	    printf("-");
	    for(i=i;i<=len_b-1;i++) printf("%d",min[i]);
	}
	return 0;
 } 
