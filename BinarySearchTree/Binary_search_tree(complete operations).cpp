#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h> 
 using namespace std;
 
typedef struct node
{
	int data;
	node *left;
	node *right;
	node* parent;
}node;

node* create_bst()
{
    node *start,*temp,*prev,*ptr;
    start=NULL;
    int x;
    while(1)
    {
        printf("press 1 to enter data\npress 0 to exit ");
        scanf("%d",&x);
        printf("\n");
        if(x==1)
        {
        	int val;
            printf("enter data: ");
            scanf("%d",&val);
            temp=(node*)malloc(sizeof(node));
            temp->data=val;
            temp->left=NULL;
            temp->right=NULL;
            if(start==NULL)
            {
            	start=temp;
            	start->parent=NULL;
    		}
	    	else
    		{
    			ptr=start;
                while(ptr!=NULL)
                {
                	prev=ptr;
                	if(val>ptr->data)
                	ptr=ptr->right;
                	
                	else if(val<ptr->data)
                	ptr=ptr->left;
				}
				temp->parent=prev;
				if(val<prev->data)
				prev->left=temp;
				
				if(val>prev->data)
				prev->right=temp;
	    	}
    	}
        else
	    {
    		break;
    	}
    }
   	return start;
}

node* rec_insert(node *start,int val)
{
    node *temp,*ptr,*prev;
    ptr=start;
    if(ptr==NULL)
    {
        temp=(node*)malloc(sizeof(node));
     	temp->data=val;
     	temp->left=NULL;
     	temp->right=NULL;
     	ptr=temp;
     	return ptr;
	}
	else
	{
	   	   if(val<ptr->data)
	   	   ptr->left=rec_insert(ptr->left,val);
	   	   
	   	   else if(val>ptr->data)
	   	   ptr->right=rec_insert(ptr->right,val);
	}
	
}

node* non_rec_insert(node *start,int val)
{
    node *temp,*ptr,*prev;
    temp=(node*)malloc(sizeof(node));
   	temp->data=val;
  	temp->left=NULL;
   	temp->right=NULL;
    if(start==NULL)
    {
    	start=temp;	
	}
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			prev=ptr;
			if(val>ptr->data)
			ptr=ptr->right;
			else if(val<ptr->data)
			ptr=ptr->left;
		}
		if(val>prev->data)
		prev->right=temp;
		if(val<prev->data)
		prev->left=temp;
	}
	return start;
}

node* rec_search(node *start,int val)
{
    node *temp;
	temp=start;
	if(temp!=NULL)
	{
    	if(val==temp->data)
        	return temp;
    	else if(val<temp->data)
        	return  rec_search(temp->left,val);
    	else if(val>temp->data)
         	return  rec_search(temp->right,val);
	}
}

node* non_rec_search(node *start,int val)
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		if(val==temp->data)
		return temp;
		
		else if(val<temp->data)
		temp=temp->left;
		
		else if(val>temp->data)
		temp=temp->right;
	}
}

node *inorder_traverse(node* start)
{
	node* temp;
	temp=start;
	if(temp!=NULL)
	{
    	inorder_traverse(temp->left); 
    	printf("%d ",temp->data);
    	inorder_traverse(temp->right);
    }
}
void level_order(node *root)
 {
 	if(root==NULL)
 	cout<<"Empty Set";
 	
 	else
 	{
 	   queue<node *> q;
 	   node *temp;
 	   
 	   q.push(root);
 	   q.push(NULL);
 	   
 	   while(q.size()>1)
 	  {
 	  	    temp=q.front();
 	  	    q.pop();
 	  	    if(temp==NULL)
 	  	    {
 	  	        q.push(NULL);
 	  	        cout<<"\n";
 	  	    }
 	  	    else
 	  	    {
     	  	    cout<<temp->data<<" ";
 	    	
 	        	if(temp->left!=NULL)
 	        	q.push(temp->left);
 	    	
 	        	if(temp->right!=NULL)
 	        	q.push(temp->right);	
 	        }
	 }
     }
 }
int main()
{
	node *start;
	start=NULL;
	int x;
	while(1)
	{
    	printf("press 1 to create BST\npress 2 for inorder traverse\npress 3 for recursive search\npress 4 for non-recursive search\npress 5 for recursive insert\npress 6 for non-recursive insert\npress 7 for level-order traversal\npress 8 to exit ");
    	scanf("%d",&x);
    	printf("\n");
    	switch(x)
    	{
    		case 1:
    		{
	    		start=create_bst();
	    		printf("\n");
	    		break;
    		}
     		case 2:
	   		{
				inorder_traverse(start);
				printf("\n");
				break;
			}
			case 3:
			{
				node *temp=NULL;
				int val;
				printf("enter value to be searched: ");
				scanf("%d",&val);
				printf("\n");
				temp=rec_search(start,val);
				if(temp==NULL)
				printf("------DATA NOT FOUND-------");
				else
				printf("the data is found successfully : %d",temp->data);
				printf("\n");
				break;
			}
			
			case 4:
			{
				node *temp=NULL;
				int val;
				printf("enter value to be searched: ");
				scanf("%d",&val);
				printf("\n");
				temp=non_rec_search(start,val);
				if(temp==NULL)
				printf("------DATA NOT FOUND-------");
				else
				printf("the data is found successfully : %d",temp->data);
				printf("\n");
				break;
			}
			
			case 5:
			{
				int val;
				printf("enter data to be inserted: ");
				scanf("%d",&val);
				start=rec_insert(start,val);
				break;
			}
			case 6:
			{
				int val;
				printf("enter data to be inserted: ");
				scanf("%d",&val);
				start=non_rec_insert(start,val);
				break;
			}
    		case 7:
    		{
    			printf("Level Order Traversal: \n");
	    		level_order(start);
	    		printf("\n");
	    		break;
	    	}
	    	case 8:
	    	{
	    	    exit(0);
		    	break;		
			}
	    }
	    printf("\n");
    }
}
