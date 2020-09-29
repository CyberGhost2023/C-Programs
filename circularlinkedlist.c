#include<stdio.h>
#include<stdlib.h>

struct linkedList{
	int data;
	struct linkedList* next;
};
struct linkedList* head=NULL;

void insertNode(int value,int pos){
	struct linkedList* temp=(struct linkedList*)malloc(sizeof(struct linkedList));
	temp->data = value;
	if(pos==1)
	{
		if(head)
		{
			temp->next=head;
			struct linkedList *itr=head;
			while(itr->next!=head)
				itr=itr->next;
			itr->next=temp;
		}
		else
		{
			temp->next=temp;
		}
		head=temp;
	}
	else if(head==NULL)
	{
		free(temp);
		printf("position not found\n");
	}
	else 
	{
		int count=1,flag=1;
		struct linkedList *itr1=head,*itr2 = head;
		while((count!=pos && itr2!= head)||flag)
		{
			flag=0;
			itr1=itr2;
			itr2 = itr2->next;
			count++;
		}
		if(count==pos)
		{
			temp->next=itr1->next;
			itr1->next=temp;
		}
		else
		{
			free(temp);
			printf("position not found\n");
		}
	}
}

void deleteNode(int pos)
{
	if(head==NULL)
		printf("List is Empty\n");
	else if(head->next==head)
	{
		struct linkedList *temp=head;
		head=NULL;
		free(temp);
	}
	else if(pos==1)
	{
		struct linkedList *temp = head,*itr=head;
		while(itr->next!=head)
			itr=itr->next;
		itr->next=head=head->next;
		free(temp);
	}
	else
	{
		int count = 1;
		struct linkedList *itr1= head,*itr2=head;
		int flag=1;
		while((pos!=count && itr2->next!=head)||flag)
		{
			flag=0;
			itr1=itr2;
			itr2=itr2->next;
			count++;
		}
		if(pos==count)
		{
			itr1->next=itr2->next;
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
		int flag=1;		
		while(flag || itr!=head )
		{
			flag=0;
			printf("%d\t",itr->data);
			itr=itr->next;
		}
	}
}

int countList()
{
	if(head==NULL)
		return 0;
	int count=0,flag=1;
	struct linkedList *itr=head;		
	while(itr!=head ||flag)
	{
		itr=itr->next;
		count++;
		flag=0;
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
