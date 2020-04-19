#include<stdio.h>
#include<stdlib.h>
 
int Partition(int *arr,int low,int high)
{
    if(arr == NULL || low < 0 || low > high)
    {
        return -1;
    }
    int point = arr[low];
    while(low < high)
    {
  		while((low<high) && arr[high]>=point)
   		{
   			high--;
   		}
  		arr[low] = arr[high];
  		while((low<high) && arr[low]<=point)
		{
			low++;
		}
  		arr[high] = arr[low];
    	
	}
	arr[low] = point; 
    return low;
}
 
void Quick(int *arr,int start,int end)
{
    int par = Partition(arr,start,end);
    if(start < par-1)
    {
 		Quick(arr,start,par-1);
    }
    if(par < end-1)
    {
 		Quick(arr,par+1,end);
    }
 
}
 
void QuickSort(int *arr,int len)//调用快排函数 
{
    Quick(arr,0,len-1);
 
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
			printf("输入错误，请从错误元素的位置开始输入\n");
			while(getchar()!='\n');	
		}
	}
	while(k);
	return a; 
}
int main() 
{
	int arr[100];
    int n,i,*a,x;
    printf("请输入元素个数(不能超过100个)：\n");
	n=check();
	printf("请输入%d个整型元素:\n",n);
	for(i=0;i<n;i++){
//		scanf("%d",&arr[i]);
		arr[i]=check();
	} 
	a=arr;
	printf("使用快速排序\n");
	QuickSort(arr,n);
	for(i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	printf("\n输出第几小的数\n");
	x=check();
	printf("第%d小的数为\n%d",x,arr[x-1]);
    return 0; 
} 
 
