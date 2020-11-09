#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node *flink,*blink;
}node;

node* create()
{
	node *start,*temp,*last;
	int x;
	printf("press 1 to enter value \npress 0 to exit");
	scanf("%d",&x);
	if(x==0)
	{
		start=NULL;
	}
	if(x==1)
	{
		start=(node*)malloc(sizeof(node));
		printf("enter data");
		scanf("%d",&(start->data));
		start->blink=NULL;
			last=start;
		
		while(1)
		{
			int y;
        	printf("press 1 to enter value \npress 0 to exit");
	        scanf("%d",&y);
		 if(y==1)
		 {
		 	temp=(node*)malloc(sizeof(node));
		 	printf("enter data");
		    scanf("%d",&(temp->data));
		    last->flink=temp;
		    temp->blink=last;
		    last=last->flink;
		 }	
		 if(y==0) 
		    break;	    
		}
		last->flink=NULL;
	}
	return start;
}

void rev_by_data_swapping(node *front,node *last)
{
       	if((front!=last) && ( (last->flink)!=front && (front->blink)!=last ))
       	{
       		int temp;
       		temp=front->data;
       		front->data=last->data;
       		last->data=temp;
       		rev_by_data_swapping(front->flink,last->blink);
	   	}	
}

node* normal_rev(node* start,node *prev,node *curr,node *next)
{
   	if(next!=NULL)
   	{
   		curr->flink=prev;
   		prev=curr;
		curr=next;
    	prev->blink=curr;
   		next=curr->flink;
   		curr->flink=prev;
   		start=curr;
   		start=normal_rev(start,prev,curr,next);
   	}
    return start;
}

node *rev_by_reversingptr(node *start,node *curr,node *next)
{
	if(next!=NULL)
	{
    	next=curr->flink;
        curr->flink=curr->blink;
        curr->blink=next; 
        start=curr;
    	curr=next;
    	start=rev_by_reversingptr(start,curr,next);
    }
    return start;
}

void traverse(node *start)
{
	node *temp;
	if(start==NULL)
	{
		printf("list is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%2d ",temp->data);
			temp=temp->flink;
		}
	}
}
int main()
{
	node *start;
	while(1)
	{
	    int x;
	    printf("press 1 to create\npress 2 to reverse by data swapping\npress 3 to reverse by reversing pointers\npress 4 to reverse as SLL manner\npress 5 to traverse\npress 6 to exit ");
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
		        	if(start!=NULL)
		        	{
		            	node *last;
		            	last=start;
		            	while(last->flink!=NULL)
                    	{   
                    		last=last->flink;
                    	}
    		            rev_by_data_swapping(start,last);
    		        }
		    	    break;
			    }
		    case 3:
		        {
                    start=rev_by_reversingptr(start,start,start);
				    break;		
			    }
		    case 4:
		    	{
		    		if(start!=NULL)
		    		{
	     	    		start=normal_rev(start,NULL,start,start->flink);
    				}
    				break;
				}
			case 5:
		    	{
		    		printf("linked list is :- ");
			        traverse(start);
					break;
				}
			case 6:
				{
					exit(0);
					break;
				}
	   }
	    printf("\n");
    }
}
