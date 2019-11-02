#include<stdio.h>
#include<stdlib.h>
typedef struct tr
{
	int num;
	struct tr *left;
	struct tr *right; 
}tree,*trpr;
void travel(trpr,int);
int main()
{
	int n,i;
	scanf("%d",&n);
	trpr p=NULL,q=NULL,root=NULL;
	for(i=0;i<n;i++)
	{
		p=(trpr)malloc(sizeof(tree));
		p->left=NULL;
		p->right=NULL;
		scanf("%d",&(p->num));
		if(root==NULL)  root=p;
		else
		{
			q=root;
			while(1)
			{
				if(p->num<q->num)
					if(q->left!=NULL)
						q=q->left;
					else
					{
						q->left=p;
						break;
					}
				else
				{
					if(q->right!=NULL)
						q=q->right;
					else
					{
						q->right=p;
						break;
					}
				}		
			}
		}
	}
	travel(root,1);
	return 0;
}
void travel(trpr p,int i)
{
	if(p==NULL) return;
	travel(p->left,i+1);
	travel(p->right,i+1);
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->num,i);
	}
	return ;
}
