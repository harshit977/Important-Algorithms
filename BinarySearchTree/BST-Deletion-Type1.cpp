#include <bits/stdc++.h> 
 using namespace std;
 
 class node
 {
 	public:
 	int data;
 	node *left,*right,*parent;
 };
 
node* create_bst()
{
    node *root,*temp,*prev,*ptr;
    root=NULL;
    int x;
    while(1)
    {
    	cout<<"\n";
        cout<<"press 1 to enter data\npress 0 to exit: ";
        cin>>x;
        cout<<"\n";
        if(x==1)
        {
        	int val;
            cout<<"enter data: ";
            cin>>val;
            temp=(node*)malloc(sizeof(node));
            temp->data=val;
            temp->left=NULL;
            temp->right=NULL;
            if(root==NULL)
            {
            	root=temp;
            	root->parent=NULL;
    		}
	    	else
    		{
    			ptr=root;
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
   	return root;
}

node* find_min(node *root)
 {
 	node *temp=root;
 	while(temp->left!=NULL)
 	{
 		temp=temp->left;
	 }
	 return temp;
 }
 
node* delete_tree(node *root,int a)
 {
    if (root == NULL) return root; 
    
    else if(root->data>a)  return delete_tree(root->left,a);
    
    else if(root->data<a)  return delete_tree(root->right,a);
    
    else
    {
    	// for 0 or 1 child node
    	if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        
        //for 2-child node
        
        node* min_node=find_min(root->right);
        root->data=min_node->data;
        root->right =delete_tree(root->right,min_node->data);
	}
 }
 
 void level_order(node *root)
 {
 	if(root==NULL)
 	return;
 	
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

 void inorder_traverse(node* start)
{
	node* temp;
	temp=start;
	if(temp!=NULL)
	{
    	inorder_traverse(temp->left); 
    	cout<<temp->data<<" ";
    	inorder_traverse(temp->right);
    }
}
 
 int main()
 {
    node* root;
	root=NULL;
	root=create_bst();
	
	cout<<"\n";
	cout<<"Inorder Traversal: ";
    inorder_traverse(root);
    cout<<"\nLevel order Traversal:\n ";
    level_order(root);
    
    cout<<"\n";
    int num;
    cout<<"enter number to be deleted: ";
    cin>>num;
    root=delete_tree(root,num);
    
    cout<<"\n";
	cout<<"Inorder Traversal: ";
    inorder_traverse(root);
    cout<<"\nLevel order Traversal:\n ";
    level_order(root);
}
