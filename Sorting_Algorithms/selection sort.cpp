#include<stdio.h>
int getarray(int arr[])
{
	int n;
	printf("enter number of elements");
	scanf("%d",&n);
	int i;
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%2d",&arr[i]);
	}
	return n;
}
int selection_sort(int arr[],int n)
{
	int temp;
	int i;
	int j;
	int minindex;
	for(i=0;i<n-1;i++)
	{
		minindex=i;
		for(j=i+1;j<n;j++)
		{
	     	if(arr[j]<arr[minindex])
	     	  {
		    	minindex=j;
		      }  
		}
	   temp =arr[i];
	    arr[i]=arr[minindex];
	    arr[minindex]=temp;
	}
}
void printarray(int arr[],int n)
{
	int i;
		printf("the sorted array by SELECTION SORT algorithm= ");
	for(i=0;i<n;i++)
	{
		printf("%2d ",arr[i]);
	}
}
int main()
{
	
	int arr[100];
	int n;
	int x;
	while(1)
	{
		printf("press 1 to Enter Data\nPress 0 to Exit");
		scanf("%d",&x);
		printf("\n");
		if(x==0)
		break;
	    n=getarray(arr);
	    selection_sort(arr,n);
	    printarray(arr,n);
	    printf("\n\n");
	}
}
