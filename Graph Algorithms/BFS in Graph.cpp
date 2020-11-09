#include<bits/stdc++.h>
using namespace std;

void set_Edge(vector<int> adj[],int x,int y,int directed)
{
	if(!directed)
	{
	    adj[x].push_back(y);
	    adj[y].push_back(x);
    }
    else
    {
    	adj[x].push_back(y);
	}
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

void BFS_Algorithm(vector<int> adj[],int s,int v)
{
	int visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=0;
	}
	queue<int> q;
	visited[s]=1;
	cout<<s<<" ";
	while(1)
	{ 
    	for(int x=0 ;x<adj[s].size(); x++)
    	{
    		if(visited[adj[s].at(x)]==0)
    		{
	    	   q.push(adj[s].at(x));
	    	   visited[adj[s].at(x)]=1;
	        }
    	}
	    int var=q.front();
	    q.pop();
	    s=var;
	    cout<<s<<" ";
	    int len=0;
	    for(int i=0;i<v;i++)
    	{
	    	len=len+visited[i];
	    }
	    if(len==v)
	    break;
    }
    while(!q.empty())
    {
    	int var=q.front();
    	q.pop();
       cout<<var<<" ";
    }
}

int main()
{
	int v,directed;
	cout<<"Total No. of vertices in graph: ";   //vertices are 0 to v-1
	cin>>v;
	cout<<"Is your graph directed:(0/1) ";
	cin>>directed;
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
		set_Edge(adj,left,right,directed);
		cout<<"\n";
		cout<<"Press 1 to enter again\nPress 0 to exit";
		cin>>i;
	}
	print_graph(adj,v);
	int s;
	cout<<"\nEnter source vertex for BFS Traversal: ";
	cin>>s;
	cout<<"\n";
	cout<<"BFS Order: ";
	BFS_Algorithm(adj,s,v);
}
