#include<stdio.h>
#include<limits.h>

void merge(int arr[],int left,int right,int mid)
{
	int size1=mid-left+1,size2=right-mid;
	int L[size1+1],R[size2+1];   //one extra size is taken
	int i,j,k;
	
	for(i=left,j=mid+1;i<=mid||j<=right;i++,j++)
	{
		L[i-left]=arr[i];
		R[j-mid-1]=arr[j];
	}
	L[size1]=INT_MAX;        //placing very large values at last
	R[size2]=INT_MAX;        //placing very large values at last
	
	i=0,j=0;
	k=left;
	
	while(i<size1+1 && j<size2+1 && k<=right)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=R[j];
			j++;
			k++;
		}
	}
	/*while(i<size1)
	{
		arr[k]=L[i];
			i++;
			k++;
	}
	while(j<size2)
	{
		arr[k]=R[j];
			j++;
			k++;
	}*/
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
