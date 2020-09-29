#include<stdio.h>
#include<stdlib.h>

struct linkedList{
	int data;
	struct linkedList* next,*prev;
};
struct linkedList* head=NULL;

void insertNode(int value,int pos){
	struct linkedList* temp=(struct linkedList*)malloc(sizeof(struct linkedList));
	temp->data = value;
	temp->next = temp->prev=NULL;
	if(pos==1)
	{
		temp->next=head;
		if(head)
			head->prev=temp;
		head=temp;
	}
	else 
	{
		int count=1;
		struct linkedList *itr1=head,*itr2 = head;
		while(count!=pos && itr2!= NULL)
		{
			itr1=itr2;
			itr2 = itr2->next;
			count++;
		}
		if(count==pos)
		{
			temp->next=itr1->next;
			temp->prev=itr1;
			itr1->next=temp;
		}
		else
			printf("position not found\n");
	}
}

void deleteNode(int pos)
{
	if(head==NULL)
		printf("List is Empty\n");
	else if(pos==1)
	{
		struct linkedList *temp = head;
		head=head->next;
		if(head)
			head->prev=NULL;
		free(temp);
	}
	else
	{
		int count = 1;
		struct linkedList *itr1= head,*itr2=head;
		while(pos!=count && itr2->next!=NULL)
		{
			itr1=itr2;
			itr2=itr2->next;
			count++;
		}
		if(pos==count)
		{
			itr1->next=itr2->next;
			if(itr2->next)
				(itr2->next)->prev=itr1;
			free(itr2);
		}
		else
			printf("position not found\n");
		
	}
}

void displayList()
{
	if(head==NULL)
		printf("List is Empty\n");
	else{
		struct linkedList *itr=head;		
		while(itr!=NULL)
		{
			printf("%d\t",itr->data);
			itr=itr->next;
		}
	}
}

int countList()
{
	int count=0;
	struct linkedList *itr=head;		
	while(itr!=NULL)
	{
		itr=itr->next;
		count++;
	}
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
			case 1:	scanf("%d %d",&data,&pos);
					insertNode(data,pos);
					break;
			case 2: scanf("%d",&pos);
					deleteNode(pos);
					break;
			case 3:displayList();break;
			case 4:printf("%d\n",countList());break;
		}
	}while(1);
	return 0;
}
