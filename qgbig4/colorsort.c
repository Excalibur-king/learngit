#include<stdio.h>
void swap(int* nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}
void sortColors(int* nums, int numsSize) {
    int i = 0, j = 0, k = numsSize - 1;
    int t = 0;
    for(i = 0; i <= k; i++) {
        if(nums[i] == 0) {
            swap(nums, i, j);
            j++;
        }
        else if(nums[i] == 2) {
            swap(nums, i, k);
            k--;
            i--;
        }
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
			printf("输入错误，请从错误元素的位置开始输入\n");
			while(getchar()!='\n');	
		}
	}
	while(k);
	return a; 
}
int main(){
	int n,i,nums[10];
	printf("请输入要输入元素个数（十个以内）：\n");
	n=check();
	printf("请输入%d个整型元素（只能在0.1.2中选取想输入的元素）：\n",n);
	for(i=0;i<n;i++){
//		scanf("%d",(nums+i));
		*(nums+i)=check();
	}
	printf("排序后：\n");
	sortColors(nums,n);
	for(i=0;i<n;i++){
		printf(" %d",*(nums+i));
	}	
	return 0;
}
