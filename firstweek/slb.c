#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define ERROR 0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct DuLNode
{
	int data;//������ 
	struct DuLNode*next;
	struct DuLNode*pre;//ָ���� 
}DuLNode,*DuLinkList;

DuLinkList InitList( DuLinkList L)                       //��ʼ������������һ���µ����Ա�L 
{
	DuLinkList node=NULL;
	node=(DuLinkList)malloc(sizeof(DuLNode));
	if(!node)
	{
		return 0;
	}
	node->next=NULL;
	node->pre=NULL; 
	L=node;
	return L;
}

DuLinkList CreateList_L (DuLinkList L)
{
	int n,a,i;
	DuLinkList p,r,head;
	head=(DuLinkList)malloc(sizeof(DuLinkList));
	head->next=NULL;
	head->pre=NULL;
	r=head;
	printf("������Ԫ�ظ�����\n");
	n=check();
	printf("������Ԫ�أ�\n");
	for(i=0;i<n;i++)
	{
		p=(DuLinkList)malloc(sizeof(DuLinkList));
		a=check();
		p->data=a;
		r->next=p;
		p->pre=r;
		r=p;
	}
	r->next=NULL;
	p=r->next;
	return (head);
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



int main(int argc, char *argv[]) 
{
	int n,m,i,e,k;
	DuLinkList L=NULL,p=NULL;
	L=InitList(L);
	L=CreateList_L(L);
	printf("���������Ԫ��Ϊ:");
	p=L->next;
	while(p!=NULL)
	{
		printf(" %d",p->data);
		p=p->next; 
	}
	printf("\n");
	return 0;
}
