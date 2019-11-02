#include<stdio.h>
#include<string.h>
int main()
{
	char Formula[500]={0};
	int Number[500]={0};
	char Symbol[500]={0};
	int len;
	gets (Formula);
	len=strlen(Formula);
	int i,j,k,tmp; j=k=0;
	for(i=0;i<len;i++)
	{
		if(Formula[i]==' ') continue;
		else if (Formula[i]=='+'||Formula[i]=='-'||Formula[i]=='*'||Formula[i]=='/'||Formula[i]=='=')
		{
			Symbol[j]=Formula[i];
			j++;
		}
		else
		{
			tmp=0;
			tmp=Formula[i]-'0';
			while(Formula[i+1]<='9'&&Formula[i+1]>='0')
			{
				tmp=10*tmp+Formula[i+1]-'0';
				i++;
			}
			Number[k]=tmp;
			k++;
		}
		
	}
    //yixia shi jisuan(xian jisuan chengchu hou jisuan jiajian)
	 int sum;
	 for(i=0;i<k;i++)
     {
     	if(Symbol[i]=='*')
     	{
     		Number[i+1]=Number[i]*Number[i+1];
     		Number[i]=-1;
     		Symbol[i]=0;
		 }
			if(Symbol[i]=='/')
     	{
     		Number[i+1]=Number[i]/Number[i+1];
     		Number[i]=-1;
     		Symbol[i]=0;
		 } 
	 }
	 j=0;
	 while(Number[j]<0)
	 {
	 	j++;
	 }
	 sum=Number[j];
	 //printf("%d %d %d\n",j,Number[j],sum);
	 j++;
	 for(i=0;i<k;i++)
	 {
	 	while(Number[j]<0) j++;
		if(Symbol[i]=='+')
		{
			sum+=Number[j]; 	//printf("%d %d %d\n",j,Number[j],sum);
			j++;
		}
        if(Symbol[i]=='-') 
        {
			sum-=Number[j]; 	//printf("%d %d %d\n",j,Number[j],sum);
			j++;
		}

	 }
    printf("%d",sum);
	return 0;
 } 
 
