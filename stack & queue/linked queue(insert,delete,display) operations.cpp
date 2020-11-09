#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node *link;
}node;

void insertq(int val, node **front,node **rear)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
     if(temp!=NULL)
	 {
	 	temp->data=val;
	 	if((*front)==NULL)
	 	{
	 		*front=temp;
	 		*rear=temp;
		}
		else
		{
			(*rear)->link=temp;
			(*rear)=temp;
		}
		(*rear)->link=NULL;
	 }	
	 else
	 {
	 	printf("Memory Allocation Not Possible !! ");
	 }
}

int deleteq(node **front, node **rear)
{
	node *temp;
	int val;
	if((*front)!=NULL && (*rear)!=NULL)
	{
		temp=*front;
	    val=(*front)->data;
	    if(*rear==*front)
	    {
	    	(*front)=(*front)->link;
	    	(*rear)=(*rear)->link;
	    }
	    else
	    {
	    	(*front)=(*front)->link;
		}
		    free(temp);
		return val;	
	}
	else
	return -100;
}

void traverse(node *front)
{
	printf("displaying the elements of queue: ");
	if(front!=NULL)
	{
    	node *temp;
     	temp=front;
    	while(temp!=NULL)
    	{
    		printf("%d ",(temp->data));
    		temp=temp->link;
    	}
    }
    else
    {
    	printf("queue empty");
	}
}

int main()
{
	node *front=NULL,*rear=NULL;
	int x;
	while(1)
	{
	    printf("press 1 to insert element\npress 2 to delete element\npress 3 to display\npress 4 to exit ");
    	scanf("%d",&x);
    	printf("\n");
    	
    	switch(x)
    	{
    		case 1:{
    		    	    int val;
    	    		    printf("enter element to be inserted: ");
    		    	    scanf("%d",&val);
    		    	    insertq(val,&front,&rear);
    		   	    	printf("\n");
			        	break;
		    	   }
		    case 2:{
		          	    int val;
		          	    printf("the deleted element is: %d",deleteq(&front,&rear));
		       	    	printf("\n");
		    			break;
				   }
			case 3:{
			            traverse(front);  
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

