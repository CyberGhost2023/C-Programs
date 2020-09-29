#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data ;
	struct stack *prev;
}*top=NULL;

void insert(int data){
	struct stack *new =(struct stack *) malloc(sizeof(struct stack));
	new->data=data;
	new->prev=top;
	top=new;
}

void delete()
{
	if(!top)
	{
		printf("Empty\n");
		return;
	}
	struct stack *temp=top;
	top=top->prev;
	free(temp);
}

void display(){
	if(!top)
	{
		printf("Empty\n");
		return;
	}
	struct stack *itr=top;
	while(itr!=NULL)
	{
		printf("%d\n",itr->data);
		itr=itr->prev;
	}
	free(itr);
}
int count(){
	int count=0;
	struct stack *itr=top;
	while(itr!=NULL)
	{
		itr=itr->prev;
		count++;
	}
	free(itr);
	return count;
}


int main(){
	do{
		printf("\nchoose your option:\n1- insertion\n2-deletion\n3-display\n4-count\n5-exit\n");
		int ch,data,pos;
		scanf("%d",&ch);
		if(ch==5)
			break;
		switch(ch)
		{
			case 1:	scanf("%d",&data);
					insert(data);
					break;
			case 2: delete();
					break;
			case 3:display();break;
			case 4:printf("%d\n",count());break;
		}
	}while(1);
	return 0;
}