#include<stdio.h>
#include<stdlib.h>

struct stack{
	int top;
	unsigned capacity;
	int *ar;
};

struct stack* createStack(unsigned size)
{
	struct stack *st=(struct stack*)malloc(sizeof(struct stack));
	if(!st)
		return NULL;
	st->top=-1;
	st->capacity=size;
	st->ar=(int *)malloc(st->capacity *(sizeof(int)));
	return st;
}

void push(struct stack *st,int data)
{
	if(st->top==st->capacity-1)
	{
		printf("Stack Full\n");
		return;
	}
	(st->top)++;
	st->ar[st->top]=data;
}

void pop(struct stack *st)
{
	if(st->top==-1)
	{
		printf("stack already empty\n");
		return;
	}
	st->top--;
}

void peek(struct stack *st)
{
	if(st->top==-1)
	{
		printf("Stack empty\n");
		return;
	}	
	printf("%d\n",st->ar[st->top]);
}

void isEmpty(struct stack *st)
{
	if(st->top==-1)
		printf("YES\n");
	else
		printf("NO\n");
}
void isFull(struct stack *st)
{
	if(st->top==st->capacity-1)
		printf("YES\n");
	else
		printf("NO\n");
}

int main(){
	struct stack* st=createStack(100);
	if(!st)
		printf("Memory Problem\n");
	do{
		printf("\nchoose your option:\n1-Push\n2-Pop\n3-Peek\n4-isEmpty\n5-isFull\n6-exit\n");
		int ch,data;
		scanf("%d",&ch);
		if(ch==6)
			break;
		switch(ch)
		{
			case 1:	scanf("%d",&data);
					push(st,data);
					break;
			case 2: pop(st);
					break;
			case 3:peek(st);break;
			case 4:isEmpty(st);break;
			case 5:isFull(st);break;
		}
	}while(1);
	return 0;
}