#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node *link;
}node;

void push(int val, node **top)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
     if(temp!=NULL)
	 {
	 	temp->data=val;
	 	if(*top==NULL)
	 	{
	 		*top=temp;
	 		(*top)->link=NULL;
		 }
		 else
		 {
		 	temp->link=*top;
		 	*top=temp;
		 }
	 }	
	 else
	 {
	 	printf("Memory Allocation Not Possible !! ");
	 }
}

int pop(node **top)
{
	int val;
	if(*top!=NULL)
	{
		node *temp;
		temp=*top;
		val=(*top)->data;
		*top=(*top)->link;
		free(temp);
		return val;
	}
	else
	return -100;
}

void traverse(node *top)
{
	printf("displaying the elements of stack: ");
	if(top!=NULL)
	{
    	node *temp;
     	temp=top;
    	while(temp!=NULL)
    	{
    		printf("%d ",(temp->data));
    		temp=temp->link;
    	}
    }
    else
    {
    	printf("stack empty");
	}
}

int main()
{
	node *top=NULL;
	int x;
	while(1)
	{
	    printf("press 1 to push element\npress 2 to pop element\npress 3 to display\npress 4 to exit ");
    	scanf("%d",&x);
    	printf("\n");
    	
    	switch(x)
    	{
    		case 1:{
    		    	    int val;
    	    		    printf("enter element to be pushed: ");
    		    	    scanf("%d",&val);
    		    	    push(val,&top);
    		   	    	printf("\n");
			        	break;
		    	   }
		    case 2:{
		          	    int val;
		          	    printf("the popped element is: %d",pop(&top));
		       	    	printf("\n");
		    			break;
				   }
			case 3:{
			            traverse(top);  
						printf("\n");   	
		    			break;
				   }
			case 4:{
	    			    exit(0);
	    		    	printf("\n");
    					break;
				   }
		}
		printf("\n");
    }
}

