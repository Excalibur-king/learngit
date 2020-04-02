#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ERROR 0;
typedef struct LNode
{
	int data;                                        //数据域 
	struct LNode *next ;                             //指针域 
}LNode,*LinkList;

LinkList InitList( LinkList L)                       //初始化操作，建立一个新的线性表L 
{
	LinkList node=NULL;
	node=(LinkList)malloc(sizeof(LNode));
	if(!node)
	{
		return ERROR;
	}
	node->next=NULL;
	L=node;
	return L;
}

int check()
{
	int k,a;
	do
	{
		if((scanf("%d",&a))==1)
		{
//			printf("输入符合要求，请继续\n"); 
			k=0;
		}
		else
		{
			k=1;
			printf("输入错误，请从错误元素开始重新输入\n");
			while(getchar()!='\n');
		}
	}
	while(k);
	return a; 
}

void CentreValue(LinkList L)
{
	LinkList mid,search;
	mid=L->next;
	search=L->next;
	while(search)
	{
		if(search->next==NULL)
		{
			printf("链表的中点为%d",mid->data);
			break;
		}
		search=search->next->next;
		if(search==NULL)
		{
			printf("链表的中点为%d %d",mid->data,mid->next->data);
			break;
		}
		mid=mid->next;
	}
	printf("\n");
}

LinkList CreateList_L(LinkList L,int n)//创建一个链表 
{
	int i,a;
	LinkList p,r;
	r=L;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
//		scanf("%d",&a); 
		a=check();
		p->data=a;
		r->next=p;
		r=p;
	}
	r->next=NULL;
	p=r->next; 
	return L;	
}

int main()
{
	int n,m,b,i,e,k;
	int* g;
	LinkList L=NULL,p=NULL;
	L=InitList(L);
	do
	{
		printf("请输入元素个数:");
		if((scanf("%d",&n))==1)
		{
			printf("输入符合要求，请继续\n"); 
			k=0;
		}
		else
		{
			k=1;
			printf("输入错误，请重新输入\n");
			while(getchar()!='\n');
		}
	}
	while(k); 
	printf("依次输入%d个数据元素:",n);
	L=CreateList_L(L,n);
	CentreValue(L);
	return 0;
}
