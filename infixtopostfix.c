#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	int top;
	unsigned capacity;
	char *ar;
};

struct stack* createStack(unsigned size)
{
	struct stack *st=(struct stack*)malloc(sizeof(struct stack));
	if(!st)
		return NULL;
	st->top=-1;
	st->capacity=size;
	st->ar=(char*)malloc(st->capacity *(sizeof(char)));
	return st;
}

void push(struct stack *st,char data)
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
	(st->top)--;
}

char peek(struct stack *st)
{
	return st->ar[st->top];
}

int isEmpty(struct stack *st)
{
	if(st->top==-1)
		return 1;
	return 0;
}

int prec(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 

void infixToPostfix(char exp[])
{
	struct stack* st=createStack(100);
	if(!st)
	{
		printf("Memory Problem\n");
		return;
	}
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]>='a'&&exp[i]<'z' || exp[i]>='A'&&exp[i]<'Z')
			printf("%c",exp[i]);	
		else if(exp[i]=='(')
			push(st,exp[i]);
		else if(exp[i]==')')
		{
			while( !isEmpty(st) && peek(st)!='(')
			{
				printf("%c",peek(st));
				pop(st);
			}
			if(isEmpty(st))
			{
				printf("Invalid expression\n");
				return;
			}
			else
				pop(st);
		}
		else{
			if(prec(exp[i])>prec(peek(st)))
			{
				push(st,exp[i]);
			}
			else
			{
				while(!isEmpty(st) && prec(peek(st))>=prec(exp[i]))
				{
					printf("%c",peek(st));
					pop(st);
				}
				push(st,exp[i]);
			}
		}
	}
	while(!isEmpty(st))
	{
		printf("%c",peek(st));
		pop(st);
	}
}

int main(){
	char exp[]="a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}