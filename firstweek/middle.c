#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ERROR 0;
typedef struct LNode
{
	int data;                                        //������ 
	struct LNode *next ;                             //ָ���� 
}LNode,*LinkList;

LinkList InitList( LinkList L)                       //��ʼ������������һ���µ����Ա�L 
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
//			printf("�������Ҫ�������\n"); 
			k=0;
		}
		else
		{
			k=1;
			printf("���������Ӵ���Ԫ�ؿ�ʼ��������\n");
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
			printf("������е�Ϊ%d",mid->data);
			break;
		}
		search=search->next->next;
		if(search==NULL)
		{
			printf("������е�Ϊ%d %d",mid->data,mid->next->data);
			break;
		}
		mid=mid->next;
	}
	printf("\n");
}

LinkList CreateList_L(LinkList L,int n)//����һ������ 
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
		printf("������Ԫ�ظ���:");
		if((scanf("%d",&n))==1)
		{
			printf("�������Ҫ�������\n"); 
			k=0;
		}
		else
		{
			k=1;
			printf("�����������������\n");
			while(getchar()!='\n');
		}
	}
	while(k); 
	printf("��������%d������Ԫ��:",n);
	L=CreateList_L(L,n);
	CentreValue(L);
	return 0;
}
