#include<stdio.h>
typedef struct sparsemat
{
	int row;
	int col;
	int val;
};
void getmatrix(sparsemat spmatA[100])
{
	int i;
	printf("enter total no of non zero values: ");
	scanf("%d",&spmatA[0].val);
	printf("enter total no of rows: ");
	scanf("%d",&spmatA[0].row);
	printf("enter total no of columns: ");
	scanf("%d",&spmatA[0].col);
	printf("\n");
	for(i=1;i<=spmatA[0].val;i++)
	{
		printf("enter row index number: ");
		scanf("%d",&spmatA[i].row);
		printf("enter column index number: ");
		scanf("%d",&spmatA[i].col);
		printf("enter value: ");
		scanf("%d",&spmatA[i].val);
	}
}
void transposemat(sparsemat spmatA[100],sparsemat spmatB[100])
{
	spmatB[0].row=spmatA[0].col;
 	spmatB[0].col=spmatA[0].row;
 	spmatB[0].val=spmatA[0].val;
	int i;
	int j;
	int rowterms[100];
	int startingpos[100];
	for(j=0;j<spmatA[0].col;j++)
	rowterms[j]=0;
	for(i=1;i<=spmatA[0].val;i++)
	{
		rowterms[spmatA[i].col]++;
	}
	startingpos[0]=1;
	int k;
	for(k=1;k<spmatA[0].col;k++)
	startingpos[k]=startingpos[k-1]+rowterms[k-1];
	
	//transpose
	int p;
	for(p=1;p<=spmatA[0].val;p++)
	{
	    spmatB[startingpos[spmatA[p].col]].row=spmatA[p].col;
	    spmatB[startingpos[spmatA[p].col]].col=spmatA[p].row;
	    spmatB[startingpos[spmatA[p].col]].val=spmatA[p].val;
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
 	printf("\n");
 	printf("Original Matrix is:-\n");
 	printspmat(spmatA);
 	printf("transpose of given sparse matrix is:-");
 	printf("\n");
 	printspmat(spmatB);
 }
 
