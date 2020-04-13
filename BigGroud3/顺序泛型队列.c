#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXQUEUE 20
#define AQUEUE_H_INCLUDED
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    char datatype[MAXQUEUE];
    int rear;
    int length;           //队列长度
    //一个节点可存放不同的数据
    int type[MAXQUEUE];    //存放进入队列的数据类型 
} AQueue;
typedef enum
{
    FALSE=0, TRUE=1
}Status;

void InitAQueue(AQueue *Q)// 初始化队列
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
}
void DestoryAQueue(AQueue *Q)//销毁队列 
{
	int i; 
	if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return;
    }
	for(i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}
Status IsFullAQueue(const AQueue *Q)//判满 
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q))
        return FALSE;
    if(LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else
        return FALSE;
}
int IsEmptyAQueue(const AQueue *Q)//判空 
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}
Status GetHeadAQueue(AQueue *Q,void *e)//找队头 
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！没有队头！\n");
		return FALSE;
	}
	int i=Q->front;
	i=(i+1)%MAXQUEUE;  
	memcpy(e, Q->data[i],20);
//	e=Q->data[Q->front];
    return TRUE;
}
int LengthAQueue(AQueue *Q)//队长 
    {
        return (Q->rear-Q->front+Q->length)%Q->length;
    }
Status EnAQueue(AQueue *Q, void *data)//入队)
{
	if (IsFullAQueue(Q))
	{
		printf("队列满了！不能再入队了！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, 20);
		Q->rear = (Q->rear + 1) % Q->length;
		return TRUE;
	}
    memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}

Status DeAQueue(AQueue *Q)//出队 
    {
    	if (IsEmptyAQueue(Q))
    	{
    		printf("队列是空的！出不了队！\n");
    		return FALSE;
    	}
        Q->front = (Q->front+1)%Q->length;
        return TRUE;
    }
void ClearAQueue(AQueue *Q)//清空 
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列已经是空的了！\n");
		return;
	}
    Q->front = Q->rear = 0; 
}
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, char type))//遍历 
    {
        if(Q->data[0] == NULL)
        {
            printf("队列目前未初始化！请先初始化队列！\n");
            return FALSE;
        }
    	if (IsEmptyAQueue(Q))
    	{
    		printf("队列里面什么都没有!\n");
    		return FALSE;
    	}
    	int i = 0;
    	printf("请输出队列：\n");
    	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
    		foo(Q->data[Q->front+i], Q->datatype[Q->front+i]);
    		i = (i + 1) % MAXQUEUE;
    	}
    	printf("\n");
        return TRUE;
    }
void APrint(void *q, char type)
    {
        if(type=='f')
            printf("%.2lf\n", *(double*)q);
        else if(type=='c')
            printf("%c\n", *(char*)q);
        else if(type=='d')
            printf("%d\n", *(int *)q);
        else if(type=='s')
            printf("%s\n", (char*)q);
    }
 void menu(){
	printf("*****************目录******************\n");
	printf("8.初始化队列\n");
	printf("9.判空\n");
	printf("10.判满\n");
	printf("1.队列的长度\n");
	printf("2.队列的第一个元素\n");
	printf("3.出列：\n");
	printf("4.清空队列\n");
	printf("5.销毁队列\n");
	printf("6.选择类型\n");
	printf("7.输出队列\n");
	printf("0.结束程序\n");
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

void typeselect(AQueue *Q){
	if(Q->data[0]==NULL)
	{
		printf("未初始化\n");
		return;
	}
	int t;
	printf("你想入队哪种类型？:\n");
    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
	t=check();
    while(t<1 || t>4)
    {
     	printf("应输入在[1,4]之间的整数！\n请重输：");
		t=check();
    }
    switch(t)
    {
     	case 1:{
			int a;
    		printf("想入队的数据:\n");
			a=check();
			Q->datatype[Q->rear]='d';
			EnAQueue(Q,&a);
			break;
		}
		case 2: {
			char a ;
			printf("想入队的数据:\n");
			scanf("%c",&a);
			Q->datatype[Q->rear]='c';
			EnAQueue(Q,&a);
			break;
		}
        case 3:{
			double a ;
    		printf("想入队的数据 :");
			scanf("%lf", &a);
			Q->datatype[Q->rear]='f';	
			EnAQueue(Q, &a);
			break;
		}
        case 4:{
			char a[20];
			printf("最大长度为20\n");
			printf("想入队的数据 :");
			scanf("%s",a);
			Q->datatype[Q->rear]='s';
			EnAQueue(Q,a);
			break;
		}
	}
}

int main()
{
	AQueue *Q;
	int i,n,t,b,l;
	void *e, *data;
	Q=NULL;
	Q=(AQueue*)malloc(sizeof(AQueue));
	e=(void*)malloc(10);
	data=(void*)malloc(10);
	do{
		menu();
		printf("请输入你的选择:\n");
		scanf("%d",&t);
		switch(t)
		{
			case 8:
					InitAQueue(Q);
					break;
			case 9:
					IsEmptyAQueue(Q);
					break;
			case 10:
					IsFullAQueue(Q);
					break; 
			case 1:
					printf("%d\n",LengthAQueue(Q));
					break;
			case 2:
					GetHeadAQueue(Q,e);
					if(GetHeadAQueue(Q,e) == 1)
					{
						printf("队头元素为:\n");
						APrint(e,Q->datatype[Q->front]); 
					}
					break;
			case 3:
					DeAQueue(Q);
					break;
			case 4:
					ClearAQueue(Q);
					if(LengthAQueue(Q)==0)
						printf("清空成功\n");
					else
						printf("清空失败\n");
					break;	
			case 5:
					DestoryAQueue(Q);
					if(Q->data[0]==NULL)
						printf("销毁成功\n");
					else
						printf("销毁失败\n");
					break;
			case 6:
					typeselect(Q);
					break;					
			case 7:
					TraverseAQueue(Q,APrint);					
					break;
			case 0:
				 	printf("已结束程序！！！\n");
					break;
			default:
					printf("输入错误，重新输入\n"); 
		}
		printf("\n");
		if(t!=0){
			system("pause");
			system("cls");
		}
	}while(t!=0);
	return 0;
}

	


