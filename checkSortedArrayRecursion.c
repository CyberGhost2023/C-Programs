#include <stdio.h>

int check(int ar[],int n)
{
	if(n==0)
		return 1;
	else
	{
		if(ar[n]>=ar[n-1])
			return check(ar,n-1);
		return 0;
	}
}


int main(){
	int ar[5]={1,2,6,4,5};
	if(check(ar,4)==1)
		printf("sorted");
	else
		printf("unsorted");
	return 0;
}