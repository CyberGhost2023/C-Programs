#include<stdio.h>

int ar[10000][1000],k=1;

void fibonacci(int n)
{
	if(n==0)
	printf("0");
	while(k<n)
	{
		int carry=0,j;
		for(j=999;j>=0;j--)
		{
			int var=ar[k][j]+ar[k-1][j]+carry;
			carry=var/10;		
			var = var%10;
			ar[k+1][j]=var;
		}
		k++;
	}
	int i=0;
	while(ar[n][i]==0 && i<1000)
		i++;
	for(;i<1000;i++)
	{
		printf("%d",ar[n][i]);
	}
	printf("\n");
}
 

int main()
{
	ar[1][999]=1;
	int t=1;
	while(t--){
	int n;
	scanf("%d",&n);
	fibonacci(n);
	}
	return 0;
}
