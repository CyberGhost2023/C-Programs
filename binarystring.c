#include<stdio.h>
int ar[3];

void binary(int n)
{
	if(n<1)
	{
		for(int i=-1;i++<2;)
			printf("%d",ar[i]);
		printf("\n");
	}
	else
	{
		ar[n-1]=0;
		binary(n-1);
		ar[n-1]=1;
		binary(n-1);
	}
}

int main(){
	binary(3);
	return 0;
}
