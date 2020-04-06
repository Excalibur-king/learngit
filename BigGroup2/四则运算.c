#define EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED
#include<stdio.h>
#include<stdlib.h> 
#define MAXSIZE 20 
typedef struct Operand //������ 
{
	int Data[MAXSIZE];
	int top;
 }Rand;
typedef struct Operator //����� 
{
	char Data[MAXSIZE];
	int top;
}Rator;
//����ջ��Ų������������ 
Rand operands;
Rator operators;
//��ʼ��ջ
void InitOperand(Rand *ra)
{
	ra->top=-1;
 } 
void InitOperator(Rator *op)
{
	op->top=-1;
 } 
//�ж�ջ�Ƿ�Ϊ��
int EmptyRand(Rand *ra)
{
	ra->top = -1;
	return 0;
 } 
int  EmptyRator(Rator *op)
{
	op->top = -1;
	return 0;
}
//��ջ
int PushRand(Rand *ra,int e)
{
	if(ra->top == MAXSIZE-1)
		return 0;
	ra->top++;
	ra->Data[ra->top] = e;
	return 1;
 } 
int PushRator(Rator *op,char e)
{
	if(op->top == MAXSIZE-1)
		return 0;
	op->top++;
	op->Data[op->top] = e;
	return 1;
 } 
//��ջ
int PopRand(Rand *ra,int *e)
{
	if(ra->top == -1)
		return 0;
	*e = ra->Data[ra->top];
	ra->top--;
	return 1;
 } 
int PopRator(Rator *op,char *e)
{
	if(op->top == -1)
		return 0;
	*e = op->Data[op->top];
	op->top--;
	return 1;
 } 
//ȡջ��Ԫ��
int GetTopRand(Rand *ra)
{
	if(ra->top == -1)
		return 0;
	return ra->Data[ra->top]; 
 }
char GetTopRator(Rator *op)
{
 	if(op->top == -1)
		return 0;
	return op->Data[op->top]; 
}
 //�ж��ַ��Ƿ�Ϊ�����
int InOp(char ch)
{
	if(ch=='('||ch==')'||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='#')
		return 1;
	return 0;
 } 
//�ж���������ȼ�
int Priority(char s)
{
	switch(s)
	{
		case '(' :
			return 4;
		case '*' :
		case '/' :
			return 3;
		case '+' :
		case '-' :
			return 2;	
   		case ')' :
   			return 1;
   		default :
   			return 0;
    }
	
 } 
//�Ƚ���������ȼ�
int Precede(char op1,char op2)
{
	if(Priority(op1)<Priority(op2))
		return 0;
	return 1;
 } 
//�жϷ��Ų�����
int Calculation(int a,int b,char c)
{
	switch(c)
	{
		case '+' :
			return a+b;
		case '-' :
			return a-b;
		case '*' :
			return a*b;
		case '/' :
			if(b==0)
				exit(1);
			return a/b;
	}
 } 
 //������ʽ
int ExCalculation(Rand *ra,Rator *op)
{
 	int a,b;
 	char ch,s;
	PushRator(op,'#');
	printf("������Ҫ�������ʽ����#��β��ע�⣡����һ��Ҫ��Ӣ�����ţ���");
	ch=getchar();
	while(ch != '#' || GetTopRator(op)!='#') 
	{
		if(!InOp(ch))//������������������� 
		{
			int temp;
			temp = ch - '0';//�ַ�תʮ���� 
			ch=getchar();
			while(!InOp(ch)) 
			{
				temp = temp *10 + ch - '0';//����������������ĸ�λת��Ϊλʮ������ 
				ch = getchar();
			}
			PushRand(ra,temp);
 	 	} 
		else
		{
		  	if(GetTopRator(op) == '(')
		  	{
		  		if(ch == ')')	//�����ţ���ջ�����������ջ����ջ�ٳ�ջ��ֱ�������š����Ų������
		  			PopRator(op,&s);
		  		else
		  			PushRator(op,ch);//���ȼ�����ջ������� ջ��Ϊ�����ţ���ջ 
		  		ch=getchar();
			}
			else
			{
				if(!Precede(GetTopRator(op),ch))//ջ�����������ջ�������Ƚ��µ�ջ�������(һֱ�ݹ���ȥ) ֱ����ǰ���������ջ�������Ϊֹ��
//   ��󽫵�ǰ�������ջ��	
				{
					PushRator(op,ch);
					ch = getchar();
				}
				else
				{
					PopRand(ra,&b);
					PopRand(ra,&a);
					PopRator(op,&s);
					PushRand(ra,Calculation(a,b,s));
					
				}
			}
	  	}
	}
	printf("������Ϊ%d\n",GetTopRand(ra));
	return 0;
}
int main()
{
	InitOperand(&operands);
	InitOperator(&operators);
	while(1)
	{
		char ch;
		ExCalculation(&operands,&operators);
		EmptyRand(&operands);
		EmptyRator(&operators);
		ch = getchar();
		if(ch == '~') //��������Ҫ�������ʽʱ ����#��������~���˳�ѭ������������ 
			exit(0); 
	}
	return 0;
}
