#include<stdio.h>
#include<stdlib.h>
int a[100]={};
int t=0;
void selectSort(int k[ ],int n)   
{    
	int i,j,d;
    int  temp;
    for(i=0;i<n-1;i++)
	{
    	d=i;
    	for(j=i+1;j<n;j++)
    	{
    		t++;
    		if(k[j]<k[d]) d=j;
		}
        if(d!=i)
		{    
        	temp=k[d];
        	k[d]=k[i];
            k[i]=temp;
        }
    }
    for(i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%d",t);
    return;
}
void bubbleSort(int k[ ],int n)
{     
	int i, j, flag=1;
    int temp;
    for(i=n-1;i>0&&flag==1;i--)
	{
    	flag=0;                      
        for(j=0;j<i;j++) 
        {
        	t++;
        	if(k[j]>k[j+1])
			{
            temp=k[j];
            k[j]=k[j+1];
            k[j+1]=temp;  
            flag=1;             
        	}
    	}
    }
    for(i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%d",t);
    return;
}
void adjust(int k[ ],int i,int n)
{

	int j,temp;
    temp=k[i];
    j=2*i+1;
    while(j<n)
	{
		if(j<n-1 && k[j]<k[j+1]) j++;
		t++;
        if(temp>=k[j]) break;
        k[(j-1)/2]=k[j];
        j=2*j+1;
    }
	k[(j-1)/2]=temp;
    return;
}
void heapSort(int k[ ],int n)
{
    int i;
    int temp;
    for(i=n/2-1;i>=0;i--) adjust(k,i,n);
    for(i=n-1;i>=1;i--)
	{
    	temp=k[i];
        k[i]=k[0];
        k[0]=temp;
        adjust(k,0,i);
    }
    for(i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%d",t);
}
void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend)
{     
	int i=left, j=leftend+1, q=left;
    while(i<=leftend && j<=rightend)
    {
    	t++;
    	if(x[i]<=x[j]) tmp[q++]=x[i++];
        else tmp[q++]=x[j++];
    }
    while(i<=leftend) tmp[q++]=x[i++];
    while(j<=rightend) tmp[q++]=x[j++];
    for(i=left; i<=rightend; i++) x[i]=tmp[i];
}
void mSort(int k[], int tmp[], int left, int right)
{
    int center;
    if(left < right)
	{
        center = (left+right)/2;
        mSort(k, tmp, left, center);
        mSort(k, tmp, center+1, right);
        merge(k, tmp, left,center, right);
    }
}
void mergeSort(int k[ ],int n)
{
    int *tmp;
    tmp = (int *)malloc(sizeof(int) * n);
    if(tmp != NULL) 
	{
        mSort(k, tmp, 0, n-1);
        free(tmp);
    } 
    int i;
    for(i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%d",t);
}
void swap(int *i, int *j)
{
    int tmp;
    tmp = *i; *i = *j; *j=tmp;
}
void quickSort(int k[ ],int left,int right)
{     

    int i, last;
    if(left<right)
	{
        last=left; 
        for(i=left+1;i<=right;i++)
        {
        	t++;
			if(k[i]<k[left])
            	swap(&k[++last],&k[i]); 
		}
        swap(&k[left],&k[last]);
        quickSort(k,left,last-1); 
        quickSort(k,last+1,right);   
    }
}
int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	switch(m)
	{
		case 1:selectSort(a,n); break;
		case 2:bubbleSort(a,n); break;
		case 3:heapSort(a,n); break;
		case 4:mergeSort(a,n); break;
		case 5:quickSort(a,0,n-1); for(i=0;i<n;i++) printf("%d ",a[i]);printf("\n%d",t);break;
	}
	return 0;
}
