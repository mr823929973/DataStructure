#include<stdio.h>
#include<string.h>
int main()
{
	char string[500]={0};
	scanf("%s",string);
	int len;
	len=strlen(string);
    int i;
    int j;
    printf("%c",string[0]);
	for(i=1;i<len;i++)
	{
		if(string[i]=='-')
		{
			if(('0'<=string[i-1]&&string[i-1]<string[i+1]&&string[i+1]<='9')||('a'<=string[i-1]&&string[i-1]<string[i+1]&&string[i+1]<='z')||('A'<=string[i-1]&&string[i-1]<string[i+1]&&string[i+1]<='Z'))
			{
				for(j=string[i-1]+1;j<string[i+1];j++) printf("%c",j);
				continue;
			 } 
		}
		printf("%c",string[i]);
	}
	return 0;
}
