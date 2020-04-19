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
//����
void insertSort(int a[],int n){
	int i,j;
	int temp;
	for(i=1;i<n;i++){
		temp=a[i];//���������� 
		j=i-1;
		while(j>=0&&a[j]>temp){//�Ƚ�ֱ�����ֱ�temp���ֵ 
			a[j+1]=a[j];//ǰֵ���� 
			j--;
		} 
		a[j+1]=temp;
	}
	
}
//�鲢 
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
//���� 
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
//��������
void CountSort(int *a, int len)
{
	assert(a);
	//ͨ��max��min�������ʱ��������Ҫ���ٵĿռ��С
	int max = a[0], min = a[0];
	for (int i = 0; i < len; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//ʹ��calloc�����鶼��ʼ��Ϊ0
	int range = max - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//ʹ����ʱ�����¼ԭʼ������ÿ�����ĸ���
	for (int i = 0; i < len; i++){
		//ע�⣺�����ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�Ų������Խ������
		b[a[i] - min] += 1;
	}
	int j = 0;
	//����ͳ�ƽ�������¶�Ԫ�ؽ��л���
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//ע�⣺Ҫ��i��ֵ����min���ܻ�ԭ��ԭʼ����
			a[j++] = i + min;
		}
	}
	//�ͷ���ʱ����
	free(b);
	b = NULL;
}
//���� 
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
//�Ƿ����� 
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
void menu(){
	printf("*****************Ŀ¼******************\n");
	printf("1.���뷨�������\n");
	printf("2.�鲢���������\n");
	printf("3.�������������\n");
	printf("4.�������������\n");
	printf("5.���Ų���\n");
	printf("6.��������\n"); 
	printf("***************************************\n"); 
}
int main(){
	FILE *pf=NULL;
	int a[N],b[M],c[Q],d[100];
	int i,j,t;
	double start,end; 
	pf=fopen("test.txt", "w" );//���������ݣ�д���� 
	if(!pf)
	{
	printf("���ļ�ʧ�ܣ������˳���");
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
		printf("\n������ָ�\n");
		t=check();
		switch(t){
			case 1://����������� 
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
   					printf("���뷨����10000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n�Ƿ�������(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				insertSort(b,M);
    				}
   					end=clock();
    				printf("���뷨����50000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				insertSort(c,Q);
   		 			}
				   	end=clock();
				    printf("���뷨����200000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k��100����"); 
				    printf("\n�����ĵȴ�\n");
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
					printf("���뷨����100K��100���飬Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;
			case 2://�鲢�������� 
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
   					printf("�鲢������10000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n�Ƿ�������(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				conflationSort(b,0,M-1);
    				}
   					end=clock();
    				printf("�鲢������50000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				conflationSort(c,0,Q-1);
   		 		}
				   	end=clock();
				    printf("�鲢������200000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k��100����"); 
				    printf("\n�����ĵȴ�\n");
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
					printf("�鲢������100K��100���飬Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;
			case 3://�����������
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
   					printf("����������10000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n�Ƿ�������(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				RadixSort(b,M);
    				}
   					end=clock();
    				printf("����������50000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				RadixSort(c,Q);
   		 			}
				   	end=clock();
				    printf("����������200000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k��100����"); 
				    printf("\n�����ĵȴ�\n");
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
					printf("����������100K��100���飬Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;
			case 4://�����������
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
   					printf("����������10000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n�Ƿ�������(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				CountSort(b,M);
    				}
   					end=clock();
    				printf("����������50000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				CountSort(c,Q);
   		 			}
				   	end=clock();
				    printf("����������200000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k��100����"); 
				    printf("\n�����ĵȴ�\n");
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
					printf("����������100K��100���飬Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;		
			case 5://�����������
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
   					printf("���ŷ�����10000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("\n�Ƿ�������(TRUE or FALSE)%s",isSorted(a,N) == 1 ? "TRUE":"FALSE");
    				printf("\n***************2w***************\n");
    				for(i=0;i<M;i++){
						fscanf(pf,"%d",&b[i]);
					} 
					start=clock();
    				{
        				 QuickSort(b,M);
    				}
   					end=clock();
    				printf("���ŷ�����50000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
    				printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(b,M) == 1 ? "TRUE":"FALSE");
    				printf("\n***************3w***************\n");
    				for(i=0;i<Q;i++){
						fscanf(pf,"%d",&c[i]);
					}
					start=clock();
    				{
        				 QuickSort(c,Q);
   		 			}
				   	end=clock();
				    printf("���ŷ�����200000������Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
				    printf("�Ƿ�������(TRUE or FALSE)%s",isSorted(c,Q) == 1 ? "TRUE":"FALSE");
				    printf("\n100k��100����"); 
				    printf("\n�����ĵȴ�\n");
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
					printf("���ŷ�����100K��100���飬Running time is: %lfms\n",end-start/CLOCKS_PER_SEC*1000);
					fclose(pf);
					break;			
			case 6://����
					printf("\n�������\n");
					break;
			default :
					printf("���������������\n");	
		}
	}while(t!=0);
	return 0;
} 
