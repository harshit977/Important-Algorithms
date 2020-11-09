#include<stdio.h>
void merge(int arr[],int left,int right,int mid);

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

void merge(int arr[],int left,int right,int mid)
{
	int temp[100];
	int i=left,j=mid+1,k=0;
	while(i<=mid && j<=right)
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=right)
	{
		temp[k]=arr[j];
		j++;
		k++;
	}
	int p;
	int l;
	for(l=left,p=0;l<=right;l++,p++)
	{
		arr[l]=temp[p];
	}
}
void mergesort(int arr[],int left,int right)
{
	if(left<right)
	{
	    int mid=(left+right)/2;
	    mergesort(arr,left,mid);
	    mergesort(arr,(mid+1),right);
	    merge(arr,left,right,mid);
    }
}
void printarray(int arr[],int n)
{
	int i;
	printf("the sorted array by MERGE SORT algorithm= ");
	for(i=0;i<n;i++)
	{
	    printf("%2d ",arr[i]);
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
    	mergesort(arr,0,n-1);
    	printarray(arr,n);
    	printf("\n\n");
    }
	return 0;
}
