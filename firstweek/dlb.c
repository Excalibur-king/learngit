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

//in
//	int k,a;
//	if((scanf("%d",&a))!=1)
//	{
//		printf("�����������������\n");
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

LinkList ListInsert(LinkList L,int i,int e)//�����Ա�L�е�i��λ�ò����µ�Ԫ��e 
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
		printf("�����λ�ò��Ϸ���\n");
		return L;
	}
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return L;
}

void menu(){
	printf("*****************Ŀ¼******************\n");
	printf("����������еĸ�Ԫ��ֵ1\n");
	printf("�ڵ������в�������Ԫ��2\n");
	printf("��������0\n");
	printf("***************************************\n"); 
}
 
void main()
{
	int n,m,i,e,k;
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
	do
	{
		printf("\n\n");
		menu();
		printf("���������ѡ��:");
//		scanf("%d",&m);
		m=check();
		switch(m)
		{
			case 1:
					printf("���������Ԫ��Ϊ:");
					p=L->next;
					while(p!=NULL)
					{
						printf(" %d",p->data);
						p=p->next; 
					}
					printf("\n");
					break;
			case 2: 
					printf("�����������λ�ú�����Ԫ�أ��ո������:");
//						scanf("%d %d",&i,&e);
						i=check();
						e=check();
					L=ListInsert(L,i,e);
					break;
			case 0:
					printf("�ѽ������򣡣���\n");
		}
		
	}while(m!=0);
}

