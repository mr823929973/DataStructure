#include<stdio.h>
#include<string.h>
int main() 
{
	FILE *in,*out;
	in=fopen("filein.txt","r");
	out=fopen("fileout.txt","w");
	char a[81]= {};
	char b[81]= {};
	char c[1025]= {};
	char d[1025]= {};
	int i,j,k,x;
	i=0;
	scanf("%s %s",a,b);
	while(a[i]>0) 
    {
		if(a[i]>='A'&&a[i]<='Z') 
		{
			a[i]=a[i]+'a'-'A';
		}
		i++;
	}
	x=strlen(a);
	while(fgets(c,1024,in)!=NULL) 
	{
		i=0;
		while(c[i]>0) 
		{
			if(c[i]>='A'&&c[i]<='Z') 
			      d[i]=c[i]+'a'-'A';
			else d[i]=c[i];
			i++;	
		}
		for(i=0;d[i]>0;i++)
		 {
		 	for(j=i,k=0;a[k]>0&&d[j]==a[k];j++,k++);
		 	if(a[k]==0) 
			 {
			 	fputs(b,out);
			 	i=i+x-1;
			 }
		 	else
		 	{
		 		fputc(c[i],out);
			 }
		 }
			
		
		for(i=0;c[i]!=0&&d[i]!=0;i++)
		c[i]=d[i]=0;
	}
	//printf("%d",x);
	fclose(in);
	fclose(out);
	return 0;
}
