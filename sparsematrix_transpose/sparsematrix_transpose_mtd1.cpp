 #include<stdio.h>
 typedef struct sparsemat
 {
 	int row;
 	int col;
 	int val;
 };
 sparsemat spmat1[100],spmatA[100],spmatB[100];
 void getmatrix(sparsemat spmat1[100])
 {
 	 int i;
     printf("enter total no of non zero values: ");
     scanf("%d",&spmat1[0].val);
     printf("enter total no of rows: ");
     scanf("%d",&spmat1[0].row);
     printf("enter total no of columns: ");
     scanf("%d",&spmat1[0].col);
     for(i=1;i<=spmat1[0].val;i++)
	   {
		    printf("enter row index no.: ");
		    scanf("%d",&spmat1[i].row);
		    printf("enter column index no.: ");
		    scanf("%d",&spmat1[i].col);
		    printf("enter value: ");
		    scanf("%d",&spmat1[i].val);
	   }
 }
 void transposemat(sparsemat spmatA[100],sparsemat spmatB[100])
 {
 	spmatB[0].row=spmatA[0].col;
 	spmatB[0].col=spmatA[0].row;
 	spmatB[0].val=spmatA[0].val;
 	int i,j,k=1;
 	for(i=0;i<spmatA[0].col;i++)
 	{
 	    for(j=1;j<=spmatA[0].val;j++)
 	    {
 		     if(spmatA[j].col==i)
 		     {
 			    spmatB[k].row=spmatA[j].col;
 			    spmatB[k].col=spmatA[j].row;
 			    spmatB[k].val=spmatA[j].val;
 			    k++;
		     }
	    }   
    }
 }
 void printspmat(sparsemat spmat1[100])
{
	int i,j,k=1;
	for(i=0;i<spmat1[0].row;i++)
	{
		for(j=0;j<spmat1[0].col;j++)
		{
			if(spmat1[k].col==j && spmat1[k].row==i)
			{
				printf("%2d ",spmat1[k].val);
				k++;
			}
			else
				printf(" 0 ");
		}
		printf("\n");
	}	
}

 int main()
 {
 	struct sparsemat spmatA[100],spmatB[100];
 	getmatrix(spmatA);
 	transposemat(spmatA,spmatB);
    printf("Original Matrix:-\n");
    printspmat(spmatA);
    printf("\n");
 	printf("transpose:- \n");
 	printspmat(spmatB);
 }
 
 
 
 
 
 
 
