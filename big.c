#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
//#define MAXWORDLENTH 50 
#define MAXDIC 650000
#define MAXWORD 1120000
#define MAXSAME 3000

//unsigned int seed=13331;
typedef struct hashDictionary
{
	char *word;
	int len;
	struct hashDictionary *link;
}hashs,*hashp;
//hash�ֵ� 


typedef struct sameLocation
{
	unsigned long long Loc;
	struct sameLocation *link;
}Location,*Lop;
//�����洢���λ�� 

typedef struct hashSameword
{
	char *word;
	int len;
	int times;
	Lop x;
}hashw,*hashwp;
//hash�洢���󵥴ʣ� 

hashp dict[MAXDIC]={};
hashwp wrongWord[MAXSAME]={};


void hashListSetup();
int hashSearch(char *,int,unsigned int);
char *readArticle();
int articleProcess(char *);
int comp(const void *a,const void *b);
void output();

int main()
{
	int i;
	char *head;
	hashListSetup();
	head=readArticle();
	i=articleProcess(head);
	qsort(wrongWord,i,sizeof(hashwp),comp);
	output(); 
	return 0; 
}
void hashListSetup()
{
	unsigned int lSize;
	FILE *dicin;
	char *dic=NULL,*p=NULL,*dich=NULL;
	dicin=fopen("dictionary.txt","r");
	fseek(dicin,0,SEEK_END);
	lSize=ftell(dicin)+1;
	rewind(dicin);
	dich=(char*)malloc(sizeof(char)*lSize);
	memset(dich,0,lSize);
	fread(dich,sizeof(char),lSize,dicin);
	fclose(dicin);
	hashp tmp=NULL;
	hashp t=NULL;
	unsigned int hash=0;
	dic=dich;
	while(*dic!=0&&dic-dich<=lSize)
	{
		while(isalpha(*dic)==0) dic++;
		p=dic;
		hash=5381;
		while(isalpha(*p)>0)
		{
			hash = ((hash << 5) + hash) + *p;
			//hash=hash+(p-dic+1)*(seed*(*p)<<(p-dic+1));
			++p;
		}
		hash=hash%(MAXDIC);
		tmp=(hashp)malloc(sizeof(hashs));
		tmp->word=dic;
		tmp->len=p-dic;
		tmp->link=NULL;
		if(dict[hash]==NULL)
		{
			dict[hash]=tmp;
		} 
		else
		{
			t=dict[hash];
			while(t->link!=NULL) t=t->link;
			t->link=tmp;
		} 
		dic=p+1;
	}
	return;
}
int hashSearch(char *wd,int len,unsigned hash)
{
	hashp tmp=NULL;
	if(dict[hash]==NULL) return 1;
	else
	{
		tmp=dict[hash];
		while(tmp!=NULL)
		{
			if(len!=tmp->len) ;
			else if (strncmp(wd,tmp->word,len)==0) return 0;
			tmp=tmp->link;
		}
		return 1;
	}
}
char *readArticle()
{
	unsigned long long lSize;
	FILE *artin;
	char *art=NULL;
	artin=fopen("article.txt","r");
	fseek(artin,0,SEEK_END);
	lSize=ftell(artin)+1;
	rewind(artin);
	art=(char*)malloc(sizeof(char)*lSize);
	memset(art,0,lSize);
	fread(art,sizeof(char),lSize,artin);
	fclose(artin);
	return art;
}
int articleProcess(char *head)
{
	char *art=head,*p=head;
	int loc;
	int i;
	int len;
	unsigned int hash;
	Lop tmp=NULL;
	while(*art!=0)
	{
		while(isalpha(*art)==0) 
		{
			if(*art!=0) art++;
			else goto flag; 
		}
		p=art;
		hash=5381;
		while(isalpha(*p)>0)
		{
			*p=tolower(*p);
			hash = ((hash << 5) + hash) + *p;
		//	hash=hash+(p-art+1)*(seed*(*p)<<(p-art+1));
			++p;
		}
		hash=hash%(MAXDIC);
		len=p-art;
		loc=art-head; 
		if(hashSearch(art,len,hash)>0)
		{
			i=0;
			while(1)
			{
				if(wrongWord[i]==NULL)
				{
					wrongWord[i]=(hashwp)malloc(sizeof(hashw));
					wrongWord[i]->len=len;
					wrongWord[i]->word=art;
					wrongWord[i]->times=1;
					wrongWord[i]->x=(Lop)malloc(sizeof(Location));
					wrongWord[i]->x->Loc=loc;
					wrongWord[i]->x->link=NULL;
					break;
				}
			 
			
				else if(len==wrongWord[i]->len&&strncmp(wrongWord[i]->word,art,len)==0)
				{
					wrongWord[i]->times+=1;
					tmp=wrongWord[i]->x;
					while(tmp->link!=NULL)	tmp=tmp->link;
					tmp->link=(Lop)malloc(sizeof(Location));
					tmp->link->Loc=loc;	
					tmp->link->link=NULL;
					break;
				}
				++i;
			}
		}
		art=p;
	}
flag:for(i=0;i<MAXSAME;++i)
		if(wrongWord[i]==NULL) break;
return i;
}
int comp(const void *a,const void *b)
{
	hashwp tmp1=*(hashwp*)a, tmp2=*(hashwp*)b;
	int len;
	if(tmp1->times>tmp2->times) return -1;
	else if(tmp2->times>tmp1->times) return 1;
	else
	{
		len=tmp1->len>tmp2->len?tmp2->len:tmp1->len;
		if(strncmp(tmp1->word,tmp2->word,len)>0) return 1;
		else if(strncmp(tmp1->word,tmp2->word,len)<0) return -1;
		else return tmp1->len-tmp2->len;
	}
}
void output()
{
	FILE *out;
	out=fopen("misspelling.txt","w");
	int i=0;
	int j;
	Lop temp=NULL;
	while(wrongWord[i]!=NULL)
	{
		for(j=0;j<wrongWord[i]->len;++j)
		 	putc(wrongWord[i]->word[j],out);
		fprintf(out," ");
		fprintf(out,"%d ",wrongWord[i]->times);
		temp=wrongWord[i]->x;
		while(temp!=NULL)
		{
			fprintf(out,"%llu ",temp->Loc);
			temp=temp->link;
		}
		 fprintf(out,"\n");
		 ++i;
	}
	fclose(out);
}
