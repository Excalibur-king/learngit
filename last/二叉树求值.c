#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
 
#define StackInitSize 100
#define max 20
#define isNum 1
#define isCha 0
#define lenNum sizeof(struct nodeNum)
#define lenCha sizeof(struct nodeCha)
#define lenBiTree sizeof(struct biTreeNode)
 
//操作数节点元素
struct nodeNum{
    int number;
};
//操作符节点元素
struct nodeCha{
    char ch;
};
//共用体
typedef union demo{
    int number;
    char cha;
}Demo;
//二叉树节点
struct biTreeNode{
    int flag;
    Demo useUnion;
    struct biTreeNode *lchild;
    struct biTreeNode *rchild;
};
//二叉树节点栈     ！会初始化两个二叉树节点栈！
struct biTreeStack{
    struct biTreeNode *base;
    struct biTreeNode *top;
    int stackSize;
};
//操作数栈
struct numStack{
    struct nodeNum *base;
    struct nodeNum *top;
    int stackSize;
};
//操作符栈
struct chaStack{
    struct nodeCha *base;
    struct nodeCha *top;
    int stackSize;
};
//初始化二叉树栈
void biTreeInitStack(struct biTreeStack *stack)
{
    stack->base = (struct biTreeNode *)malloc(StackInitSize * lenBiTree);
    if(!stack->base)
    {
        printf("初始化失败，退出程序！\n");
        exit(0);
    }
    stack->top = stack->base;
    stack->stackSize = StackInitSize;
}
//初始化操作数栈
void numInitStack(struct numStack *stack1)
{
    stack1->base = (struct nodeNum *)malloc(StackInitSize * lenNum);
    if(!stack1->base)
    {
        printf("初始化失败，退出程序！\n");
        exit(0);
    }
    stack1->top = stack1->base;
    stack1->stackSize = StackInitSize;
}
//初始化操作符栈
void chaInitStack(struct chaStack *stack2)
{
    stack2->base = (struct nodeCha *)malloc(StackInitSize * lenCha);
    if(!stack2->base)
    {
        printf("初始化失败，退出程序！\n");
        exit(0);
    }
    stack2->top = stack2->base;
    stack2->stackSize = StackInitSize;
}
//压入操作符
void chaPush(struct chaStack *stack3,char ch)
{
    if(stack3->top - stack3->base >= stack3->stackSize)
    {
        printf("栈满！\n退出程序！\n");
        exit(0);
    }
    stack3->top->ch = ch;
    stack3->top++;
}
//压入操作数
void numPush(struct numStack *stack4,int number)
{
    if(stack4->top - stack4->base >= stack4->stackSize)
    {
        printf("栈满！\n退出程序！\n");
        exit(0);
    }
    stack4->top->number = number;
    stack4->top++;
}
//压入栈节点
void biTreeNodePush(struct biTreeStack *curBiTree,struct biTreeNode curTreeNode)
{
    if(curBiTree->top - curBiTree->base >= curBiTree->stackSize)
    {
        printf("栈满！\n退出程序！\n");
        exit(0);
    }
    *curBiTree->top = curTreeNode;
    curBiTree->top++;
}
//弹出栈节点
struct biTreeNode *biTreeNodePop(struct biTreeStack *curBiTree)
{
    if(curBiTree->top != curBiTree->base)
    {
        curBiTree->top--;
        return curBiTree->top;
    }
    else
    {
         printf("栈已空！\n退出程序！\n");
         exit(0);
    }
}
void recoverPtr(struct biTreeStack *curBiTree)
{
    curBiTree->top++;
    curBiTree->top++;
}
//弹出操作符
char chaPop(struct chaStack *stack5)
{
    if(stack5->top != stack5->base)
    {
        stack5->top--;
        return stack5->top->ch;
    }
    else
    {
         printf("栈已空！\n退出程序！\n");
         exit(0);
    }
}
//弹出操作数
int numPop(struct numStack *stack6)
{
    if(stack6->top != stack6->base)
    {
        stack6->top--;
        return stack6->top->number;
    }
    else
    {
        printf("栈已空！\n退出程序！\n");
        exit(0);
    }
}
//运算符栈取顶
char chaGetTop(struct chaStack stack7)
{
    if(stack7.top >= stack7.base)
    {
        stack7.top--;
        return stack7.top->ch;
    }
    else
    {
        printf("栈已空！\n退出程序！\n");
        exit(0);
    }
}
//运算数栈取顶
int numGetTop(struct numStack stack8)
{
    if(stack8.top >= stack8.base)
    {
        stack8.top--;
        return stack8.top->number;
    }
    else
    {
        printf("栈已空！\n退出程序！\n");
        exit(0);
    }
}
//判断并返回算符间的优先关系
char Precede(char ch1,char ch2)
{
    char ch = ' ';
    switch(ch1)
    {
        case '$':
            if('+' == ch2||'-' == ch2||'*' == ch2||'/' == ch2||'(' == ch2)
            {
                ch = '<';
            }
            else if(')' == ch2)
            {
                printf("输入有误！\n退出程序！\n");
                exit(0);
            }
            else if('$' == ch2)
            {
                ch = '=';
            }
        break;
        case ')':
            if('+' == ch2||'-' == ch2||'*' == ch2||'/' == ch2||')' == ch2||'$' == ch2)
            {
                ch = '>';
            }
            else if('(' == ch2)
            {
                printf("输入有误！\n退出程序！\n");
                exit(0);
            }
        break;
        case '(':
            if('+' == ch2||'-' == ch2||'*' == ch2||'/' == ch2||'(' == ch2)
            {
                ch = '<';
            }
            else if(')' == ch2)
            {
                ch = '=';
            }
            else if('$' == ch2)
            {
                printf("输入有误！\n退出程序！\n");
                exit(0);
            }
        break;
        case '/':
            if('+' == ch2||'-' == ch2||'*' == ch2||'/' == ch2||')' == ch2||'$' == ch2)
            {
                ch = '>';
            }
            else if('(' == ch2)
            {
                ch = '<';
            }
        break;
        case '*':
            if('+' == ch2||'-' == ch2||'*' == ch2||'/' == ch2||')' == ch2||'$' == ch2)
            {
                ch = '>';
            }
            else if('(' == ch2)
            {
                ch = '<';
            }
        break;
        case '-':
            if('+' == ch2||'-' == ch2||')' == ch2||'$' == ch2)
            {
                ch = '>';
            }
            else if('*' == ch2||'/' == ch2||'(' == ch2)
            {
                ch = '<';
            }
        break;
        case '+':
            if('+' == ch2||'-' == ch2||')' == ch2||'$' == ch2)
            {
                ch = '>';
            }
            else if('*' == ch2||'/' == ch2||'(' == ch2)
            {
                ch = '<';
            }
        break;
        default:
            {
                printf("非法输入！\n退出程序！\n");
                exit(0);
            }
    }
    return ch;
}
//将弹出的数进行计算
int Operate(int numa,char ch,int numb)
{
    int number = 0;
    switch(ch)
    {
        case '+':
            number = numa + numb;
        break;
        case '-':
            number = numa - numb;
        break;
        case '*':
            number = numa * numb;
        break;
        case '/':
            number = numa / numb;
        break;
    }
    return number;
}
//先序遍历二叉树
void preOrder(struct biTreeNode *biTree)
{
    if(biTree->flag == isNum)
    {
        printf("%d   ",biTree->useUnion.number);
    }
    else if(biTree->flag == isCha)
    {
        printf("%c   ",biTree->useUnion.cha);
    }
    if(biTree->lchild != NULL) preOrder(biTree->lchild);
    if(biTree->rchild != NULL) preOrder(biTree->rchild);
}
//后序遍历二叉树
void aftOrder(struct biTreeNode *biTree)
{
    if(biTree->lchild != NULL) aftOrder(biTree->lchild);
    if(biTree->rchild != NULL) aftOrder(biTree->rchild);
    if(biTree->flag == isNum)
    {
        printf("%d   ",biTree->useUnion.number);
    }
    else if(biTree->flag == isCha)
    {
        printf("%c   ",biTree->useUnion.cha);
    }
}
//显示二叉树
void outPutBiTree(struct biTreeNode *biTree)
{
    if(biTree != NULL)
    {
        if(biTree->flag == isNum)
        {
            printf("%d ",biTree->useUnion.number);
        }
        else if(biTree->flag == isCha)
        {
            printf("%c ",biTree->useUnion.cha);
        }
    }
    if(biTree->lchild != NULL)
    {
        printf("(");
        outPutBiTree(biTree->lchild);
        printf(",");
    }
    if(biTree->rchild != NULL)
    {
        outPutBiTree(biTree->rchild);
        printf(")");
    }
}//销毁二叉树
void destoryTree(struct biTreeNode *biTree){
	if(biTree==NULL)
		return;
	if(biTree->lchild!=NULL){
		destoryTree(biTree->lchild);
		biTree->lchild=NULL;
	}
	if(biTree->rchild!=NULL){
		destoryTree(biTree->rchild);
		biTree->rchild=NULL;
	}
	if(biTree!=NULL){
		free(biTree);
		biTree=NULL;
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
void menu()
{
	printf("*********************\n");
	printf("1.销毁二叉树:\n");
	printf("2.创建二叉树:\n");
	printf("0.退出程序:\n");
	printf("*********************\n"); 
 } 
//表达式求值并创建二叉树
//int doEvaluateExpression()
int main() 
{
    char ch,x,the;
    int numa,numb;
    int count;
    int i,temp;
    long number,num[max];
    struct numStack opnd;//定义操作数栈 
    struct chaStack optr;//定义操作符栈 
    struct biTreeNode tempTreeNode,*finTreeNode,*treeNode_1,*treeNode_2;//定义树节点 
    struct biTreeStack binaryTree,binaryTree_0;//定义二叉树结点栈 
    numInitStack(&opnd);//初始化操作数栈
    chaInitStack(&optr);//初始化操作符栈
    biTreeInitStack(&binaryTree);//初始化二叉树节点栈
    biTreeInitStack(&binaryTree_0);//初始化二叉树节点栈副本
    chaPush(&optr,'$');//压入操作符 
    printf("请输入表达式(以$号结束):\n");
    ch = getchar();
    while(!(ch == '$' && chaGetTop(optr) == '$'))
    {
        if(isdigit(ch))    //如果是数字就进运算数栈
        {
            count = 0;
            number = 0;
            while(isdigit(ch))//如果getchar()得到的是数字,则连续读
            {
                count++;
                num[count-1] = ch-48;
                ch = getchar();
            }
            temp = count;
            for(i = 0; i < count; i++)//判断数字有几位
            {
                temp--;
                number += num[i] * pow(10,temp);
            }
            numPush(&opnd,number);
            tempTreeNode.flag = isNum;
            tempTreeNode.useUnion.number = number;
            tempTreeNode.rchild = NULL;
            tempTreeNode.lchild = NULL;
            biTreeNodePush(&binaryTree,tempTreeNode);
        }
        else
        {
            //若无限循环则说明  ch 可能为空了
            switch(Precede(chaGetTop(optr),ch))//判断优先级
            {
                case '<':                   //栈顶元素优先权低
                    chaPush(&optr,ch);
                    ch = getchar();
                    break;
                case '=':                   //脱括号并接收下一个字符
                    x = chaPop(&optr);
                    ch = getchar();
                    break;
                case '>':                   //退栈并将运算结果入栈
                    the = chaPop(&optr);
                    numb = numPop(&opnd);
                    numa = numPop(&opnd);
                    numPush(&opnd,Operate(numa,the,numb));
                    tempTreeNode.flag = isCha;
                    tempTreeNode.useUnion.cha = the;
                    treeNode_1 = biTreeNodePop(&binaryTree);
                    treeNode_2 = biTreeNodePop(&binaryTree);
                    biTreeNodePush(&binaryTree_0,*treeNode_1);//弹出的内容转存到另一个节点栈里，避免覆盖
                    biTreeNodePush(&binaryTree_0,*treeNode_2);//弹出的内容转存到另一个节点栈里，避免覆盖
                    tempTreeNode.lchild = biTreeNodePop(&binaryTree_0);
                    tempTreeNode.rchild = biTreeNodePop(&binaryTree_0);
                    recoverPtr(&binaryTree_0);//恢复副本栈里的指针指向
                    biTreeNodePush(&binaryTree,tempTreeNode);
                    break;
                default:
                    printf("其他字符！\n退出程序！\n");
                    exit(0);
                    break;
            }
        }
    }
    finTreeNode = biTreeNodePop(&binaryTree);
    printf("\n显示表达式树(广义表)为:\n");
    outPutBiTree(finTreeNode);
    printf("\n\n二叉树先序遍历:\n");
    preOrder(finTreeNode);//先序遍历
    printf("\n\n二叉树后序遍历:\n");
    aftOrder(finTreeNode);
    printf("\n计算结果:%d\n",numGetTop(opnd));
    return 0;
}
//int main()
//{
//	
////	printf("\n\n计算结果是：%d\n",doEvaluateExpression());
//	return 0;
//}
