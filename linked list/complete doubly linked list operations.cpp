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
	printf("\n");
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
	        printf("\n");
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

node* insert(node *start)
{
	node *temp,*ptr,*temp1;
	int val,pos;
	printf("\n");
	printf("enter value to be inserted: ");
	scanf("%d",&val);
	printf("enter position at which value to be inserted");
	scanf("%d",&pos);
	
	if(start==NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=val;
		start=temp; 
		start->flink=NULL;
		start->blink=NULL;
	}
	else
	{	
		if(pos==1)
		{
			temp=(node*)malloc(sizeof(node));
			temp->data=val;
		    temp->flink=start;
		    start->blink=temp;
		    start=temp;
		}
		if(pos>1)
		{
			ptr=start;
			node *ptr1;
			int count=1;
			temp=(node*)malloc(sizeof(node));
			temp->data=val;
			while(ptr!=NULL && count<pos-1)
			{
				ptr=ptr->flink;
				count++;
			}
			if(ptr!=NULL)
			{
				ptr1=ptr->flink;
				temp->flink=ptr1;
				temp->blink=ptr;
				ptr->flink=temp;
				if(ptr1!=NULL)
				ptr1->blink=temp;
			}
			else
			{
				printf("\ninvalid position\n");
			}
		}
		if(pos<=0)
		{
			printf("\ninvalid position\n");
		}
	}
	return start;
}

node* _delete(node *start)
{
	node *temp,*ptr;
	
	if(start==NULL)
	{
		printf("deletion cannot be performed as list is empty");
	}
	else
	{
		int pos,val;
	    printf("enter node position to be deleted");
	    scanf("%d",&pos);
		if(pos>0)
		{
			if(pos==1)
		    	{
			     	temp=start;
			 	    start=start->flink;
			    	val=temp->data;
		    		free(temp);
		    		printf("the deleted element is = %d",val);
			}
			else
		    	{
		           int count=1;
		           temp=start;
		            while(temp->flink!=NULL && count<pos-1)
		           {
		            	temp=temp->flink;
		     	        count++;
			        }
			   
			        if(count==pos-1)
			        {
				        ptr=temp->flink;
				        val=ptr->data;
				        temp->flink=ptr->flink;
				        if(ptr->flink!=NULL)
				        (ptr->flink)->blink=temp;
				        free(ptr);
				        printf("the deleted element is = %d",val);
			        }
		         	else
			        {
				        printf("invalid position");
			        }
			    }
			}
		else
		  printf("invalid position");
    }
	
   	return start;
}

int main()
{
	node *start;
	printf("enter elements of linked list :- \n");
	start=create();
	printf("\n\n");
	while(1)
	{
	    int x;
	    printf("press 1 to traverse \npress 2 to insert element at any position\n press 3 to delete at any position ");
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
	    printf("\n\n");
    }
}



