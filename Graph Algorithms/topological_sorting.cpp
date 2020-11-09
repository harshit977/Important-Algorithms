#include<bits/stdc++.h>
using namespace std;

void set_Edge(vector<int> adj[],int x,int y)
{
    adj[x].push_back(y);
}

void print_graph(vector<int> adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		cout<<"Adjacency List of vertex "<<i<<" is: ";
		
		for (int x=0 ;x<adj[i].size(); x++)
		  {
		   if(x==adj[i].size()-1)
		   cout<<adj[i].at(x);
		   else 
           cout<<adj[i].at(x)<<" ->";
	      }
        printf("\n"); 
	}
}

void topologicalSort_rec_fn(vector<int> adj[],int vertex,int visited[],stack<int>& Stack)
{
	visited[vertex]=1;
	
	for(int x=0 ;x<adj[vertex].size(); x++)
    	{
    		if(visited[adj[vertex].at(x)]==0)
    		{
    			topologicalSort_rec_fn(adj,adj[vertex].at(x),visited,Stack);
    		}
    	}
	Stack.push(vertex);
}

void topological_sort(vector<int> adj[],int v)
{
   stack<int> Stack; 
   
   int visited[v]; 
   for (int i = 0; i < v; i++) 
       visited[i] = 0; 
  
   for (int i = 0; i < v; i++) 
        if (visited[i] == 0) 
            topologicalSort_rec_fn(adj,i, visited, Stack); 
  
    // Print contents of stack 
    while (!Stack.empty()) { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
}

int main()
{
	int v;
	cout<<"Total No. of vertices in graph: ";   //vertices are 0 to v-1
	cin>>v;
	cout<<"\nEnter the Edges:- \n\n";
	vector<int> adj[v];
	int i=1;
	while(i)
	{
		int left,right;
		cout<<"enter one end: ";
		cin>>left;
		cout<<"enter other end: ";
		cin>>right;
		set_Edge(adj,left,right);
		cout<<"\n";
		cout<<"Press 1 to enter again\nPress 0 to exit";
		cin>>i;
	}
	print_graph(adj,v);
	cout<<"\n";
	cout<<"Topological Order: ";
    topological_sort(adj,v);
}
