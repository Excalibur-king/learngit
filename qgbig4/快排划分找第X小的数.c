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
 
void QuickSort(int *arr,int len)//���ÿ��ź��� 
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
//			printf("�������Ҫ�������\n"); 
			k=0;
		}
		else
		{
			k=1;
			printf("���������Ӵ���Ԫ�ص�λ�ÿ�ʼ����\n");
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
    printf("������Ԫ�ظ���(���ܳ���100��)��\n");
	n=check();
	printf("������%d������Ԫ��:\n",n);
	for(i=0;i<n;i++){
//		scanf("%d",&arr[i]);
		arr[i]=check();
	} 
	a=arr;
	printf("ʹ�ÿ�������\n");
	QuickSort(arr,n);
	for(i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	printf("\n����ڼ�С����\n");
	x=check();
	printf("��%dС����Ϊ\n%d",x,arr[x-1]);
    return 0; 
} 
 
