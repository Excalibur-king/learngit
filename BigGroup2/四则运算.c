#define EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED
#include<stdio.h>
#include<stdlib.h> 
#define MAXSIZE 20 
typedef struct Operand //操作数 
{
	int Data[MAXSIZE];
	int top;
 }Rand;
typedef struct Operator //运算符 
{
	char Data[MAXSIZE];
	int top;
}Rator;
//定义栈存放操作数和运算符 
Rand operands;
Rator operators;
//初始化栈
void InitOperand(Rand *ra)
{
	ra->top=-1;
 } 
void InitOperator(Rator *op)
{
	op->top=-1;
 } 
//判断栈是否为空
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
//进栈
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
//出栈
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
//取栈顶元素
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
 //判断字符是否为运算符
int InOp(char ch)
{
	if(ch=='('||ch==')'||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='#')
		return 1;
	return 0;
 } 
//判断运算符优先级
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
//比较运算符优先级
int Precede(char op1,char op2)
{
	if(Priority(op1)<Priority(op2))
		return 0;
	return 1;
 } 
//判断符号并运算
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
 //计算表达式
int ExCalculation(Rand *ra,Rator *op)
{
 	int a,b;
 	char ch,s;
	PushRator(op,'#');
	printf("请输入要计算的算式（以#结尾，注意！括号一定要是英文括号）：");
	ch=getchar();
	while(ch != '#' || GetTopRator(op)!='#') 
	{
		if(!InOp(ch))//不是运算符而是运算数 
		{
			int temp;
			temp = ch - '0';//字符转十进制 
			ch=getchar();
			while(!InOp(ch)) 
			{
				temp = temp *10 + ch - '0';//将逐个读入运算数的个位转化为位十进制数 
				ch = getchar();
			}
			PushRand(ra,temp);
 	 	} 
		else
		{
		  	if(GetTopRator(op) == '(')
		  	{
		  		if(ch == ')')	//右括号，将栈顶的运算符出栈，出栈再出栈，直到左括号。括号不作输出
		  			PopRator(op,&s);
		  		else
		  			PushRator(op,ch);//优先级大于栈顶运算符 栈顶为左括号，入栈 
		  		ch=getchar();
			}
			else
			{
				if(!Precede(GetTopRator(op),ch))//栈顶的运算符出栈；继续比较新的栈顶运算符(一直递归下去) 直到当前运算符大于栈顶运算符为止；
//   最后将当前运算符入栈；	
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
	printf("运算结果为%d\n",GetTopRand(ra));
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
		if(ch == '~') //在输入需要运算的算式时 ，在#后面输入~来退出循环，结束程序 
			exit(0); 
	}
	return 0;
}
