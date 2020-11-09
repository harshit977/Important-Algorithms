#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
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
void push(char var)
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
char pop()
{
	char var;
	if(!(is_stackempty()))
	{
		var=stack[top];
		top--;
		return var;
	}
	else
	return -100; 
}
int priority(char a)
{
	if(a=='+'||a=='-')
	return 1;
	else if(a=='*'||a=='/')
	return 2;
	else if(a=='(')
	return 0;
}

void infix_to_postfix(char infix[],char postfix[])
{
	int i=0,j=0;
	int len;
	len=strlen(infix);
	while(i<len)
	{
		if(isalpha(infix[i]))
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='(')
		{
		    push(infix[i]);   	
		}
		else if(infix[i]==')')
		{
	       int var;
	       var=pop();
	       while(var !='(')
	       {
	       	postfix[j++]=var;
	       	var=pop();
		   }
		}
		else
		{
			 if(priority(infix[i])>priority(stack[top] || top==-1))
		        {
		    	push(infix[i]);
		    	}
			 else
			 {
		    	while(priority(stack[top])>=priority(infix[i]))
			    {
				    postfix[j++]=pop();
			    }
			    push(infix[i]);
		     }
		}
		i++;
    }
    while(top>=0)
    postfix[j++]=pop();
    //postfix[j]='\0';
}
int main()
{
	char infix[100];
	char postfix[100];
	printf("enter infix expresion:- ");
	scanf("%s",infix);
	printf("\n");
	infix_to_postfix(infix,postfix);
	printf("the equivalent postfix expression= ");
	printf("%s",postfix);
}


