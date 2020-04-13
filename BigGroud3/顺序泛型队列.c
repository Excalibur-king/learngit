#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXQUEUE 20
#define AQUEUE_H_INCLUDED
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������
    int front;
    char datatype[MAXQUEUE];
    int rear;
    int length;           //���г���
    //һ���ڵ�ɴ�Ų�ͬ������
    int type[MAXQUEUE];    //��Ž�����е��������� 
} AQueue;
typedef enum
{
    FALSE=0, TRUE=1
}Status;

void InitAQueue(AQueue *Q)// ��ʼ������
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
}
void DestoryAQueue(AQueue *Q)//���ٶ��� 
{
	int i; 
	if(Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return;
    }
	for(i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}
Status IsFullAQueue(const AQueue *Q)//���� 
{
    if(Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
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
int IsEmptyAQueue(const AQueue *Q)//�п� 
{
    if(Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}
Status GetHeadAQueue(AQueue *Q,void *e)//�Ҷ�ͷ 
{
	if (IsEmptyAQueue(Q))
	{
		printf("����Ϊ�գ�û�ж�ͷ��\n");
		return FALSE;
	}
	int i=Q->front;
	i=(i+1)%MAXQUEUE;  
	memcpy(e, Q->data[i],20);
//	e=Q->data[Q->front];
    return TRUE;
}
int LengthAQueue(AQueue *Q)//�ӳ� 
    {
        return (Q->rear-Q->front+Q->length)%Q->length;
    }
Status EnAQueue(AQueue *Q, void *data)//���)
{
	if (IsFullAQueue(Q))
	{
		printf("�������ˣ�����������ˣ�\n");
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

Status DeAQueue(AQueue *Q)//���� 
    {
    	if (IsEmptyAQueue(Q))
    	{
    		printf("�����ǿյģ������˶ӣ�\n");
    		return FALSE;
    	}
        Q->front = (Q->front+1)%Q->length;
        return TRUE;
    }
void ClearAQueue(AQueue *Q)//��� 
{
	if (IsEmptyAQueue(Q))
	{
		printf("�����Ѿ��ǿյ��ˣ�\n");
		return;
	}
    Q->front = Q->rear = 0; 
}
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, char type))//���� 
    {
        if(Q->data[0] == NULL)
        {
            printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
            return FALSE;
        }
    	if (IsEmptyAQueue(Q))
    	{
    		printf("��������ʲô��û��!\n");
    		return FALSE;
    	}
    	int i = 0;
    	printf("��������У�\n");
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
	printf("*****************Ŀ¼******************\n");
	printf("8.��ʼ������\n");
	printf("9.�п�\n");
	printf("10.����\n");
	printf("1.���еĳ���\n");
	printf("2.���еĵ�һ��Ԫ��\n");
	printf("3.���У�\n");
	printf("4.��ն���\n");
	printf("5.���ٶ���\n");
	printf("6.ѡ������\n");
	printf("7.�������\n");
	printf("0.��������\n");
	printf("***************************************\n"); 
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

void typeselect(AQueue *Q){
	if(Q->data[0]==NULL)
	{
		printf("δ��ʼ��\n");
		return;
	}
	int t;
	printf("��������������ͣ�:\n");
    printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n");
	t=check();
    while(t<1 || t>4)
    {
     	printf("Ӧ������[1,4]֮���������\n�����䣺");
		t=check();
    }
    switch(t)
    {
     	case 1:{
			int a;
    		printf("����ӵ�����:\n");
			a=check();
			Q->datatype[Q->rear]='d';
			EnAQueue(Q,&a);
			break;
		}
		case 2: {
			char a ;
			printf("����ӵ�����:\n");
			scanf("%c",&a);
			Q->datatype[Q->rear]='c';
			EnAQueue(Q,&a);
			break;
		}
        case 3:{
			double a ;
    		printf("����ӵ����� :");
			scanf("%lf", &a);
			Q->datatype[Q->rear]='f';	
			EnAQueue(Q, &a);
			break;
		}
        case 4:{
			char a[20];
			printf("��󳤶�Ϊ20\n");
			printf("����ӵ����� :");
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
		printf("���������ѡ��:\n");
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
						printf("��ͷԪ��Ϊ:\n");
						APrint(e,Q->datatype[Q->front]); 
					}
					break;
			case 3:
					DeAQueue(Q);
					break;
			case 4:
					ClearAQueue(Q);
					if(LengthAQueue(Q)==0)
						printf("��ճɹ�\n");
					else
						printf("���ʧ��\n");
					break;	
			case 5:
					DestoryAQueue(Q);
					if(Q->data[0]==NULL)
						printf("���ٳɹ�\n");
					else
						printf("����ʧ��\n");
					break;
			case 6:
					typeselect(Q);
					break;					
			case 7:
					TraverseAQueue(Q,APrint);					
					break;
			case 0:
				 	printf("�ѽ������򣡣���\n");
					break;
			default:
					printf("���������������\n"); 
		}
		printf("\n");
		if(t!=0){
			system("pause");
			system("cls");
		}
	}while(t!=0);
	return 0;
}

	


