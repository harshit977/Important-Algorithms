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
	printf("enter data:- ");
	scanf("%d",&(start->data));
	int x;
	printf("enter 1 to add more data \n enter 0 to exit");
	scanf("%d",&x);
	if(x==1)
	{
	 
	 while(1)
	 {
	 	int var;
	    printf("enter data:- ");
	    scanf("%d",&var);
	 	temp=(node*)malloc(sizeof(node));
	 	temp->data=var;
	 	last->link=temp;
	 	last=temp;
	 	int y;
	 	printf("enter 1 to add more data \n enter 0 to exit");
	    scanf("%d",&y);
	    if(y==0)
	    break;
	 }
    }
    else
	{
     last=temp;
    }
    
	 last->link=NULL;
	 printf("\n");
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
	}
