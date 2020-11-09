#include<iostream>
using namespace std;

void counting_sort(int arr[],int n,int r)
{
	int temp[10];
	int sorted_array[n];
	for(int i=0;i<=9;i++)
	{
		temp[i]=0;
	}
	for(int j=0;j<n;j++)
	{
		temp[(arr[j]/r)%10]++;
	}
	for(int x=1;x<=9;x++)
	{
		temp[x]=temp[x]+temp[x-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		sorted_array[--temp[((arr[i]/r)%10)]]=arr[i];
	}
	cout<<"phase: ";
	for(int i=0;i<n;i++)
	{
		cout<<sorted_array[i]<<" ";
		arr[i]=sorted_array[i];
	}
	cout<<"\n";
}

void radix_sort(int arr[],int n)
{
	int max=arr[0],d=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		max=arr[i];
	}
	while(max)
	{
		max=max/10;
		d++;
	}
	int r=1;
	while(d>=1)
	{
	int temp_arr[n];
	counting_sort(arr,n,r);
	d--;
	r=r*10;
    }
}
int main()
{
	int n;
	cout<<"enter number of entries: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the entries: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	radix_sort(arr,n);
	cout<<"\nThe sorted array is: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

