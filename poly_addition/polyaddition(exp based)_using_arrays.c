#include<stdio.h>
 typedef struct term
 {
     int exp;
     int coeff;
 }term;
 term poly[100],poly1[100],poly2[100],poly3[100];
 int getpoly(term poly[100])
 {
     int n,i;
     printf("\n");
    printf("enter no of terms: ");
    scanf("%d",&n);
    printf("enter exponent and coefficient of each term: \n");
 for(i=0;i<n;i++)
{
	printf("exponent: ");
    scanf("%d",&poly[i].exp);
    printf("coefficients: ");
    scanf("%d",&poly[i].coeff);
}
  return n;
 }
 int addpoly(term poly1[100],term poly2[100],int n1,int n2,term poly3[100])
{
    int i=0,j=0,k=0,n3;
    while(i<n1 && j<n2)
    {
        if(poly1[i].exp==poly2[j].exp)
        {
            poly3[k].exp=poly1[i].exp;
            poly3[k].coeff=poly1[i].coeff+poly2[j].coeff;
            i++;
            j++;
            k++;
        }
        else if(poly1[i].exp>poly2[j].exp)
        {
            poly3[k]=poly1[i];
            k++;
            i++;
        }
        else
        {
            poly3[k]=poly2[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        poly3[k]=poly1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        poly3[k]=poly2[j];
        k++;
        j++;
    }
    n3=k;
    return n3;
}
void printpoly( term poly[100],int n)
{
	int i;
    for(i=0;i<n;i++)
    {
        if(poly[i].coeff!=0)
        {
          if(i<n-1)
            printf("(%d)x^%d + ",poly[i].coeff,poly[i].exp);
          else
            printf("(%d)x^%d",poly[i].coeff,poly[i].exp);
        }
    }
}
int main()
{
    term poly1[100],poly2[100],poly3[100];
    int n1,n2,n3;
    printf("enter info for first polynomial\n");
    n1= getpoly(poly1);
    printf("\n");
    printf("enter info for second polynomial\n");
    n2= getpoly(poly2);
    printf("\n");
    n3=addpoly(poly1,poly2,n1,n2,poly3);
    printf("The Resultant polynomial:-");
    printpoly(poly3,n3);
}
