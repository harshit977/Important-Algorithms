#include<stdio.h>
int main()
{
    int poly1[100],poly2[100],deg1,deg2,poly3[100],deg3;
    printf("enter degree of polynomial 1:");
    scanf("%d",&deg1);
    printf("enter coefficients in decreasing order of powers of variable ");
    for(int i=0;i<=deg1;i++)
        scanf("%d",&poly1[i]);
    printf("enter degree of polynomial 2:");
    scanf("%d",&deg2);
    printf("enter coefficients in decreasing order of powers of variable ");
    for(int i=0;i<=deg2;i++)
        scanf("%d",&poly2[i]);
    if(deg1==deg2)
    {
        for(int i=0;i<=deg1;i++)
            poly3[i]=poly1[i]+poly2[i];
        deg3=deg1;
    }
    if(deg1>deg2)
    {
        int diff;
        diff=deg1-deg2;
        for(int i=0;i<diff;i++)
            poly3[i]=poly1[i];
        for(int i=0;i<=deg2;i++)
            poly3[diff+i]=poly1[diff+i]+poly2[i];
        deg3=deg1;
    }
     if(deg1<deg2)
    {
        int diff;
        diff=deg2-deg1;
        for(int i=0;i<diff;i++)
            poly3[i]=poly2[i];
        for(int i=0;i<=deg1;i++)
            poly3[diff+i]=poly2[diff+i]+poly1[i];
        deg3=deg2;
    }
    printf("final polynomial of degree % d=",deg3);
    for(int i=0;i<=deg3;i++)
    {
        printf("%dx^%d + ",poly3[i],deg3-i);
    }
    return 0;
}
