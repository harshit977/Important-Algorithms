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
	printf("enter data: ");
	scanf("%d",&(start->data));
	 int var;
	 printf("enter more data: ");
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
    	int s1=0,s2=0;
    	int count=0;
    	while(temp!=NULL)
    	{
    		if(count%2==0)
    		s1=s1+(temp->data);
    		else
    		s2=s2+(temp->data);
    		temp=temp->link;
    		count++;
		}	
		printf(" odd positioned:- %d",s1);
		printf(" even positioned:- %d",s2);
	}
	
		int main()
	{
		printf("enter data to linked list \n");
		node *start;
		start=create();
		traverse(start);
	}
