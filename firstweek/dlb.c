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

//in
//	int k,a;
//	if((scanf("%d",&a))!=1)
//	{
//		printf("输入错误，请重新输入\n");
//		break;			
//	}
//}
//	while(k);
//	return a; 
//}
//t Check()
//{

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

LinkList ListInsert(LinkList L,int i,int e)//在线性表L中第i个位置插入新的元素e 
{
	int j=0;
	LinkList s=NULL,p=NULL;
	p=L;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		printf("输入的位置不合法！\n");
		return L;
	}
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return L;
}

void menu(){
	printf("*****************目录******************\n");
	printf("输出单链表中的各元素值1\n");
	printf("在单链表中插入数据元素2\n");
	printf("结束程序0\n");
	printf("***************************************\n"); 
}
 
void main()
{
	int n,m,i,e,k;
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
	do
	{
		printf("\n\n");
		menu();
		printf("请输入你的选择:");
//		scanf("%d",&m);
		m=check();
		switch(m)
		{
			case 1:
					printf("现在链表的元素为:");
					p=L->next;
					while(p!=NULL)
					{
						printf(" %d",p->data);
						p=p->next; 
					}
					printf("\n");
					break;
			case 2: 
					printf("依次输入插入位置和数据元素（空格隔开）:");
//						scanf("%d %d",&i,&e);
						i=check();
						e=check();
					L=ListInsert(L,i,e);
					break;
			case 0:
					printf("已结束程序！！！\n");
		}
		
	}while(m!=0);
}

