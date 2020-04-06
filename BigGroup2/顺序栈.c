#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100 //����ռ��ʼ������ 
#define STACKINCREMENT 10// �洢�ռ�������� 
#define OK 1
#define overflow -1
#define ERROR 0
#define ARRIR -1
typedef int StackType;//ջԪ������
typedef struct {
	StackType *base;
	StackType *top; //ջ��ָ��
	int stacksize;//��ǰ�ѷ���洢�ռ� 
}SqStack;
//ջ�ĳ�ʼ�� 
int InitStack(SqStack *p){
	p->base = (StackType*)malloc(STACK_INIT_SIZE* sizeof(StackType));
	if(p->base == NULL)
	{
		return ERROR;//�ڴ����ʧ�� 
	}
	p->top=p->base;//ջ����ջ����ͬ���ʾһ����ջ
	p->stacksize = STACK_INIT_SIZE;
	return OK; 
}
//�ж�ջ�Ƿ�Ϊ��
int EmptyStack(SqStack *p)
{
	if(p->top = p->base)
	return OK;
	else
	return ERROR;
 } 
 //˳��ջ��ѹ��
 int Push(SqStack *p,StackType e)
 {//����Ԫ��eΪ�µ�ջ��Ԫ��
 	if((p->top - p->base) >= p->stacksize)//ջ��
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
//˳��ջ�ĵ���
int Pop(SqStack *p,StackType *e)
{
	//��ջ���գ���ɾ��p��ջ��Ԫ�أ���e������ֵ
	if(p->top == p->base)
	return ERROR;
	--(p->top);
	 *e = *(p->top);
	return OK;
 } 
 //˳��ջ������
 int DestoryStack(SqStack *p)
 {
 	//�ͷ�ջ�׿ռ䲢�ÿ�
	 free(p->base);
	 p->base=NULL;
	 p->top=NULL;
	 p->stacksize=0;
	 return OK; 
  } 
  //˳��ջ�����
int ClearStack(SqStack *p)
{
  	p->top=p->base;
  	return OK;
}

//˳��ջ����
int StackLength(SqStack p)
{
	//ջ��ָ���ȥջ��ָ����ڳ��ȣ���Ϊջ��ָ��ָ��ǰջ��Ԫ�ص���һ��λ��
	return p.top-p.base; 
 } 
//����ջ��Ԫ��
int GetTop(SqStack *p,StackType *e)
{
	//��ջ��Ϊ�գ�������e����p��ջ��Ԫ��
	if(p->top>p->base)
	{
		*e = *(p->top-1);
		return OK;
	 } 
	 else return ERROR;
 } 
 
 void menu(){
	printf("*****************Ŀ¼******************\n");
	printf("ջ�ĳ���1\n");
	printf("ջ�Ķ�Ԫ��Ϊ2\n");
	printf("����ջ��Ԫ�أ�3\n");
	printf("���ջ4\n");
	printf("����ջ5\n");
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
 	int n,i,m;
 	StackType *e,a;
 	SqStack *pstack,stack;
 	pstack=&stack;
 	e=(StackType*)malloc(sizeof(StackType));//Ϊָ��e�����ڴ��ַ
	InitStack(pstack);//��ʼ��ջ
	if(EmptyStack(pstack)==1)
	printf("*********ջ��**********\n");
	printf("������ջ��Ԫ�ظ�����\n");
//	scanf("%d",&n);
	n=check();
	printf("�������������ݣ�\n");
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
		printf("���������ѡ��:");
//		scanf("%d",&m);
		m=check();
		switch(m)
		{
			case 1:
					printf("ջ�ĳ���Ϊ��%d\n",StackLength(stack));
					break;
			case 2: 
					GetTop(pstack,e);
					printf("ջ��Ԫ��Ϊ��%d\n",*e); 
					break;
			case 3:
					Pop(pstack,e);
					printf("������ջ��Ԫ��Ϊ:%d\n",*e);
					break;
			case 4:
					ClearStack(pstack);
					printf("ջ�Ƿ�Ϊ��:%d(1:�ǣ�0������)\n",EmptyStack(pstack));
					break;
			
			case 5:
					DestoryStack(pstack);
					if(DestoryStack(pstack) ==1)
						printf("������ջ\n");
					else printf("����ʧ��\n");
					break;
			case 6:
					ClearStack(pstack);
					if(EmptyStack(pstack)==OK)
					{ 
						printf("��ճɹ�\n");
						printf("������ջ��Ԫ�ظ�����\n");
						n=check();
						printf("�������������ݣ�\n");
						for(i=0;i<n;i++)
						{
							a=check();
							Push(pstack,a);
						 }
					}
					else
					printf("���ʧ��\n");
					 break;
			case 0:
					printf("�ѽ������򣡣���\n");
		}
	}
	while(m!=0);
	return 0;
 }
 
