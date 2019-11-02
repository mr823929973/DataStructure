#include<stdio.h>
int main()
{
	FILE *in,*out;
	in=fopen("encrypt.txt","r");
	out=fopen("output.txt","w");
	char a[27];
	int i=0,j=0;
	while(scanf("%c",&a[i]))
	{
		if(a[i]=='\n') break; 
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])
			{
				a[i]=0;	
				break;
			}	     
		}
		if(a[i]>0) i++;
	}
	int b='z';
	for(i=i;i<=25;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]==b)
			{
				j=-1;
				b--;
				continue;
			}
		}
		a[i]=b;
		b--;	
	}
	char c=0;
	while(fscanf(in,"%c",&c)!=EOF)
	{
		if(c>='a'&&c<='z')
		{
			c=a[c-'a'];
		}
		fputc(c,out);
	}
	fclose(in);
	fclose(out);
	return 0;
}
