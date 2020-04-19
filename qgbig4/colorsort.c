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
int main(){
	int n,i,nums[10];
	printf("������Ҫ����Ԫ�ظ�����ʮ�����ڣ���\n");
	n=check();
	printf("������%d������Ԫ�أ�ֻ����0.1.2��ѡȡ�������Ԫ�أ���\n",n);
	for(i=0;i<n;i++){
//		scanf("%d",(nums+i));
		*(nums+i)=check();
	}
	printf("�����\n");
	sortColors(nums,n);
	for(i=0;i<n;i++){
		printf(" %d",*(nums+i));
	}	
	return 0;
}
