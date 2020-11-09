#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void max_heapify(int arr[],int i,int n)
{
	int l=2*i,r=2*i+1;
	int largest;
	
	if(l<=n && arr[i]<arr[l])
		largest=l;
    else
        largest=i;
    
	if(r<=n && arr[r]>arr[largest])
		largest=r;
	
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest,n);
	}
}

void build_max_heap(int arr[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		max_heapify(arr,i,n);
	}
}

int main()
{
	int n;
	cout<<"enter number of elements: ";
	cin>>n;
	int arr[n+1];
	cout<<"enter the elements";
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	cout<<"\n";
	build_max_heap(arr,n);
	int k=n;
	for(int i=1;i<=n;i++)
	{
		cout<<arr[1]<<" ";
		arr[1]=arr[k];
		k--;
		max_heapify(arr,1,k);
	}
}
