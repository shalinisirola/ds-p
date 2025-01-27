#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

void push(int s[10], int *top, int item)
{
	*top = *top + 1;
	s[*top]=item;
}
	
int pop(int s[10], int *top)
{
	int item;
	item = s[*top];
	*top = *top - 1;
	return item;

}

 
int main()
{
	char post[20],ch;
	int i,a,b,res,top= -1,s[20];
	printf(" Enter the valid numerical postfix expression \n");
	scanf("%s",post);

	for(i=0;i<strlen(post);i++)
	{
		ch=post[i];
		if(isdigit(ch)){
			push(s, &top, ch-'0');
		}
		else
		{
		    b = pop(s,&top);
		    a = pop(s,&top);

		    if( ch == '+' ) res = a + b;
		    if( ch == '-' ) res = a - b;
		    if( ch == '*' ) res = a * b;
		    if( ch == '/' ) res = a / b;
                    if( ch == '%' ) res = a % b;
                    if( ch == '^' ) res = pow(a,b);
		    push(s, &top, res);
		}
	}
	printf(" The evaluated value of expression is %d \n", res);
}


