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

node* insert(node *start)
{
	node *temp,*ptr;
	int val,pos;
	printf("enter value to be inserted: ");
	scanf("%d",&val);
	printf("enter position: ");
	scanf("%d",&pos);
	if(start==NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=val;
		temp->link=NULL;
		start=temp;
	}
	else
	{
		if(pos==0)
		{
			printf("\ninvalid position");
		}
	    if(pos!=1 && pos>0)
	    {
	    	int count=1;
	    	ptr=start;
	    	while(ptr!=NULL && count<pos-1)
	    	{
	    		ptr=ptr->link;
	    		count++;
			}
			if(ptr!=NULL)
			{
	    	temp=(node*)malloc(sizeof(node));
		    temp->data=val;
		    temp->link=ptr->link;
		    ptr->link=temp;
		    }
		    else
		    printf("\ninvalid position");
		}
		if(pos==1)
		{
			ptr=start;
			temp=(node*)malloc(sizeof(node));
		    temp->data=val;
		    temp->link=ptr;
		    start=temp;
		}
	}
return start;	
}

node* _delete(node* start)
{
	node *temp,*ptr;
	if(start==NULL)
	{
		printf("\ndeletion cannot be performed as list is empty\n ");
	}
	else
	{
		int pos,val;
		printf("enter that node position before which the node is to be deleted ");
		scanf("%d",&pos);
		
		if(pos==1)
		{
			printf("No node exist before this position");
		}
		else if(pos==2)
		{
			temp=start;
			start=start->link;
			val=temp->data;
			free(temp);
			printf("the deleted element is= %d",val);
			printf("\n");
		}
		else if(pos>2)
		{
			temp=start;
			int count=1;
			while((temp->link)!=NULL && count<pos-2)
			{
				temp=temp->link;
				count++;
			}
			if(temp->link==NULL)
			{
				printf("invalid position");
			}
			else if(count==pos-2)
			{
				ptr=temp->link;
				val=ptr->data;
				temp->link=ptr->link;
				free(ptr);
				printf("the deleted element is= %d",val);
				printf("\n");
			}
			else
			{
				printf("invalid position\n");
			}
		}
		else
		{
			printf("invalid position");
		}
	}
	return start;
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
	printf("press 1 to traverse \npress 2 to insert element at any position \npress 3 to delete at given position\n ");
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
		    	start=insert(start);
		    	break;
			}	
		case 3:
			{
				start=_delete(start);
				break;
		    }
	}
	printf("\n");
    }
}
