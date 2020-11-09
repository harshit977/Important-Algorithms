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

int main()
{
	int v,directed;
	cout<<"Total No. of vertices in graph: ";   //vertices are 0 to v-1
	cin>>v;
	cout<<"Is your graph directed:(0/1) ";
	cin>>directed;
	vector<int> adj[v];
	int i=1;
	while(i)
	{
		int left,right;
		cout<<"enter left vertex: ";
		cin>>left;
		cout<<"enter right vertex: ";
		cin>>right;
		set_Edge(adj,left,right,directed);
		cout<<"\n";
		cout<<"Press 1 to enter again\nPress 0 to exit";
		cin>>i;
	}
	print_graph(adj,v);
	return 0;
}

