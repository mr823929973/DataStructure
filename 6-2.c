#include<stdio.h>
#include<stdlib.h>
struct student
{
	int id;
	char name[21];
	int pos;
};
struct student list[100]={};
int seatlist[100]={};
int cmp1(const void*,const void*);
int cmp2(const void*,const void*);
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	FILE *in,*out;
	in=fopen("in.txt","r");
	for(i=0;i<n;i++)
	{
		fscanf(in,"%d%s%d",&list[i].id,list[i].name,&list[i].pos);
	}
	fclose(in);
	qsort(list,n,sizeof(struct student),cmp1);
	int q,m;
	m=list[n-1].pos;
	if(m<n) q=m;
	else q=n;
	for(i=0;i<n;i++)
	{
		seatlist[list[i].pos]+=1;
	}
	int j;
	for(i=1,j=1;i<=q;i++)
	{
		if(seatlist[i]==0)
		{
			if(list[n-j].pos>i)
			{
			seatlist[list[n-j].pos]-=1;
			list[n-j].pos=i;
			seatlist[i]+=1;	
			j++;
			}
		}
	}
	int k;
	for(i=1;i<n;i++)
	{
		if(seatlist[i]==0) break;
	}
	m=i-1;
	for(i=1,k=1;i<=m;i++)
	{
		if(seatlist[i]==2)
		{
			for(j=0;j<n;j++)
			{
				if(list[j].pos==i) break;
			}
			seatlist[i]--;
			list[j+1].pos=m+k;
			seatlist[m+k]++;
			k++;
		}
	}
	qsort(list,n,sizeof(struct student),cmp2);
	out=fopen("out.txt","w");	
	for(i=0;i<n;i++)
	{
		fprintf(out,"%d %s %d\n",list[i].id,list[i].name,list[i].pos);
	}
	fclose(out);
	return 0;
} 
int cmp1(const void *a,const void *b)
{
	struct student *a1=(struct student *)a,*b1=(struct student *)b;
	if((a1->pos-b1->pos)!=0) return a1->pos-b1->pos;
	else return a1->id-b1->id;
}
int cmp2(const void *a,const void *b)
{
	struct student *a1=(struct student *)a,*b1=(struct student *)b;
	return a1->id-b1->id;
}
