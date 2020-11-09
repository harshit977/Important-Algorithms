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
void insertion_sort(int arr[],int n)
{
   int var;
   int i,j;
   for(i=1;i<n;i++)
   {
       var=arr[i];
       int j=i-1;
       while(j>=0 && (arr[j]>var))
           {
   	            arr[j+1]=arr[j];
   	            j--;
           }
        arr[j+1]=var;
   }
}
void printarray(int arr[],int n)
{
	int i;
	printf("the sorted array by INSERTION SORT algorithm= ");
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
    	insertion_sort(arr,n);
    	printarray(arr,n);
    	printf("\n\n");
   }
}
