#include<stdio.h>
int main()
{
	char a[21][21]={};
	int i,j;
	for(i=1;i<=19;i++)
    	for(j=1;j<=19;j++)
    		scanf(" %c",&a[i][j]);
    for(i=1;i<=19;i++) //hengxiang
		for(j=0;j<=16;j++)
			{
			  if((a[i][j]!='0'&&a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2]&&a[i][j]==a[i][j+3])&&(a[i][j+4]=='0'||a[i][j-1]=='0'))
			  {
			  	printf("%c:%d,%d",a[i][j],i,j);
			  	return 0;
			  }
			}
	for(j=1;j<=19;j++) //zongxiang
		for(i=0;i<=16;i++)
			{
			  if((a[i][j]!='0'&&a[i][j]==a[i+1][j]&&a[i][j]==a[i+2][j]&&a[i][j]==a[i+3][j])&&(a[i+4][j]=='0'||a[i-1][j]=='0'))
			  {
			  	printf("%c:%d,%d",a[i][j],i,j);
			  	return 0;
			  }
			}
	int k=0;		
	for(i=1;i<=15;i++) //zuoxia youshang
	 for(j=1,k=i;k<=16;k++,j++)
	  if((a[k][j]!='0'&&a[k][j]==a[k+1][j+1]&&a[k][j]==a[k+2][j+2]&&a[k][j]==a[k+3][j+3])&&(a[k+4][j+4]=='0'||a[k-1][j-1]=='0'))
			  {
			  	printf("%c:%d,%d",a[k][j],k,j);
			  	return 0;
			   }		   
	for(j=2;j<=15;j++)
	 for(i=1,k=j;k<=16;k++,i++)
	  if((a[i][k]!='0'&&a[i][k]==a[i+1][k+1]&&a[i][k]==a[i+2][k+2]&&a[i][k]==a[i+3][k+3])&&(a[i+4][k+4]=='0'||a[i-1][k-1]=='0'))
			  {
			  	printf("%c:%d,%d",a[i][k],i,k);
			  	return 0;
			   }
	for(i=19;i>=5;i--)
	 for(j=1,k=i;k>=4;j++,k--)
		if((a[k][j]!='0'&&a[k][j]==a[k-1][j+1]&&a[k][j]==a[k-2][j+2]&&a[k][j]==a[k-3][j+3])&&(a[k-4][j+4]=='0'||a[k+1][j-1]=='0'))
			  {
			  	printf("%c:%d,%d",a[k][j],k-3,j+3);
			  	return 0;
			   }
	for(j=2;j<=15;j++)
	 for(i=19,k=j;k<=16;i--,k++)
	  if((a[i][k]!='0'&&a[i][k]==a[i-1][k+1]&&a[i][k]==a[i-2][k+2]&&a[i][k]==a[i-3][k+3])&&(a[i-4][k+4]=='0'||a[i+1][k-1]=='0'))
			  {
			  	printf("%c:%d,%d",a[i][k],i-3,k+3);
			  	return 0;
			   }		   		  		   		   
    printf("No");		
    return 0;		
    		
}
