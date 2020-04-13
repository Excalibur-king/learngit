#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX 10
typedef int bool;
typedef int ElemType;
typedef struct Node
{
 ElemType data;
 struct Node *next;
}Node;
typedef struct {
 Node *front;
 Node *rear;
}LinkQueue;

//��ʼ������
void InitQueue(LinkQueue *Q);
//�ж϶����Ƿ�Ϊ��
bool Empty(LinkQueue Q);
//���(��β�巨����һ��)
void EnQueue(LinkQueue *Q, ElemType e);
//����
bool DeQueue(LinkQueue *Q, ElemType *e);
//��������
void Traverse(LinkQueue Q);
//#include "LinkQueue.h"

//��ʼ������
void InitQueue(LinkQueue *Q) {
 Q->front = (Node*)malloc(sizeof(Node));
 Q->front->data = -1;
 Q->front->next = NULL;
 Q->rear = Q->front;
}

//�ж϶����Ƿ�Ϊ��
bool Empty(LinkQueue Q) {
 if (Q.front == Q.rear)
  return true;
 else
  return false;
}

//���(��β�巨����һ��)
void EnQueue(LinkQueue *Q, ElemType e) {
 Node* pNew = (Node*)malloc(sizeof(Node));
 pNew->data = e;
 pNew->next = NULL;

 pNew->next = Q->rear->next;
 Q->rear->next = pNew;
 Q->rear = pNew;
}

//����
bool DeQueue(LinkQueue *Q, ElemType *e) {
 if (Empty(*Q))
  return false;
 Node *temp = Q->front->next;
 Q->front->next = Q->front->next->next;
 free(temp);
 return true;
}

// ��ȡ��ͷԪ�أ���e����Q�Ķ�ͷԪ��
int GetFrontElem(LinkQueue *Q,int e)
{
	if(Q->front==Q->rear) 
		return false;
	e=Q->front->next->data;
	return true;
}
 
 
//��������
void Traverse(LinkQueue Q) {
 Node *p = Q.front->next;
 while (p) {
  printf("%d->", p->data);
  p = p->next;
 }
 printf("NULL\n");
}
//#include "LinkQueue.h"
//2-���٣�����һ������Q
void DestroyLQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
	}
}
 
//3-��գ����һ������Q
void ClearLQueue(LinkQueue *Q)
{
	Node *p,*s;
	Q->rear=Q->front;
	p=Q->front->next;
	s=p;
	while(p)
	{
		s=p->next;
		free(p);
		p=s;
	}
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

void menu(){
	printf("\n");
	printf("1.����������Ԫ��:\n");
	printf("2.��ն���\n");
	printf("3.���ٶ���\n");
	printf("4.��ȡͷԪ��\n");
	printf("5.�������룺\n");
	printf("0.��������\n");
	printf("\n"); 
}
int main()
{
 	LinkQueue Q;
 	ElemType e;
 	Node q;
 	InitQueue(&Q);
 	int i,n,a,t,b;
 	printf("������Ԫ�ظ���\n");
//	scanf("%d",&n);
	n=check(); 
    printf("������Ԫ�أ�\n"); 
	for(i=0;i<n;i++)
	{
//		scanf("%d",&a);
		a=check();
		EnQueue(&Q,a);
	}
	do{
		menu();
		printf("��ѡ��\n");
//		scanf("%d",&t);
		t=check();
		switch(t){
			case 1:
					Traverse(Q);
					break;
			case 2:
					ClearLQueue(&Q); 
					if(Empty(Q)==1)
					{
						printf("��ճɹ�\n");
					}
					else
						printf("���ʧ��\n");
					break;
			case 3:
					DestroyLQueue(&Q);
					if(Empty(Q)==1)
					{
						printf("���ٳɹ�\n");
					}
					else
						printf("����ʧ��\n");
					break;
			case 4:
					GetFrontElem(&Q,b);
					printf("ͷԪ��Ϊ��%d\n",b);
					break;
			case 5:
					ClearLQueue(&Q);
					DestroyLQueue(&Q);
					if(Empty(Q)==1)
					{
						InitQueue(&Q);
						printf("������Ԫ�ظ���\n");
//						scanf("%d",&n);
						n=check(); 
    					printf("������Ԫ�أ�\n"); 
						for(i=0;i<n;i++)
						{
//							scanf("%d",&a);
							a=check();
							EnQueue(&Q,a);
						}
					}					
					else
						printf("����ʧ��\n");
					break;
			case 0:
					printf("�������\n"); 
		}
	}while(t!=0);
	

 return 0;
}
