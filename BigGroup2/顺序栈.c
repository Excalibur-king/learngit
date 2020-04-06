#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100 //储存空间初始分配量 
#define STACKINCREMENT 10// 存储空间分配增量 
#define OK 1
#define overflow -1
#define ERROR 0
#define ARRIR -1
typedef int StackType;//栈元素类型
typedef struct {
	StackType *base;
	StackType *top; //栈顶指针
	int stacksize;//当前已分配存储空间 
}SqStack;
//栈的初始化 
int InitStack(SqStack *p){
	p->base = (StackType*)malloc(STACK_INIT_SIZE* sizeof(StackType));
	if(p->base == NULL)
	{
		return ERROR;//内存分配失败 
	}
	p->top=p->base;//栈顶与栈底相同则表示一个空栈
	p->stacksize = STACK_INIT_SIZE;
	return OK; 
}
//判断栈是否为空
int EmptyStack(SqStack *p)
{
	if(p->top = p->base)
	return OK;
	else
	return ERROR;
 } 
 //顺序栈的压入
 int Push(SqStack *p,StackType e)
 {//插入元素e为新的栈顶元素
 	if((p->top - p->base) >= p->stacksize)//栈满
	 {
	  	p->base = (StackType*)realloc(p->base,(p->stacksize+STACKINCREMENT)*sizeof(StackType));
	  	if(p->base==NULL)
	  	return ERROR;
	  	p->top = p->base+p->stacksize;
		p->stacksize +=STACKINCREMENT;
 	 }
 	 *(p->top) = e;
 	 (p->top)++;
 	 return OK;
  } 
//顺序栈的弹出
int Pop(SqStack *p,StackType *e)
{
	//若栈不空，则删除p的栈顶元素，用e返回其值
	if(p->top == p->base)
	return ERROR;
	--(p->top);
	 *e = *(p->top);
	return OK;
 } 
 //顺序栈的销毁
 int DestoryStack(SqStack *p)
 {
 	//释放栈底空间并置空
	 free(p->base);
	 p->base=NULL;
	 p->top=NULL;
	 p->stacksize=0;
	 return OK; 
  } 
  //顺序栈的清空
int ClearStack(SqStack *p)
{
  	p->top=p->base;
  	return OK;
}

//顺序栈长度
int StackLength(SqStack p)
{
	//栈顶指针减去栈底指针等于长度，因为栈底指针指向当前栈顶元素的下一个位置
	return p.top-p.base; 
 } 
//返回栈顶元素
int GetTop(SqStack *p,StackType *e)
{
	//若栈不为空，，则用e返回p的栈顶元素
	if(p->top>p->base)
	{
		*e = *(p->top-1);
		return OK;
	 } 
	 else return ERROR;
 } 
 
 void menu(){
	printf("*****************目录******************\n");
	printf("栈的长度1\n");
	printf("栈的顶元素为2\n");
	printf("弹出栈顶元素：3\n");
	printf("清空栈4\n");
	printf("销毁栈5\n");
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
 	int n,i,m;
 	StackType *e,a;
 	SqStack *pstack,stack;
 	pstack=&stack;
 	e=(StackType*)malloc(sizeof(StackType));//为指针e分配内存地址
	InitStack(pstack);//初始化栈
	if(EmptyStack(pstack)==1)
	printf("*********栈空**********\n");
	printf("请输入栈的元素个数：\n");
//	scanf("%d",&n);
	n=check();
	printf("请输入整型数据：\n");
	for(i=0;i<n;i++)
	{
//		scanf("%d",&a);
		a=check();
		Push(pstack,a);
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
					printf("栈的长度为：%d\n",StackLength(stack));
					break;
			case 2: 
					GetTop(pstack,e);
					printf("栈顶元素为：%d\n",*e); 
					break;
			case 3:
					Pop(pstack,e);
					printf("弹出的栈顶元素为:%d\n",*e);
					break;
			case 4:
					ClearStack(pstack);
					printf("栈是否为空:%d(1:是；0：不是)\n",EmptyStack(pstack));
					break;
			
			case 5:
					DestoryStack(pstack);
					if(DestoryStack(pstack) ==1)
						printf("已销毁栈\n");
					else printf("销毁失败\n");
					break;
			case 6:
					ClearStack(pstack);
					if(EmptyStack(pstack)==OK)
					{ 
						printf("清空成功\n");
						printf("请输入栈的元素个数：\n");
						n=check();
						printf("请输入整型数据：\n");
						for(i=0;i<n;i++)
						{
							a=check();
							Push(pstack,a);
						 }
					}
					else
					printf("清空失败\n");
					 break;
			case 0:
					printf("已结束程序！！！\n");
		}
	}
	while(m!=0);
	return 0;
 }
 
