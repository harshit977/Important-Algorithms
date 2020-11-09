#include<stdio.h>

int getarray(int arr[])
{
	int n;
	int i;
	printf("enter no of elements to be sorted= ");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	return n;
}
void quicksort(int arr[],int left,int right)
{
	if(right > left)
    {
	int pivot=arr[left];
	int i=left,j=right+1;
	while(i<=j)
	{
	do
	{
		i++;
	}
	while(arr[i]<pivot && i<=right);
	do
	{
		j--;
	}
	while(arr[j]>pivot);
	printarray(arr,n);
	if(i<=j)
	{
		int temp;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
    }
    
    arr[left]=arr[j];
    arr[j]=pivot;
	quicksort(arr,left,j-1);
	quicksort(arr,j+1,right);
}
}

int main()
{
	int arr[100],n;
	int x;
	while(1)
	{
		printf("press 1 to Enter Data\nPress 0 to Exit");
		scanf("%d",&x);
		printf("\n");
		if(x==0)
		break;
    	n=getarray(arr);
    	quicksort(arr,0,n-1);
    	printarray(arr,n);
    	printf("\n\n");
    }
   	return 0;
}
