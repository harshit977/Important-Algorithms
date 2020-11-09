    #include<stdio.h>
    int getpoly(int poly[100])
    {
        int deg,i;
        printf("enter degree of polynomial");
        scanf("%d",&deg);
        printf("enter coefficients:");
        for(i=0;i<=deg;i++)
            scanf("%d",&poly[i]);
        return deg;
    }
    int addpoly(int poly1[100],int poly2[100],int deg1,int deg2,int poly3[100])
    {
        int deg3;
        int diff;
        int i,j;
        if(deg1>deg2)
     {
         diff=deg1-deg2;
         deg3=deg1;
         for(i=0;i<diff;i++)
             poly3[i]=poly1[i];
         for(j=0;j<=deg2;j++)
             poly3[diff+j]=poly1[diff+j]+poly2[j];
      }
         if(deg1<deg2)
     {
         diff=deg2-deg1;
         deg3=deg2;
         for(i=0;i<diff;i++)
             poly3[i]=poly2[i];
         for(j=0;j<=deg1;j++)
             poly3[diff+j]=poly2[diff+j]+poly1[j];
     }
     if(deg1==deg2)
     {
         int c=0;
         for(i=0;i<=deg1;i++)
             poly3[i]=poly1[i]+poly2[i];
         for(j=0;j<=deg1;j++)
         {
             if(poly3[j]!=0)
                 break;
             else
                 c++;
         }
         for(i=0;i<deg1;i++)
             poly3[i]=poly3[i+c];
             deg3=deg1-c;
     }
    return deg3;
    }
    void printpoly(int poly[100],int deg3)
       {
       	int i;
           printf("final degree=%d\n",deg3);
           printf("final polynomial=");
          for(i=0;i<=deg3;i++)
          {
              if(poly[i]!=0)
                {
                	if(i<deg3)
                    printf("(%d)x^%d+",poly[i],deg3-i);
                    else
                    printf("(%d)x^%d",poly[i],deg3-i); 
                }
          }
       }
     int main()
     {
         int poly1[100],poly2[100],poly3[100],deg1,deg2,deg3;
         printf("enter 1st poly:-\n");
         deg1=getpoly(poly1);
         printf("\nenter 2nd poly:-\n");
         deg2=getpoly(poly2);
         deg3=addpoly(poly1,poly2,deg1,deg2,poly3);
         printpoly(poly3,deg3);
 }






