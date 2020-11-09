#include<stdio.h>
#include<string.h>
#include<ctype.h>
void validate_infix(char infix[])
{
	int i=0;
	int count=0;
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')      //bracket balance
		{
			int p;
			p=i;
			while(infix[p]!=')' && infix[p]!='\0' )
			{
				p++;
			}
			if(infix[p]=='\0')
			count++;
		}
		 if(isalpha(infix[i]) && isalpha(infix[i+1]))
		{
            count++;   
		}
		 if((infix[i]>=42 && infix[i]<=47) && (infix[i+1]>=42 && infix[i+1]<=47) )
		{
		count++;
		}
		if(isalpha(infix[i]) && infix[i+1]=='(')
		{
			count++;
		}
		if((infix[i]=='(') && (infix[i+1]>=42 && infix[i+1]<=47) )
		{
			count++;
		}
		if((infix[i]>=42 && infix[i]<=47) && infix[i+1]==')')
		{
			count++;
		}
		if(infix[i]==')' && isalpha(infix[i+1]))
		{
			count++;
		}
		 if(infix[i]==')' && infix[i+1]=='(')
		{
			count++;
		}
		i++;
	}
	if(count>0)
	{
		printf("invalid infix expression");
	}
	else
	{
		printf("valid infix expression");
	}
}
int main()
{
	char infix[100];
	printf("enter infix expression: ");
	gets(infix);
	printf("\n");
	validate_infix(infix);
	
}

