#include<iostream>
using namespace std;

int main()
{
	int k,n;
	cout<<"enter Value of k: ";
	cin>>k;
	cout<<"enter number of entries: ";
	cin>>n;
	int arr[n],temp[k+1],sorted_array[n];
	cout<<"Enter the entries: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<=k;i++)
	{
		temp[i]=0;
	}
	for(int j=0;j<n;j++)
	{
		temp[arr[j]]++;
	}
	for(int x=1;x<=k;x++)
	{
		temp[x]=temp[x]+temp[x-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		sorted_array[temp[arr[i]]-1]=arr[i];
		temp[arr[i]]--;
	}
	cout<<"the sorted array is: ";
	for(int i=0;i<n;i++)
	{
		cout<<sorted_array[i]<<" ";
	}
}
