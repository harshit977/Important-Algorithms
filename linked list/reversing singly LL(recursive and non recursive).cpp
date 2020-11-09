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

node* non_rec_reverse(node *start)
{
	if(start!=NULL)
	{
		node *next,*prev,*curr;
	    curr=start;
    	next=curr->link;
    	prev=NULL;
		while(next!=NULL)
		{
			curr->link=prev;
			prev=curr;
			curr=next;
			next=next->link;
			curr->link=prev;
		}
		start=curr;
		return start;
	}
	else
	{
		start=NULL;
		return start;
	}	
}

node* rec_reverse(node *start,node *prev,node *curr,node *next)
{
	if(next!=NULL)
	{
       	curr->link=prev;
		prev=curr;
		curr=next;
		next=next->link;
		curr->link=prev;
		start=curr;
		start=rec_reverse(start,prev,curr,next);
	}
	return start;
}

int main()
{
	node *start;
	while(1)
	{
	int x;
	printf("press 1 to create\npress 2 to apply non recursive reverse\npress 3 to apply recursive reverse\npress 4 to traverse list\npress 5 to exit ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		    {
			    printf("enter elements of linked list :- \n");
            	start=create();
			    break;
		    }
		case 2:
		    {
		    	start=non_rec_reverse(start);
		    	break;
			}	
		case 3:
			{
				if(start!=NULL)
				{
			    	start=rec_reverse(start,NULL,start,start->link);
			    }
			    else
			    {
			    	start=NULL;
				}
				break;
		    }
		case 4:
		    {
		    	printf("the linked list is:- ");
		    	traverse(start);
				break;
			}
		case 5:
			{
				exit(0);
				break;
			}
	}
	printf("\n");
    }
}
