#include<stdio.h>
int main()
{
	typedef struct contact
	{
		char name[23];
		char num[12]; 
	}cts;
	cts a[100]={};
	int b;
	scanf("%d",&b);
	int i=0;
	for(i=0;i<b;i++)
	{
		scanf("%s %s",a[i].name,a[i].num);
	}
    int j,k;
    cts tmp;
    for(j=0;j<b-1;j++)
     {
     
     	for(k=0;(a[j].name[k]!=0&&a[j+1].name[k]!=0&&a[j].name[k]!='_'&&a[j+1].name[k]!='_');k++)
     	{
     	// printf("%d %d\n",	a[j].name[k],a[j+1].name[k]);
		     if(a[j].name[k]>a[j+1].name[k])
     		{
     			tmp=a[j];
     			a[j]=a[j+1];
     			a[j+1]=tmp;
     			j=-1;
     			break;
			 }
			 else if (a[j].name[k]<a[j+1].name[k]) break;
			
		 }
		
		 if(((a[j].name[k]==0)+(a[j+1].name[k]==0)+(a[j].name[k]=='_')+(a[j+1].name[k]=='_'))>=2)
		 {
		 	for(i=0;i<=10;i++)
		 	{
		 		if(a[j].num[i]!=a[j+1].num[i])
		 		 i=20;
			 }
			 if(i==11)
			 {
			 	a[j+1].name[0]='|';
			 }
			 else
			 {
			 	a[j+1].name[k+1]=a[j].name[k+1]+1;
			 	if(a[j+1].name[k+1]>0&&a[j+1].name[k+1]<'0')
			 		a[j+1].name[k+1]+='0';
			 	if(a[j+1].name[k]==0)
			 		a[j+1].name[k]='_';
			 }
		  } 
	 } 
	for(i=0;i<b;i++)
	if(a[i].name[0]<='z')
	printf("%s %s\n",a[i].name,a[i].num);
	return 0; 
}
