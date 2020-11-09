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
