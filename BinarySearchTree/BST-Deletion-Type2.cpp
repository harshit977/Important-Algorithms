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
 
 int swap(int& a,int& b)
 {
 	int t;
 	t=a;
 	a=b;
 	b=t;
 }
 
 node* search(node *root,int a)
 {
 	node* temp;
 	temp=root;
 	if(temp==NULL)
 	{
 		return NULL;
	 }
 	if(temp->data==a)
 	return temp;
 	
 	else if(temp->data>a)
 	{
 		return search(temp->left,a);
	 }
	 else
	 {
	 	return search(temp->right,a);
	 }
 }
 
  void delete_tree(node *root,int a)
 {
 		node *searched_node=search(root,a);
 	if(root==NULL)
 	return;
 	
 	if(searched_node==NULL)
 	return;
 	
 	if(searched_node==root && searched_node->left==NULL && searched_node->right==NULL)
 	{
 	    	free(searched_node);
 	    	return;
	 }
	 
 	if(searched_node->left==NULL && searched_node->right==NULL)
 	{
 		node *parent=searched_node->parent;
 		
 		if(searched_node->data>parent->data)
 		parent->right=NULL;
 		else
 		parent->left=NULL;
 		free(searched_node);
 		return;
	 }
	 else if((searched_node->left!=NULL && searched_node->right==NULL) || (searched_node->left==NULL && searched_node->right!=NULL))
	 {
	 	if(searched_node->left!=NULL)
	 	{
	 		swap(searched_node->data,(searched_node->left)->data);
	 		node* temp=searched_node->left;
	 		searched_node->left=NULL;
	 		free(temp);
		 }
		 if(searched_node->right!=NULL)
	 	{
	 		swap(searched_node->data,(searched_node->right)->data);
	 		node* temp=searched_node->right;
	 		searched_node->right=NULL;
	 		free(temp);
		 }
		 return;
	 }
	 else
	 {
	 	node* min_node=find_min(searched_node->right);
	 	swap(min_node->data,searched_node->data);
	 	delete_tree(searched_node->right,(min_node->data));
	 }
 	
 	
 }
 
 
void inorder_traverse(node* start)
{
	node* temp;
	temp=start;
	if(start=NULL)
	cout<<"Empty Set";
	
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
	cout<<"enter tree elements: ";
	root=create_bst();
	
	cout<<"\n";
	cout<<"Inorder Traversal: ";
    inorder_traverse(root);
    
    cout<<"\n\n";
    
    int num;
    cout<<"enter number to be deleted: ";
    cin>>num;
    delete_tree(root,num);
    
    cout<<"\n";
    
    cout<<"Inorder Traversal: ";
    inorder_traverse(root);
	
    
 }
