#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int k=1;

//function to return nth fibonacci number 
void fibonacci(int n,int *ar)
{
	if(n==0)
	{
		printf("0");
		return;
	}
	while(k<n)
	{
		int carry=0,j;
		for(j=499;j>=0;j--)
		{
			int var=*(ar+(500*k)+j)+*(ar+((k-1)*500)+j)+carry;
			carry=var/10;		
			var = var%10;
			*(ar+((k+1)*500)+j)=var;
		}
		k++;
	}
	int i=0;
	while(!(*(ar+((n)*500)+i)) && i<500)
		i++;
	for(;i<500;i++)
	{
		printf("%d",*(ar+((n)*500)+i));
	}
	printf("\n");
}
 

int main()
{
	int *ar = (int *)malloc(5000*500*sizeof(int));//initialized array to store 5000 fibonacci number cosidering length of each fibonacci number to be 500
	memset(ar,0,5000*500*sizeof(int));
	*(ar+((1)*500)+499)=1;
	int test_case=1;
	while(test_case--){
	int n;
	scanf("%d",&n);
	fibonacci(n,ar);
	}
	return 0;
}
