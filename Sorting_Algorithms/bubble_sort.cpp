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
void bubble_sort(int arr[],int n)
{
	int temp,i,j;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void printarray(int arr[],int n)
{
	int i;
	printf("the sorted array by BUBBLE SORT algorithm= ");
	for(i=0;i<n;i++)
	{
		printf("%2d ",arr[i]);
	}
}
int main()
{
	int n,arr[100];
	int x;
	while(1)
	{
		printf("press 1 to Enter Data\nPress 0 to Exit");
		scanf("%d",&x);
		printf("\n");
		if(x==0)
		break;
    	n=getarray(arr);
    	bubble_sort(arr,n);
    	printarray(arr,n);
    	printf("\n\n");
    }
    return 0;
}
