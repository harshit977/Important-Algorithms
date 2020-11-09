#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int exp,coeff;
	node *link;
}node;

node *create()
{
	node *start,*temp,*last;
	int x;
	start=NULL;
	printf("press 1 to enter (exp,coeff) pair\npress 0 to exit ");
	scanf("%d",&x);
	if(x==0)
	{
		start=NULL;
	}
	else
	{
		while(1)
		{
			temp=(node*)malloc(sizeof(node));
			if(temp!=NULL)
			{
			printf("enter exponent:");
			scanf("%d",&(temp->exp));
			printf("enter coefficient:");
			scanf("%d",&(temp->coeff));
			if(start==NULL)
			{
				start=temp;
				last=start;
			}
			else
			{
				last->link=temp;
				last=temp;
			}
		    }   
			else
			{
				printf("memory allocation not possible");
			}
		    printf("press 1 to enter (exp,coeff) pair again\npress 0 to exit ");
	        scanf("%d",&x);
	        if(x==0)
	        break;
	    }
	    last->link=NULL;
	}
	return start;
}

node *add_poly(node *start1, node *start2)
{
	node *start3,*temp1,*temp2,*temp ,*last;
	temp1=start1;
	temp2=start2;
	start3=NULL;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(((temp1->exp)==(temp2->exp)) && ((temp1->coeff)+(temp2->coeff)==0))
		{ 
		   temp1=temp1->link;
		   temp2=temp2->link;
		}
		else
		{
		if((temp1->exp)>(temp2->exp))
		{
			temp=(node*)malloc(sizeof(node));
			temp->exp=temp1->exp;
			temp->coeff=temp1->coeff;
			temp1=temp1->link;
		}
		else if((temp1->exp)<(temp2->exp))
		{
			temp=(node*)malloc(sizeof(node));
			temp->exp=temp2->exp;
			temp->coeff=temp2->coeff;
			temp2=temp2->link;
		}
		else
		{
			temp=(node*)malloc(sizeof(node));
			temp->exp=(temp1->exp);
			temp->coeff=(temp1->coeff)+(temp2->coeff);	
			temp1=temp1->link;
			temp2=temp2->link;
		}
		if(start3==NULL)
		{
			start3=temp;
			last=start3;
		}
		else
		{
			last->link=temp;
			last=temp;
		}
    	}  
	}
	while(temp1!=NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->exp=temp1->exp;
		temp->coeff=temp1->coeff;
		if(start3==NULL)
		{
			start3=temp;
			last=start3;
		}
		else
		{
			last->link=temp;
			last=temp;
		}
		temp1=temp1->link;
	}
	while(temp2!=NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->exp=temp2->exp;
		temp->coeff=temp2->coeff;
		if(start3==NULL)
		{
			start3=temp;
			last=start3;
		}
		else
		{
			last->link=temp;
			last=temp;
		}
		temp2=temp2->link;
	}	
	last->link=NULL;
	return start3;
}
void traverse(node *start)
{
	node *temp;
	temp=start;
	if(start==NULL)
	{
		printf("polynomial is empty");
	}
	else
	{
	  while(temp->link!=NULL)
	  {
	    	if(temp->link->coeff>0)
	  	        printf("%dx^%d+",temp->coeff,temp->exp);
	    	if(temp->link->coeff<0)
	  	        printf("%dx^%d",temp->coeff,temp->exp);
	    temp=temp->link;
	  }
	  if(temp->exp==0)
	  { 
    	  printf("%d",temp->coeff);
	  }
	  else
	  {
    	  printf("%dx^%d",temp->coeff,temp->exp); 
      }
    }
}
int main()
{
	node *start1,*start2,*start3;
	printf("Enter polynomial 1 :\n");
	start1=create();
	printf("Enter polynomial 2 :\n");
	start2=create();
	start3=add_poly(start1,start2);
	printf("This is the operation performed \n [");
	traverse (start1);
	printf(" ] + [ ");
	traverse (start2);
	printf(" ] \n = ");
	traverse (start3);
}
