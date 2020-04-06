#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int selemtype;
//ջ����ʽ�洢�ṹ
typedef struct snode{
	selemtype data; //������
	struct snode *next; //ָ���� 
}snode,*psnode;
//ջ�����
typedef struct LinkStack
{
	psnode base;
	psnode top; //ջ��ָ�� 
	int count; //ջ�ĳ��� 
 } LinkStack;
 //��ʼ��ջ�����
 int InitLStack(LinkStack *s)
 {
 	s->top=(psnode)malloc(sizeof(snode));
 	if(!s->top)
 		return ERROR;
 	s->top=NULL;
 	s->count=0;
 	return OK;
  } 
  //�ж�ջ�Ƿ�Ϊ��
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
//����ջ
int TraverseLStack(LinkStack *s)
{
	int i;
	if(isEmptyLStack(s)==OK)
	return ERROR;
	psnode p=s->top;
	for(i=s->count;i>0;i--)
	{
		printf("ջ��Ԫ�أ�%d\n",p->data);
		p=p->next;
	 } 
	 printf("\n");
	 return OK;
 } 
//����Ԫ����ջ
int PushLStack(LinkStack *s,selemtype e)
{
	psnode p=(psnode)malloc(sizeof(snode));
	if(!p) return ERROR;
	p->data = e;
	p->next = s->top; //�½��ָ��ջ��ָ��ָ��ĵ�ַ 
	s->top = p;    //����ջ��ָ�� 
	s->count++; //�������һ 
	return OK;
 } 
//��ȡջ��Ԫ��
int gettop(LinkStack *s,selemtype *e )
{
	if(isEmptyLStack(s)==OK)
	return ERROR;
	*e = s->top->data;
	return OK;
}
//��ջԪ�س�ջ
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

 //���ջ
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
//����ջ
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
//ջ�ĳ���
int LStacklength(LinkStack s)
{

	return s.count;
	

 } 
 
 void menu(){
	printf("*****************Ŀ¼******************\n");
	printf("ջ���ĳ���1\n");
	printf("ջ���Ķ�Ԫ��Ϊ2\n");
	printf("����ջ��Ԫ�أ�3\n");
	printf("���ջ��4\n");
	printf("����ջ��5\n");
	printf("��������6\n");
	printf("��������0\n");
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
	printf("��������ջԪ�ظ�����\n");
	n=check(); 
	printf("���������͵���ջԪ�أ�\n");
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
		printf("���������ѡ��:");
//		scanf("%d",&m);
		m=check();
		switch(m)
		{
			case 1:
					
					printf("ջ�ĳ���Ϊ��%d\n",LStacklength(s));
					break;
			case 2: 
					TraverseLStack(ps);
					gettop(ps,e);
					printf("ջ��Ԫ��Ϊ��%d\n",*e); 
					break;
			case 3:
					TraverseLStack(ps);
					PopLStack(ps,e);
					printf("������ջ����Ԫ��Ϊ: %d\n",*e);
					break;
			case 4:
					ClearLStack(ps);
					printf("ջ�Ƿ�Ϊ��:%d(1:��;2������)\n",isEmptyLStack(ps)); 
					break;
			
			case 5:
					DestoryLStack(ps);
					if(DestoryLStack(ps) == OK)
						printf("������ջ\n");
					else printf("����ʧ��\n");
					break;
			case 6:	ClearLStack(ps);
					if(isEmptyLStack(ps) == OK)
					{	
						printf("�����ջ\n");
						printf("��������ջԪ�ظ�����\n");
						n=check(); 
						printf("���������͵���ջԪ�أ�\n");
						int i;
						for(i=0;i<n;i++)
						{
							a=check(); 
							PushLStack(ps,a);
						}
					}
					else printf("���ʧ��\n");
					break;
					
			case 0:
					printf("�ѽ������򣡣���\n");
		}
	}
	while(m!=0);
	return 0;
 }
   
   
