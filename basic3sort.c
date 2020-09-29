#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define upper_limit 30000
#define lower_limit 1

void insertion(int *ar3,int n)
{
	clock_t t1=clock();
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		temp=ar3[i+1];
		j=i;
		while(j>=0 && ar3[j]>temp )
		{
			ar3[j+1]=ar3[j];
			j--;
		}
		ar3[j+1]=temp;
	}
	clock_t t2=clock();
	printf("Time taken for insertion sorting array of size %d is %lf seconds\n",n,(double)(t2-t1)/CLOCKS_PER_SEC);
}

void bubble(int *ar2,int n)
{
	clock_t t1=clock();
	int temp,i,j,flag;
	for(i=0;i<n;i++)
	{
		flag=1;
		for(j=0;j<n-i-1;j++)
		{
			if(ar2[j]>ar2[j+1])
			{
				temp = ar2[j];
				ar2[j] = ar2[j+1];
				ar2[j+1]= temp;
				flag=0;
			}
		}
		if(flag)
			break;
	}	
	clock_t t2=clock();
	printf("Time taken for bubble sorting array of size %d is %lf seconds\n",n,(double)(t2-t1)/CLOCKS_PER_SEC);
}


void selection(int *ar1,int n)
{
	clock_t t1=clock();
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ar1[i]>ar1[j])
			{
				temp = ar1[i];
				ar1[i] = ar1[j];
				ar1[j]= temp;
			}
		}
	}	
	clock_t t2=clock();
	printf("Time taken for selection sorting array of size %d is %lf seconds\n",n,(double)(t2-t1)/CLOCKS_PER_SEC);
}

int main(){
	srand(time(0));
	int n=20000,i,j;
	printf("n is %d\n",n);
	int *ar1=(int*)malloc(n*sizeof(int));
	int *ar2=(int*)malloc(n*sizeof(int));
	int *ar3=(int*)malloc(n*sizeof(int));
	printf("For sorted array:\n");
	for(j=1;j<=n;j++)
	{
		ar1[j]=j;
		ar2[j]=j;
		ar3[j]=j;
	}
	selection(ar1,n);
	bubble(ar2,n);
	insertion(ar3,n);
	printf("For reverse sorted array:\n");
	for(i=n,j=0;i>0;i--,j++)
	{
		ar1[j]=i;
		ar2[j]=i;
		ar3[j]=i;
	}
	selection(ar1,n);
	bubble(ar2,n);
	insertion(ar3,n);
	printf("For random array:\n");
	for(j=0;j<n;j++)
	{
		ar1[j]=(rand()%(upper_limit-lower_limit+1))+lower_limit;//alloting random values from 1 to 30000
		ar2[j]=ar1[j];
		ar3[j]=ar1[j];
	}
	selection(ar1,n);
	bubble(ar2,n);
	insertion(ar3,n);
	return 0;
}
