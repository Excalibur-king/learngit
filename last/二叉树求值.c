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
 
//�������ڵ�Ԫ��
struct nodeNum{
    int number;
};
//�������ڵ�Ԫ��
struct nodeCha{
    char ch;
};
//������
typedef union demo{
    int number;
    char cha;
}Demo;
//�������ڵ�
struct biTreeNode{
    int flag;
    Demo useUnion;
    struct biTreeNode *lchild;
    struct biTreeNode *rchild;
};
//�������ڵ�ջ     �����ʼ�������������ڵ�ջ��
struct biTreeStack{
    struct biTreeNode *base;
    struct biTreeNode *top;
    int stackSize;
};
//������ջ
struct numStack{
    struct nodeNum *base;
    struct nodeNum *top;
    int stackSize;
};
//������ջ
struct chaStack{
    struct nodeCha *base;
    struct nodeCha *top;
    int stackSize;
};
//��ʼ��������ջ
void biTreeInitStack(struct biTreeStack *stack)
{
    stack->base = (struct biTreeNode *)malloc(StackInitSize * lenBiTree);
    if(!stack->base)
    {
        printf("��ʼ��ʧ�ܣ��˳�����\n");
        exit(0);
    }
    stack->top = stack->base;
    stack->stackSize = StackInitSize;
}
//��ʼ��������ջ
void numInitStack(struct numStack *stack1)
{
    stack1->base = (struct nodeNum *)malloc(StackInitSize * lenNum);
    if(!stack1->base)
    {
        printf("��ʼ��ʧ�ܣ��˳�����\n");
        exit(0);
    }
    stack1->top = stack1->base;
    stack1->stackSize = StackInitSize;
}
//��ʼ��������ջ
void chaInitStack(struct chaStack *stack2)
{
    stack2->base = (struct nodeCha *)malloc(StackInitSize * lenCha);
    if(!stack2->base)
    {
        printf("��ʼ��ʧ�ܣ��˳�����\n");
        exit(0);
    }
    stack2->top = stack2->base;
    stack2->stackSize = StackInitSize;
}
//ѹ�������
void chaPush(struct chaStack *stack3,char ch)
{
    if(stack3->top - stack3->base >= stack3->stackSize)
    {
        printf("ջ����\n�˳�����\n");
        exit(0);
    }
    stack3->top->ch = ch;
    stack3->top++;
}
//ѹ�������
void numPush(struct numStack *stack4,int number)
{
    if(stack4->top - stack4->base >= stack4->stackSize)
    {
        printf("ջ����\n�˳�����\n");
        exit(0);
    }
    stack4->top->number = number;
    stack4->top++;
}
//ѹ��ջ�ڵ�
void biTreeNodePush(struct biTreeStack *curBiTree,struct biTreeNode curTreeNode)
{
    if(curBiTree->top - curBiTree->base >= curBiTree->stackSize)
    {
        printf("ջ����\n�˳�����\n");
        exit(0);
    }
    *curBiTree->top = curTreeNode;
    curBiTree->top++;
}
//����ջ�ڵ�
struct biTreeNode *biTreeNodePop(struct biTreeStack *curBiTree)
{
    if(curBiTree->top != curBiTree->base)
    {
        curBiTree->top--;
        return curBiTree->top;
    }
    else
    {
         printf("ջ�ѿգ�\n�˳�����\n");
         exit(0);
    }
}
void recoverPtr(struct biTreeStack *curBiTree)
{
    curBiTree->top++;
    curBiTree->top++;
}
//����������
char chaPop(struct chaStack *stack5)
{
    if(stack5->top != stack5->base)
    {
        stack5->top--;
        return stack5->top->ch;
    }
    else
    {
         printf("ջ�ѿգ�\n�˳�����\n");
         exit(0);
    }
}
//����������
int numPop(struct numStack *stack6)
{
    if(stack6->top != stack6->base)
    {
        stack6->top--;
        return stack6->top->number;
    }
    else
    {
        printf("ջ�ѿգ�\n�˳�����\n");
        exit(0);
    }
}
//�����ջȡ��
char chaGetTop(struct chaStack stack7)
{
    if(stack7.top >= stack7.base)
    {
        stack7.top--;
        return stack7.top->ch;
    }
    else
    {
        printf("ջ�ѿգ�\n�˳�����\n");
        exit(0);
    }
}
//������ջȡ��
int numGetTop(struct numStack stack8)
{
    if(stack8.top >= stack8.base)
    {
        stack8.top--;
        return stack8.top->number;
    }
    else
    {
        printf("ջ�ѿգ�\n�˳�����\n");
        exit(0);
    }
}
//�жϲ��������������ȹ�ϵ
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
                printf("��������\n�˳�����\n");
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
                printf("��������\n�˳�����\n");
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
                printf("��������\n�˳�����\n");
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
                printf("�Ƿ����룡\n�˳�����\n");
                exit(0);
            }
    }
    return ch;
}
//�������������м���
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
//�������������
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
//�������������
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
//��ʾ������
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
}//���ٶ�����
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
void menu()
{
	printf("*********************\n");
	printf("1.���ٶ�����:\n");
	printf("2.����������:\n");
	printf("0.�˳�����:\n");
	printf("*********************\n"); 
 } 
