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
node* insert(node *start, int val,int pos)
{
	node *ptr,*temp,*temp2;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=val;
	if(pos>1)
	{
	int count=1;
		temp=start;	
	while(count<pos-1 && temp!=NULL)
	{
    	 temp=temp->link;
		 count++;
    }
    temp2=temp->link;
	 ptr->link=temp2;
	 temp->link=ptr;
    }
    else if(pos==1)
    {
    	ptr->link=start;
    	start=ptr;
	}
	else
	{
		printf("invalid position entered");
		exit(1);
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
		int val,pos;
		printf("enter element to be inserted into list");
		scanf("%d",&val);
		printf("enter position:- ");
		scanf("%d",&pos);
		start=insert(start,val,pos);
		printf("displaying the contents of linked list:- ");
		traverse(start);
	}














