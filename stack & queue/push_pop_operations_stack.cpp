#include<stdio.h>
#define MAX 3
int stack[MAX];
int top=-1;
int is_stackfull()
{
	if(top<MAX-1)
	return 0;
	else 
	return 1;
}
int is_stackempty()
{
	if(top<0)
	return 1;
	else
	return 0;
}
void push(int var)
{
 if(!(is_stackfull()))
 {
 	top++;
 	stack[top]=var;
 	printf("the element is successfully pushed into the stack!\n");
 }
 else
 {
 	 printf("stack overflow\n");
 }
}
int pop()
{
	int var;
	if(!(is_stackempty()))
	{
		var=stack[top];
		top--;
		return var;
	}
	else
	return -100; 
}
int main()
{
	while(1>0)
	{
	int val;
	int x;
	printf("select the operation to be performed:- ");
	printf("\n");
	printf("press 1 for push operation :\npress 2 for pop operation : ");
	scanf("%d",&x);
	printf("\n");
	switch(x)
	{
		case 1:
			{
				int var;
				printf("enter element to be pushed into the stack:-  ");
				scanf("%d",&var);
				printf("\n");
	        	push(var);
	        }
         	break;
        case 2:
        	{
        		int var;
        		var=pop();
        		printf("the popped element= %d\n",var);
			}
			break;
		default:printf("invalid input\n");
		break;
	}
	printf("press 1 to enter again: \n press 0 to exit");
	scanf("%d",&val);
	if(val!=1)
	break;
    }
    return 0;
}
