#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node *link;
}node;

node *create()
{
	node *start,*last,*temp;
	int x;
	printf("press 1 to enter value \npress 0 to exit");
	scanf("%d",&x);
	if(x==0)
	{
		start=NULL;
	}
	if(x==1)
	{
		int var;
		start=(node*)malloc(sizeof(node));
		printf("enter data: ");
		scanf("%d",&var);
		start->data=var;
		last=start;
		printf("\n");
		while(1)
	{
	  int x;
	  printf("press 1 to enter value \npress 0 to exit");
	  scanf("%d",&x);
	  if(x==0)
	  {
	  last->link=NULL;
	  break;
      }
	  else
	  {
	  	int var;
	  	 printf("enter data: ");
		 scanf("%d",&var);
	  	 temp=(node*)malloc(sizeof(node));
	  	 temp->data=var;
	  	 last->link=temp;
	  	 last=last->link;
	  	 
	  }
	  printf("\n");
	}
	last->link=NULL;
    }
    return start;
    printf("\n");
}
void traverse(node *start)
{
	node *temp;
	temp=start;
	if(start==NULL)
	{
		printf("\n");
		printf("list empty");
	}
	else
	{
		while(temp!=NULL)
		{
		printf("%d ",temp->data);
		temp=temp->link;
	    }
	    printf("\n");
	}
}

void insert(node *start)
{
	node *temp,*ptr;
	int val,value;
	printf("enter value to be inserted: ");
	scanf("%d",&val);
	printf("enter value after which it is inserted:");
	scanf("%d",&value);

        temp=(node*)malloc(sizeof(node));
		temp->data=val;
		ptr=start;
		while(ptr!=NULL && (ptr->data)!=value)
		{
			ptr=ptr->link;
		}
		if(ptr!=NULL)
		{
			temp->link=ptr->link;
			ptr->link=temp;
		}
		else
		    {
			    printf("value not found in linked list");
			}	
}

void _delete(node* start)
{
	node *temp,*ptr;
	if(start==NULL)
	{
		printf("\ndeletion cannot be performed as list is empty\n ");
	}
	else
	{
		int value,val;
		printf("enter value after which node to be deleted ");
		scanf("%d",&value);
	
			ptr=start;
			while( ptr!=NULL && (ptr->data)!=value)
	     	{    
		    	ptr=ptr->link;
		    }
			
			if(ptr==NULL)
			{
				 printf("value not found in linked list");
			}
			else if((ptr->link)==NULL)
			{
				printf("node does not exist after given value");
			}
			else
			{
				temp=ptr->link;
				val=temp->data;
				ptr->link=temp->link;
				free(temp);
				printf("the deleted element is = %d",val);
			}
	}
}

int main()
{
	node *start;
	printf("enter elements of linked list :- \n");
	start=create();
	printf("\n");
	while(1)
	{
	int x;
	printf("press 1 to traverse \npress 2 to insert after a given value \npress 3 to delete after a given value  ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		    {
			    printf("linked list is :- ");
			    traverse(start);
			    break;
		    }
		case 2:
		    {
		    	insert(start);
		    	break;
			}	
		case 3:
			{
				_delete(start);
				break;
		    }
	}
	printf("\n");
    }
}
