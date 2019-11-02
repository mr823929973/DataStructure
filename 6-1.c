#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NHASH 3001
#define MULT 37
struct index
{
	int start;
	int num;
};
struct hash
{
	char *word;
	struct hash *next;
};
char word [3500][21]={};
int wordNum;
struct index list[26]={};
struct hash *hashList[NHASH]={};
void orderSearch(char *);
void binarySearch(char *);
void indexSearch(char *);
void hashSearch(char *);
void setupIndexList(void);
void setupHashList(void);
unsigned int hashCal(char *);
int main()
{
    FILE *in;
    in=fopen("dictionary3000.txt","r");
    int i=0;
    while(fscanf(in,"%s",word[i])!=EOF) i++;
    wordNum=i;
    fclose(in);
	int opt;
	char t[21];
	scanf("%s%d",t,&opt);
	switch(opt)
	{
		case 1: orderSearch(t); break;
		case 2: binarySearch(t); break;
		case 3: indexSearch(t); break;
		case 4: hashSearch(t); break;
	}
	return 0;
}
void orderSearch(char *t)
{
	int i;
	for(i=0;i<wordNum&&strcmp(t,word[i])>0;i++);
	if(strcmp(t,word[i])==0) printf("1 %d",i+1);
	else printf("0 %d",i+1);
	return;
}
void binarySearch(char *t)
{
	int i=0,l=0,r=wordNum-1,m=0;
	while(l<=r)
	{
		i++;
		m=(r+l)/2;
		if(strcmp(t,word[m])<0)
			r=m-1;
		else if(strcmp(t,word[m])>0)
			l=m+1;
		else
			break;	
	}
	if(strcmp(t,word[m])==0) printf("1 %d",i);
	else printf("0 %d",i);
	return;
}
void indexSearch(char *t)
{
	setupIndexList();
	int i=0,l=list[t[0]-'a'].start,r=l+list[t[0]-'a'].num-1,m=0;
	while(l<=r)
	{
		i++;
		m=(r+l)/2;
		if(strcmp(t,word[m])<0)
			r=m-1;
		else if(strcmp(t,word[m])>0)
			l=m+1;
		else
			break;	
	}
	if(strcmp(t,word[m])==0) printf("1 %d",i);
	else printf("0 %d",i);
	return;
}
void hashSearch(char *t)
{
	int i=0;
	unsigned int hash=0;
	struct hash *p=NULL;
	setupHashList();
	hash=hashCal(t);
	p=hashList[hash];
	while(p!=NULL)
	{
		i++;
		if(strcmp(t,p->word)<=0) break;
		p=p->next;
	}
	if(p==NULL||strcmp(t,p->word)!=0) printf("0 %d",i);
	else printf("1 %d",i);
	return;
}
void setupIndexList(void)
{
	int i=0,num=0,start=0;
	for(i=0;i<26;i++)
	{
		list[i].start=start;
		while(word[start][0]==i+'a') 
		{
			num++;
			start++;
		}
		list[i].num=num;
		num=0;
	}
	return;
}
void setupHashList(void)
{
	int i;
	unsigned hash=0;
	struct hash *p=NULL,*q=NULL;
	for(i=0;i<wordNum;i++)
	{
		hash=hashCal(word[i]);
		p=(struct hash*)malloc(sizeof(struct hash));
		p->next=NULL;
		p->word=word[i];
		if(hashList[hash]==NULL) hashList[hash]=p;
		else
		{
			q=hashList[hash];
			while(q->next!=NULL) q=q->next;
			q->next=p;
		}
	}
	return;
}
unsigned int hashCal(char *str)
{
	unsigned int h=0;
    char *p;
	for(p=str;*p!='\0';p++)
		h=MULT*h+*p;
    return h%NHASH;
}
