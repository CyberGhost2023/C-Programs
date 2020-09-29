#include<stdio.h>

struct fib{
	int size;
	int *p;
}obj[2000];

struct fib mult(struct fib x,struct fib y)
{
	int size1=x.size,size2=y.size,*p1=x.p,*p2=y.p,size3=size1+size2+1;
	 *p3=(int*)malloc((size3)*sizeof(int));
	memset(p3,0,size3*sizeof(int));
	int count=0,i=;
	for(
}

int main()
{
	for(int i=0;i<2000;i++)
	{
		obj[i].p=NULL;
	}
	obj[0].size=0;
	obj[1].size=1;
	
	
return 0;
}
