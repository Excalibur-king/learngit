# QG训练营xx组第一周周记：
2020年4月日

## 生活随记

想起最近一次出门是在上周六晚上，和朋友出去打篮球，都是高中的老朋友了，打球方式还是特别的熟悉，任你在外头球场怎么carry,在熟悉你打球方式的人面前还是得乖乖挨帽。

摄影协会那边给我们这些毫无摄影技术的秘书部小干拍摄图片的任务，刚好是让我们拍春景，我可以给我家那几盆花花草草摆拍了。

这几天真的是从早上坐到晚上，功课有点忙不过来，时间都花在了训练营上了，有点失去平衡。



## 一周总结

从周一到周四学的基本都是链表，链表相对于数组的好处，链表的基本操作，快慢指针这些；

其中对我来说链表的基本操作和快慢指针都是刚接触的，所以花的时间相对会多一些。

链表的基本操作呢，就从链表的初始化开始说起吧。

###### 链表的初始化

```c
LinkList InitList()//初始化操作
{
	LNode *node;//定义LNode型的变量node，即头指针 
	node=(LNode*)malloc(sizeof(LNode));//开辟动态储存区，把起始地址赋给node ，malloc(X)的作用是开辟一个长度为x的内存区。malloc带回的是不指向任何类型数据的指针，（LNode*）则将malloc返回的指针转换为LNode型数据的指针，"*"不能省，否则转化为LNode的类型。
	if(!node)
	{
		return ERROR;
	}
	node->next=NULL;// 头指针指向下一个结点 
	return node;
}
```

###### 获取链表中某一个位置的元素

```c
int GetElem(LinkList L,int i)//将线性表 L中第i个位置元素返回给e。
{
	int j,e;
	LinkList p=NULL;
	if(i<1||i>ListLength(L))//判断输入的位置是否正确
	{
		printf("输入的位置不合法！\n");
		return 0;
	}
	p=L->next//头指针指向首结点
	j=1;
	while(j<i)//当循环到指定位置时给出该位置的地址
	{
		p=p->next;//指向下一个结点
		j++;
	}
	e=p->data;//将该位置的数据赋给e
	printf("第%d位的数据元素为%d\n",i,e);
	
}
```

###### 链表添加元素操作

```c
LinkList ListInsert(LinkList L,int i,int e)//在线性表L中第i个位置插入新的元素e 
{
	int j=0;
	LinkList s=NULL,p=NULL;
	p=L;//将头指针的地址赋给p
	while(p&&j<i-1)//判断P是否为空,寻找第i-1个结点。
	{
		p=p->next;//p指向下一个结点
		j++;
	}
	if(!p||j>i-1)//判断输入位置是否合法
	{
		printf("输入的位置不合法！\n");
		return L;
	}
	s=(LinkList)malloc(sizeof(LNode));//开辟新的结点，并把起始地址赋给s
	s->data=e;//把e的值赋值给s
	s->next=p->next;//s结点指向原本p结点的下一个结点；
	p->next=s;//p结点的下一结点是s
	return L;
}
```



###### 计算链表的长度

```c
int ListLength(LinkList L)//计算链表有多少个元素 
{
	LinkList p=NULL;
	int count=0;
	p=L;
	while(p->next)
	{
		count++;
		p=p->next; 
	}
	return count;
}
```

###### 创建链表

```c
LinkList CreateList_L(LinkList L,int n)//创建一个链表 
{
	int i,a;
	LinkList p,r;
	r=L;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));//开辟新结点p
		scanf("%d",&a);
		p->data=a;//a的值赋给p结点
		r->next=p;//尾结点r后插入新结点p
		r=p;//r移到尾结点
	}
	r->next=NULL;//r所在的结点指向空，表示该结点为尾结点
	return L;
}
```

###### 链表删除哪个位置元素的位置的操作

```c
LinkList ListDelete(LinkList L,int i)//删除线性表L中第i个位置元素，
{
	int j;
	LinkList q=NULL,p=NULL;
	p=L;
	j=0;
	while(p->next&&j<i-1)//寻找第i-1个结点
	{
		p=p->next;//p指向下一结点
		j++;
	}
	if(!(p->next)||j>i-1)//判断输入位置是否合法
	{
		printf("输入的位置不合法！！\n");
		return L;
	}
	q=p->next;//找到需要删除的结点
	p->next=q->next; //将q的下一结点的地址给p
	free(q);//释放q点
	return L;
}
```

###### 链表返回某个元素操作

```c
int GetElem(LinkList L,int i)//将线性表 L中第i个位置元素返回给e。
{
	int j,e;
	LinkList p=NULL;
	if(i<1||i>ListLength(L))
	{
		printf("输入的位置不合法！\n");
		return 0;
	}
	p=L->next;//p指向首元素
	j=1;
	while(j<i)//遍历寻找目标结点
	{
		p=p->next;
		j++;
	}
	e=p->data;//将目标结点的数据给e
	printf("第%d位的数据元素为%d\n",i,e);
	
}
```

###### 链表的遍历

```c
void Linkprint (LinkLisk *head)
{
    LinkList *p = head;
    while( p!=NULL)
    {
    	printf("%d",p->data);
        p=p->next;
	}
}
```





## 存在问题

##### 在这次的大组作业要求，链表要能耐打，有良好的交互设计，而我做的是整型数据链表，为了防止用户输入非整型数据，我的程序需要解决判断用户输入的数据是否符合正确类型，不符合又该怎么办的问题。

###### 我的解决办法是：

写一个能够判断输入数据是否符合整型数据的函数，若符合，则继续输入，若不符合，则返回重新输入.

```c
int check()
{
	int k,a;
	do
	{
		if((scanf("%d",&a))==1)
		{
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

```



## 下周规划

与其叫做下周规划，不如叫做周末规划吧，因为今天是星期四。。。

今晚交了作业后，我要先把这几天落下的作业写一下，不然周末估计没有时间去写那么多的作业。

明天周五是空档期，我打算抓紧时间完成一部分作业，有时间再继续学js，明天晚上可以的话我觉得我

要继续打网页的demo，争取周六能够完成一个静态网页。小组作业我打算在周末完成，而且新的大组

作业 就留到周日吧，大组作业估计需要花较多时间去学习新的知识，估计会持续到下周。而前端的学习

时间已经不如以前充裕，所以现在应该加快自己的节奏，课内作业完成速度要快，大组作业也不能拖拉

，我得为我前端的学习以及其他工作室的考核做准备。

| 周四晚         | 完成课内作业，优先高数，其次电工       |
| -------------- | -------------------------------------- |
| 周五早         | 完成课内作业，优先大物                 |
| 周五下午及晚上 | 学习js，写网页（争取当晚写完静态页面） |
| 周六早         | 完成课内作业，离散等其他               |
| 周六下午       | 完成小组作业，学习js                   |
| 周六晚上       | 学习js,完善网页                        |
| 周日早上       | 构思新网页，找素材，学习js             |
| 周日下午       | 学习大组作业所需要的知识               |
| 周日晚上       | 开始动手写网页，学习js                 |

