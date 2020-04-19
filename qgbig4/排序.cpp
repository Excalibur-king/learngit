#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#define N 10000
#define M 50000
#define Q 200000
#define FALSE 0
#define TRUE 1
#define MAX 100000000
#define RAND_MAX 0x7fff 
//插入
void insertSort(int a[],int n){
	int i,j;
	int temp;
	for(i=1;i<n;i++){
		temp=a[i];//创建缓冲区 
		j=i-1;
		while(j>=0&&a[j]>temp){//比较直到出现比temp大的值 
			a[j+1]=a[j];//前值后移 
			j--;
		} 
		a[j+1]=temp;
	}
	
}
//归并 
void combineArr(int arrL[],int ln,int arrR[],int rn){
	int temp[Q]; 
    int i = 0;
    int j = 0;
    int k=0;
    while(i<ln&&j<rn){

        if(arrL[i]<=arrR[j]){
            temp[k++] = arrL[i++];
        }else{
            temp[k++] = arrR[j++];
        }
    }
    while(i<ln){
        temp[k++] = arrL[i++];
    }

    while(j<rn){
        temp[k++] = arrR[j++];
    }

    for(int i = 0;i<k;++i){
        arrL[i] = temp[i];
    }
}
void conflationSort(int arr[],int l,int r){

    if(r>l){
        int mid = (l+r)/2;
        conflationSort(arr,l,mid);
        conflationSort(arr,mid+1,r);
        combineArr(&arr[l],mid-l+1,&arr[mid+1],r-mid);
    }
} 
//基数 
void RadixCountSort(int *index,int *a,int len)  
{  
    int i;  
    int *count=(int *)malloc(sizeof(int)*10);  

    for(i=0;i<10;i++)  
    {  
        count[i]=0;  
    }  

    for(i=0;i<len;i++)  
    {  
        count[index[i]] ++;  
    }  

    for(i=1;i<10;i++)  
    {  
        count[i]=count[i] + count[i - 1];  
    }  

    int *sort=(int *)malloc(sizeof(int)*len);  

    for(i=len-1;i>=0;i--)  
    {  
        count[index[i]] --;  
        sort[count[index[i]]] = a[i];  
    }  

    for(i=0;i<len;i++)  
    {  
        a[i]=sort[i];  
    }  

    free(sort);  
    free(count);  
}  

