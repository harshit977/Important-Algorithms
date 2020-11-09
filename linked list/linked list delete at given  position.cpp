#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node *link;
}node;
 
node* create()
{
	node *start,*last,*temp;
	
	start=(node*)malloc(sizeof(node));
	last=start;
	printf("enter data");
	scanf("%d",&(start->data));
	 int var;
	 printf("enter more data");
	 scanf("%d",&var);
	 while(var!=-1)
	 {
	 	temp=(node*)malloc(sizeof(node));
	 	temp->data=var;
	 	last->link=temp;
	 	last=temp;
	 	scanf("%d",&var);
	 }
	 last->link=NULL;
	 printf("\n");
	 return start;
}
node* _delete(node *start,int pos)
{
	node *temp,*ptr;
	int var;
	if(pos>1)
	{
		int count=1;
		temp=start;
		while(count<pos-1 && temp!=NULL)
		{
			temp=temp->link;
			count++;
		}
		ptr=temp->link;
		var=ptr->data;
		temp->link=ptr->link;
		free(ptr);
		printf("the deleted element = %d \n",var);
	}
	if(pos==1)
	{
		ptr=start;
		temp=start;
		var=temp->data;
		temp=temp->link;
		start=temp;
		free(ptr);
		printf("the deleted element = %d \n",var);
	}
	return start;
}
void traverse(node *start)
    {
    	node *temp;
    	temp=start;
    	while(temp!=NULL)
    	{
    		printf("%d ",temp->data);
    		temp=temp->link;
		}	
	}
	int main()
	{
		printf("enter data to linked list \n");
		node *start;
		start=create();
		printf("displaying the contents of linked list:- ");
		traverse(start);
		printf("\n");
		int pos,var;
		printf("enter position at which element to be deleted ");
		scanf("%d",&pos);
		start=_delete(start,pos);
		printf("displaying the contents of linked list:- ");
		traverse(start);
		printf("\n");
	}

		
		
		
		
		
		
		
		

