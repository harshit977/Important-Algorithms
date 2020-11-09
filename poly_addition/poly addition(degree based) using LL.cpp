#include<stdio.h>
#include<stdlib.h>
 typedef struct node
 {
    	int data;
    	node *link;
 }node;

node *create(int *deg)
{
	node *start,*temp,*last;
	start=NULL;
	printf("enter the degree of polynomial: ");
	scanf("%d",deg);
	int i;
	for(i=0;i<=*deg;i++)
	{
		temp=(node*)malloc(sizeof(node));
		printf("enter coefficient: ");
		scanf("%d",&(temp->data));
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
	last->link=NULL;
	return start;
}

node *addpoly(node *start1,node *start2,int deg1,int deg2,int *deg3)
{
	node *start3,*temp,*temp1,*temp2,*last;
	start3=NULL;
	temp1=start1;
	temp2=start2;
	last=start3;
	int i;
	*deg3=deg1;
	
	if(start1==NULL && start2==NULL)
	start3=NULL;
	
	else if(start1==NULL && start2!=NULL)
	start3=start2;
	
	else if(start1!=NULL && start2==NULL)
	start3=start1;
	
	if(deg1>deg2)
	{
		for(i=0;i<(deg1-deg2);i++)
		{
			temp=(node*)malloc(sizeof(node));
			temp->data=temp1->data;
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
		*deg3=deg1;
	}
	else if(deg1<deg2)
	{
		for(i=0;i<(deg2-deg1);i++)
		{
			temp=(node*)malloc(sizeof(node));
			temp->data=temp2->data;
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
		*deg3=deg2;
	}
		
	while(temp1!=NULL && temp2!=NULL)
	{
		if((start3==NULL) && ((temp1->data)+(temp2->data)==0))
		{
			temp1=temp1->link;
			temp2=temp2->link;
			*deg3--;
		}
		else
		{
    	     temp=(node*)malloc(sizeof(node));
     		 temp->data=(temp1->data)+(temp2->data);
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
    		 temp2=temp2->link;
	    }
	}
	last->link=NULL;
	return start3;
}

void traverse(node *start,int deg)
{
	node *temp;
	temp=start;
	int x=deg;
	if(start==NULL)
	{
		printf("polynomial is empty");
	}
	else
	{
		printf("%dx^%d",temp->data,x);
		x--;
		temp=temp->link;
	  while(temp->link!=NULL && x!=0)
	  {
	     if(temp->data!=0)
		 {
		 	if(temp->data>0)
		 	{
		 		printf("+%dx^%d",temp->data,x);
			}
		 	else if(temp->data<0)
		 	{
		 		printf("%dx^%d",temp->data,x);
			}
		 }
		 temp=temp->link;
		 x--;	
      }
      if(temp->data>0)
      printf("+%d",temp->data);
      else
      printf("%d",temp->data);
    }
}

int main()
{
	node *start1,*start2,*start3;
	int deg1,deg2,deg3;
	printf("enter first polynomial\n");
	start1=create(&deg1);
	printf("\n");
	printf("enter second polynomial\n");
	start2=create(&deg2);
	start3=addpoly(start1,start2,deg1,deg2,&deg3);
	printf("\n");
	printf("first polynomial: ");
	traverse(start1,deg1);
	printf("\n");
	printf("second polynomial: ");
	traverse(start2,deg2);
	printf("\n");
	printf("deg of final polynomial: %d",deg3);
	printf("\n");
	printf("displaying final polynomial: ");
	traverse(start3,deg3);
}