void RadixSort(int *a,int len)  
{  
    int i , x=1;  
    int tmp=1;  
    int *radix=(int *)malloc(sizeof(int)*len);  

    while(x)  
    {  
        tmp=tmp * 10;  
        x=0;  

        for(i=0;i<len;i++)  
        {  
            radix[i]=a[i] % tmp;  
            radix[i]=radix[i] / (tmp / 10);  
            if(a[i] / tmp > 0)  
        	{  
                x = 1;  
            }  
        }  

        RadixCountSort(radix,a,len);  
    }  
    free(radix);  
} 
//计数排序
void CountSort(int *a, int len)
{
	assert(a);
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max = a[0], min = a[0];
	for (int i = 0; i < len; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//使用calloc将数组都初始化为0
	int range = max - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//使用临时数组记录原始数组中每个数的个数
	for (int i = 0; i < len; i++){
		//注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min] += 1;
	}
	int j = 0;
	//根据统计结果，重新对元素进行回收
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//注意：要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
		}
	}
	//释放临时数组
	free(b);
	b = NULL;
}
//快排 
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
//是否排序 
int isSorted(int a[],int n){
    int flag = 1;
	int i; 
    for(i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            flag = 0;
            break;
        }
    }
    return flag;
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
void menu(){
	printf("*****************目录******************\n");
	printf("1.插入法排序测试\n");
	printf("2.归并法排序测试\n");
	printf("3.基数法排序测试\n");
	printf("4.计数法排序测试\n");
	printf("5.快排测试\n");
	printf("6.结束程序\n"); 
	printf("***************************************\n"); 
}
int main(){
	FILE *pf=NULL;
	int a[N],b[M],c[Q],d[100];
	int i,j,t;
	double start,end; 
	pf=fopen("test.txt", "w" );//，创建数据，写数据 
	if(!pf)
	{
	printf("打开文件失败，程序退出！");
	exit(1);
	}
	srand(time(NULL));
	for(i =0;i < N;i++ ){
        a[i] =  rand();
        fprintf(pf,"%d\n",a[i]);
    }	
	for(i =0;i < M;i++ ){
        b[i] =  rand();
        fprintf(pf,"%d\n",b[i]);
    } 
	for(i =0;i < Q;i++ ){
        c[i] =  rand();
        fprintf(pf,"%d\n",c[i]);
    } 
	for(i =0;i < 100;i++ ){
	    d[i] = rand();
	    fprintf(pf,"%d\n",d[i]);
	}
	fclose(pf);
	menu();
	do{
		printf("\n请输入指令：\n");
		t=check();
		switch(t){
			case 1://插入排序测试 
					pf=fopen("test.txt","r");
					printf("\n***************1w***************\n");
					for(i=0;i<N;i++){
						fscanf(pf,"%d",&a[i]);
					} 
					start=clock();
   	 				{
        				insertSort(a,N);
    				}
   					end=clock();
   					printf("插入法排序10000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n是否已排序：(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				insertSort(b,M);
    				}
   					end=clock();
    				printf("插入法排序50000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("是否已排序：(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				insertSort(c,Q);
   		 			}
				   	end=clock();
				    printf("插入法排序200000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("是否已排序：(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k个100数组"); 
				    printf("\n请耐心等待\n");
				    start=clock(); 
				    {
				    	srand(time(NULL));
					 	for(j=0;j<100000;j++){
					    	for(i =0;i < 100;i++ ){
					        	d[i] = rand();
					    	}
					    	insertSort(d,100);
						}
					}
					end=clock();
					printf("插入法排序100K个100数组，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;
			case 2://归并函数测试 
					pf=fopen("test.txt","r");
					printf("\n***************1w***************\n");
					for(i=0;i<N;i++){
						fscanf(pf,"%d",&a[i]);
					} 
					start=clock();
   	 				{
        				conflationSort(a,0,N-1);
    				}
   					end=clock();
   					printf("归并法排序10000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n是否已排序：(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				conflationSort(b,0,M-1);
    				}
   					end=clock();
    				printf("归并法排序50000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("是否已排序：(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				conflationSort(c,0,Q-1);
   		 		}
				   	end=clock();
				    printf("归并法排序200000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("是否已排序：(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k个100数组"); 
				    printf("\n请耐心等待\n");
				    start=clock(); 
				    {
				    	srand(time(NULL));
					 	for(j=0;j<100000;j++){
					    	for(i =0;i < 100;i++ ){
					        	d[i] = rand();
					    	}
					    	conflationSort(d,0,99);
						}
					}
					end=clock();
					printf("归并法排序100K个100数组，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;
			case 3://基数排序测试
					 pf=fopen("test.txt","r");
					printf("\n***************1w***************\n");
					for(i=0;i<N;i++){
						fscanf(pf,"%d",&a[i]);
					} 
					start=clock();
   	 				{
        				RadixSort(a,N);
    				}
   					end=clock();
   					printf("基数法排序10000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n是否已排序：(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				RadixSort(b,M);
    				}
   					end=clock();
    				printf("基数法排序50000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("是否已排序：(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				RadixSort(c,Q);
   		 			}
				   	end=clock();
				    printf("基数法排序200000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("是否已排序：(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k个100数组"); 
				    printf("\n请耐心等待\n");
				    start=clock(); 
				    {
				    	srand(time(NULL));
					 	for(j=0;j<100000;j++){
					    	for(i =0;i < 100;i++ ){
					        	d[i] = rand();
					    	}
					    	RadixSort(d,100);
						}
					}
					end=clock();
					printf("基数法排序100K个100数组，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;
			case 4://计数排序测试
					pf=fopen("test.txt","r");
					printf("\n***************1w***************\n");
					for(i=0;i<N;i++){
						fscanf(pf,"%d",&a[i]);
					} 
					start=clock();
   	 				{
        				CountSort(a,N);
    				}
   					end=clock();
   					printf("计数法排序10000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n是否已排序：(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				CountSort(b,M);
    				}
   					end=clock();
    				printf("计数法排序50000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("是否已排序：(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				CountSort(c,Q);
   		 			}
				   	end=clock();
				    printf("计数法排序200000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("是否已排序：(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k个100数组"); 
				    printf("\n请耐心等待\n");
				    start=clock(); 
				    {
				    	srand(time(NULL));
					 	for(j=0;j<100000;j++){
					    	for(i =0;i < 100;i++ ){
					        	d[i] = rand();
					    	}
					    	CountSort(d,100);
						}
					}
					end=clock();
					printf("计数法排序100K个100数组，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;		
			case 5://快排排序测试
					pf=fopen("test.txt","r");
					printf("\n***************1w***************\n");
					for(i=0;i<N;i++){
						fscanf(pf,"%d",&a[i]);
					} 
					start=clock();
   	 				{
        				 QuickSort(a,N);
    				}
   					end=clock();
   					printf("快排法排序10000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n是否已排序：(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				 QuickSort(b,M);
    				}
   					end=clock();
    				printf("快排法排序50000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("是否已排序：(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				 QuickSort(c,Q);
   		 			}
				   	end=clock();
				    printf("快排法排序200000个数，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("是否已排序：(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k个100数组"); 
				    printf("\n请耐心等待\n");
				    start=clock(); 
				    {
				    	srand(time(NULL));
					 	for(j=0;j<100000;j++){
					    	for(i =0;i < 100;i++ ){
					        	d[i] = rand();
					    	}
					    	 QuickSort(d,100);
						}
					}
					end=clock();
					printf("快排法排序100K个100数组，Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;			
			case 6://结束
					printf("\n程序结束\n");
					break;
			default :
					printf("输入错误，重新输入\n");	
		}
	}while(t!=0);
	return 0;
} 
