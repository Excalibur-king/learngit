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

//初始化队列
void InitQueue(LinkQueue *Q);
//判断队列是否为空
bool Empty(LinkQueue Q);
//入队(和尾插法基本一样)
void EnQueue(LinkQueue *Q, ElemType e);
//出队
bool DeQueue(LinkQueue *Q, ElemType *e);
//遍历队列
void Traverse(LinkQueue Q);
//#include "LinkQueue.h"

//初始化队列
void InitQueue(LinkQueue *Q) {
 Q->front = (Node*)malloc(sizeof(Node));
 Q->front->data = -1;
 Q->front->next = NULL;
 Q->rear = Q->front;
}

//判断队列是否为空
bool Empty(LinkQueue Q) {
 if (Q.front == Q.rear)
  return true;
 else
  return false;
}

//入队(和尾插法基本一样)
void EnQueue(LinkQueue *Q, ElemType e) {
 Node* pNew = (Node*)malloc(sizeof(Node));
 pNew->data = e;
 pNew->next = NULL;

 pNew->next = Q->rear->next;
 Q->rear->next = pNew;
 Q->rear = pNew;
}

//出队
bool DeQueue(LinkQueue *Q, ElemType *e) {
 if (Empty(*Q))
  return false;
 Node *temp = Q->front->next;
 Q->front->next = Q->front->next->next;
 free(temp);
 return true;
}

// 获取队头元素：用e返回Q的队头元素
int GetFrontElem(LinkQueue *Q,int e)
{
	if(Q->front==Q->rear) 
		return false;
	e=Q->front->next->data;
	return true;
}
 
 
//遍历队列
void Traverse(LinkQueue Q) {
 Node *p = Q.front->next;
 while (p) {
  printf("%d->", p->data);
  p = p->next;
 }
 printf("NULL\n");
}
//#include "LinkQueue.h"
//2-销毁：销毁一个队列Q
void DestroyLQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
	}
}
 
//3-清空：清空一个队列Q
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

void menu(){
	printf("\n");
	printf("1.输出队列里的元素:\n");
	printf("2.清空队列\n");
	printf("3.销毁队列\n");
	printf("4.获取头元素\n");
	printf("5.重新输入：\n");
	printf("0.结束程序\n");
	printf("\n"); 
}
int main()
{
 	LinkQueue Q;
 	ElemType e;
 	Node q;
 	InitQueue(&Q);
 	int i,n,a,t,b;
 	printf("请输入元素个数\n");
//	scanf("%d",&n);
	n=check(); 
    printf("请输入元素：\n"); 
	for(i=0;i<n;i++)
	{
//		scanf("%d",&a);
		a=check();
		EnQueue(&Q,a);
	}
	do{
		menu();
		printf("请选择：\n");
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
						printf("清空成功\n");
					}
					else
						printf("清空失败\n");
					break;
			case 3:
					DestroyLQueue(&Q);
					if(Empty(Q)==1)
					{
						printf("销毁成功\n");
					}
					else
						printf("销毁失败\n");
					break;
			case 4:
					GetFrontElem(&Q,b);
					printf("头元素为：%d\n",b);
					break;
			case 5:
					ClearLQueue(&Q);
					DestroyLQueue(&Q);
					if(Empty(Q)==1)
					{
						InitQueue(&Q);
						printf("请输入元素个数\n");
//						scanf("%d",&n);
						n=check(); 
    					printf("请输入元素：\n"); 
						for(i=0;i<n;i++)
						{
//							scanf("%d",&a);
							a=check();
							EnQueue(&Q,a);
						}
					}					
					else
						printf("操作失败\n");
					break;
			case 0:
					printf("程序结束\n"); 
		}
	}while(t!=0);
	

 return 0;
}
