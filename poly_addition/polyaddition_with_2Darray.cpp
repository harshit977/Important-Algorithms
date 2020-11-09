#include<stdio.h>
int getpoly(int poly[2][200])
{
	int t;
	printf("enter no of terms: ");
	scanf("%d",&t);
	printf("enter exponent and coefficient of each term\n");
	for(int i=0;i<t;i++)
	{
		printf("exponent: ");
		scanf("%d",&poly[0][i]);
		printf("coefficient: ");
		scanf("%d",&poly[1][i]);
	}
	return t;
}
int addpoly(int poly1[2][200],int poly2[2][200],int poly3[2][200],int n1,int n2)
{
	int n3;
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(poly1[0][i]==poly2[0][j])
		{
			if(poly1[1][i]+poly2[1][j]==0)
			i++,j++;
			else
			{
			poly3[1][k]=poly1[1][i]+poly2[1][j];
			poly3[0][k]=poly1[0][i];
			i++;
			j++;
			k++;
		}
		}
		else if(poly1[0][i]>poly2[0][j])
		{
			poly3[0][k]=poly1[0][i];
			poly3[1][k]=poly1[1][i];
			i++;
			k++;
		}
		else
		{
			poly3[0][k]=poly2[0][j];
			poly3[1][k]=poly2[1][j];
			j++;
			k++;
		}	
	}
	while(i<n1)
	{
		poly3[0][k]=poly1[0][i];
		poly3[1][k]=poly1[1][i];
		i++;
		k++;	
	}
	while(j<n2)
	{
		poly3[0][k]=poly2[0][j];
		poly3[1][k]=poly2[1][j];
		j++;
		k++;
	}
	n3=k;
	return n3;	
}
void printpoly(int poly[2][200],int n3)
{
	printf("final polynomial=");
	for(int i=0;i<n3;i++)
	{
		if(poly[1][i]!=0)
		{
			if(i<(n3-1))
			{
			    printf("(%d)x^%d+",poly[1][i],poly[0][i]);
			}
			else
			{
				if(poly[0][i]!=0)
			    printf("(%d)x^%d",poly[1][i],poly[0][i]);
			    else
			    printf("(%d)",poly[1][i]);
			}	    
		}
	}
}
int main()
{
	int poly1[2][200],poly2[2][200],poly3[2][200],n1,n2,n3;
	 printf("enter info for first polynomial\n");
	n1=getpoly(poly1);
	 printf("\n");
    printf("enter info for second polynomial\n");
	n2=getpoly(poly2);
	printf("\n");
	n3=addpoly(poly1,poly2,poly3,n1,n2);
	 printf("The Resultant polynomial:-");
	printpoly(poly3,n3);
}
