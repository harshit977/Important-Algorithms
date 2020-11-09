#include<stdio.h>
#define MAX 100
float stack[MAX];
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
float push(float var)
{
 if(!(is_stackfull()))
 {
 	top++;
 	stack[top]=var;
 }
 else
 {
 	 printf("stack overflow\n");
 }
}
float pop()
{
	float var;
	if(!(is_stackempty()))
	{
		var=stack[top];
		top--;
		return var;
	}
	else
	return -100; 
}
float evalpostfix(char expr[])
{
	int i=0;
	while(expr[i]!='\0')
	{
		if(expr[i]>=48 && expr[i]<=57)
		{
			float f;
			f=expr[i]-'0';
			push(f);
		}
		else
		{
			int op1,op2;
			op2=pop();
			op1=pop();
			float result;
			
			switch(expr[i])
			{
				case '+':
				{
					result=op1+op2;
					push(result);
				}
				break;
				case '-':
				{
					result=op1-op2;
					push(result);
				}
				break;
				case '*':
				{
				    result=op1*op2;
					push(result);
				}
				break;
				case '/':
				{
				    result=op1/op2;
					push(result);
				}
				break;
				case '%':
				{
				    result=op1%op2;
					push(result);
				}
				break;
				default:
				{
					printf("invalid symbol");
				}
				break;
				
			}
		}
		i++;
	}
}
int main()
{
	char postexp[100];
	printf("enter postfix expression: ");
	scanf("%s",postexp);
	evalpostfix(postexp);
	printf("the value of expression is = %f",stack[top]);
}
