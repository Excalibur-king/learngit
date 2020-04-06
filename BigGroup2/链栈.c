#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int selemtype;
//栈的链式存储结构
typedef struct snode{
	selemtype data; //数据域
	struct snode *next; //指针域 
}snode,*psnode;
//栈顶结点
typedef struct LinkStack
{
	psnode base;
	psnode top; //栈顶指针 
	int count; //栈的长度 
 } LinkStack;
 //初始化栈顶结点
 int InitLStack(LinkStack *s)
 {
 	s->top=(psnode)malloc(sizeof(snode));
 	if(!s->top)
 		return ERROR;
 	s->top=NULL;
 	s->count=0;
 	return OK;
  } 
  //判断栈是否为空
int isEmptyLStack(LinkStack *s)
{
  	if(s->top==NULL)
	{
  		return OK;
	}
	else
	{
		return ERROR;
	}
}
//遍历栈
int TraverseLStack(LinkStack *s)
{
	int i;
	if(isEmptyLStack(s)==OK)
	return ERROR;
	psnode p=s->top;
	for(i=s->count;i>0;i--)
	{
		printf("栈中元素：%d\n",p->data);
		p=p->next;
	 } 
	 printf("\n");
	 return OK;
 } 
//链表元素入栈
int PushLStack(LinkStack *s,selemtype e)
{
	psnode p=(psnode)malloc(sizeof(snode));
	if(!p) return ERROR;
	p->data = e;
	p->next = s->top; //新结点指向栈顶指针指向的地址 
	s->top = p;    //更新栈顶指针 
	s->count++; //结点增加一 
	return OK;
 } 
//获取栈顶元素
int gettop(LinkStack *s,selemtype *e )
{
	if(isEmptyLStack(s)==OK)
	return ERROR;
	*e = s->top->data;
	return OK;
}
//链栈元素出栈
int PopLStack(LinkStack *s, selemtype *e)
{
	if(isEmptyLStack(s)==OK)
	return ERROR;
	psnode temp =s->top;
	*e=temp->data;
	s->top=temp->next;
	s->count--;
	free(temp);
	return OK; 
} 

 //清空栈
int ClearLStack(LinkStack *s)
{
	psnode p;
	while(s->top)
	{
		p=s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return OK;
 } 
//销毁栈
int DestoryLStack(LinkStack *s)
{
	psnode p,q=NULL;
	if(isEmptyLStack(s)==ERROR)
	{
		p = s->top;
		int i;
		for(i=s->count;i>0;i--)
		{
			q = p->next;
			free(p);
			p=q;
		}
		s->count = 0;
		return OK;
	}
	else
	return ERROR;
	
 } 
//栈的长度
int LStacklength(LinkStack s)
{

	return s.count;
	

 } 
 
 void menu(){
	printf("*****************目录******************\n");
	printf("栈链的长度1\n");
	printf("栈链的顶元素为2\n");
	printf("弹出栈链元素：3\n");
	printf("清空栈链4\n");
	printf("销毁栈链5\n");
	printf("重新输入6\n");
	printf("结束程序0\n");
	printf("***************************************\n"); 
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
 
int main()
{
	int m;
	LinkStack s,*ps;
	selemtype a,*e;
	e=(selemtype*)malloc(sizeof(selemtype));
	ps = &s;
	InitLStack(ps);
	int n;
//	isEmptyLStack(ps);
	printf("请输入入栈元素个数：\n");
	n=check(); 
	printf("请输入整型的入栈元素：\n");
	int i;
	for(i=0;i<n;i++)
	{
		a=check(); 
		PushLStack(ps,a);
	}
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
					
					printf("栈的长度为：%d\n",LStacklength(s));
					break;
			case 2: 
					TraverseLStack(ps);
					gettop(ps,e);
					printf("栈顶元素为：%d\n",*e); 
					break;
			case 3:
					TraverseLStack(ps);
					PopLStack(ps,e);
					printf("弹出的栈链顶元素为: %d\n",*e);
					break;
			case 4:
					ClearLStack(ps);
					printf("栈是否为空:%d(1:是;2：不是)\n",isEmptyLStack(ps)); 
					break;
			
			case 5:
					DestoryLStack(ps);
					if(DestoryLStack(ps) == OK)
						printf("已销毁栈\n");
					else printf("销毁失败\n");
					break;
			case 6:	ClearLStack(ps);
					if(isEmptyLStack(ps) == OK)
					{	
						printf("已清空栈\n");
						printf("请输入入栈元素个数：\n");
						n=check(); 
						printf("请输入整型的入栈元素：\n");
						int i;
						for(i=0;i<n;i++)
						{
							a=check(); 
							PushLStack(ps,a);
						}
					}
					else printf("清空失败\n");
					break;
					
			case 0:
					printf("已结束程序！！！\n");
		}
	}
	while(m!=0);
	return 0;
 }
   
   
