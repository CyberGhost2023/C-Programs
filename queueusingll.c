#include<stdio.h>
#include<stdlib.h>


struct queue{
	int data;
	struct queue *next;
}*top=NULL,*bottom=NULL;


void insert(int data){
	struct queue *new=(struct queue *)malloc(sizeof(struct queue));
	new->data =data;
	new->next=NULL;
	if(top==NULL)
	{
		top=new;
		bottom=new;
	}
	else{
		bottom->next=new;
		bottom=new;
	}
}

void delete(){
	if(top==NULL)
	{
		printf("Empty\n");
		return;
	}
	struct queue *temp=top;
	if(top==bottom)
	{
		bottom=NULL;
	}
	top=top->next;
	free(temp);
}

void display(){
	if(top==NULL)
	{
		printf("Empty\n");
		return;
	}
	struct queue *itr=top;
	while(itr)
	{
		printf("%d\n",itr->data);
		itr=itr->next;
	}
	free(itr);
}

int count(){
	
	int count=0;
	struct queue *itr=top;
	while(itr)
	{
		itr=itr->next;
		count++;
	}
	free(itr);
	return count;
}

int main(){
	do{
		printf("\nchoose your option:\n1- insertion\n2-deletion\n3-display\n4-count\n5-exit\n");
		int ch,data;
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