//���ʽ��ֵ������������
//int doEvaluateExpression()
int main() 
{
    char ch,x,the;
    int numa,numb;
    int count;
    int i,temp;
    long number,num[max];
    struct numStack opnd;//���������ջ 
    struct chaStack optr;//���������ջ 
    struct biTreeNode tempTreeNode,*finTreeNode,*treeNode_1,*treeNode_2;//�������ڵ� 
    struct biTreeStack binaryTree,binaryTree_0;//������������ջ 
    numInitStack(&opnd);//��ʼ��������ջ
    chaInitStack(&optr);//��ʼ��������ջ
    biTreeInitStack(&binaryTree);//��ʼ���������ڵ�ջ
    biTreeInitStack(&binaryTree_0);//��ʼ���������ڵ�ջ����
    chaPush(&optr,'$');//ѹ������� 
    printf("��������ʽ(��$�Ž���):\n");
    ch = getchar();
    while(!(ch == '$' && chaGetTop(optr) == '$'))
    {
        if(isdigit(ch))    //��������־ͽ�������ջ
        {
            count = 0;
            number = 0;
            while(isdigit(ch))//���getchar()�õ���������,��������
            {
                count++;
                num[count-1] = ch-48;
                ch = getchar();
            }
            temp = count;
            for(i = 0; i < count; i++)//�ж������м�λ
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
            //������ѭ����˵��  ch ����Ϊ����
            switch(Precede(chaGetTop(optr),ch))//�ж����ȼ�
            {
                case '<':                   //ջ��Ԫ������Ȩ��
                    chaPush(&optr,ch);
                    ch = getchar();
                    break;
                case '=':                   //�����Ų�������һ���ַ�
                    x = chaPop(&optr);
                    ch = getchar();
                    break;
                case '>':                   //��ջ������������ջ
                    the = chaPop(&optr);
                    numb = numPop(&opnd);
                    numa = numPop(&opnd);
                    numPush(&opnd,Operate(numa,the,numb));
                    tempTreeNode.flag = isCha;
                    tempTreeNode.useUnion.cha = the;
                    treeNode_1 = biTreeNodePop(&binaryTree);
                    treeNode_2 = biTreeNodePop(&binaryTree);
                    biTreeNodePush(&binaryTree_0,*treeNode_1);//����������ת�浽��һ���ڵ�ջ����⸲��
                    biTreeNodePush(&binaryTree_0,*treeNode_2);//����������ת�浽��һ���ڵ�ջ����⸲��
                    tempTreeNode.lchild = biTreeNodePop(&binaryTree_0);
                    tempTreeNode.rchild = biTreeNodePop(&binaryTree_0);
                    recoverPtr(&binaryTree_0);//�ָ�����ջ���ָ��ָ��
                    biTreeNodePush(&binaryTree,tempTreeNode);
                    break;
                default:
                    printf("�����ַ���\n�˳�����\n");
                    exit(0);
                    break;
            }
        }
    }
    finTreeNode = biTreeNodePop(&binaryTree);
    printf("\n��ʾ���ʽ��(�����)Ϊ:\n");
    outPutBiTree(finTreeNode);
    printf("\n\n�������������:\n");
    preOrder(finTreeNode);//�������
    printf("\n\n�������������:\n");
    aftOrder(finTreeNode);
    printf("\n������:%d\n",numGetTop(opnd));
    return 0;
}
//int main()
//{
//	
////	printf("\n\n�������ǣ�%d\n",doEvaluateExpression());
//	return 0;
//}
