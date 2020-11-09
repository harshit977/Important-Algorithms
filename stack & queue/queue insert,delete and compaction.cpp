#include<stdio.h>
#define MAX 3
int queue[MAX];
int front=-1;
int rear=-1;
int is_full()
{
	if(rear>=MAX-1)
	return 1;
	else
	return 0;
}
int is_empty()
{
	if(rear<=front)
	return 1;
	else
	return 0;
}
void insert(int var)
{
	if(!is_full())
	{
	rear++;
	queue[rear]=var;
	printf("insertion successfull");
	printf("\n");
   }
   else
   printf("overflow");
   printf("\n");
}
int _delete()
{
	int var;
	if(!is_empty())
	{
		front++;
		return queue[front];
   }
   else
   return -100;
}
 void compact()
 {
 	if(front>=0 && front<=rear)
 	 {
 	 	int i=0;
 	 	int j=front;
 	while(i<(rear-front))
 	{
 	 queue[i]=queue[j+1];
 	 i++;
 	 j++;
	 }
    front=-1;
    rear=i-1;
    printf("compaction performed\n\n");
}
 }
 int main()
{
	while(1>0)
	{
	int val;
	int x;
	printf("select the operation to be performed:- ");
	printf("\n\n");
	printf("press 1 for insert operation :\npress 2 for delete operation : ");
	scanf("%d",&x);
	printf("\n");
	switch(x)
	{
		case 1:
			{
				int var;
				printf("enter element to be inserted in queue:-  ");
				scanf("%d",&var);
				printf("\n");
	        	insert(var);
	        }
         	break;
        case 2:
        	{
        		int var;
        		var=_delete();
        		printf("the deleted element= %d\n",var);
			}
			break;
		default:printf("invalid input\n");
		break;
	}
	printf("press 1 to enter again:\npress 0 to exit:\npress 2 for compaction: ");
	scanf("%d",&val);
	if(val==2)
	compact();
	if(val==0)
	break;
    }
    return 0;
}
