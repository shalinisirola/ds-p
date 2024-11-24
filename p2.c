#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

void push(char s[100], int *top, char item){
	*top = *top + 1;
	s[*top]=item;
}


int pop(char s[100], int *top){
	int item;
	item = s[*top];
	*top = *top - 1;
	return item;
}


int IPV( char ch){
	if(ch == '+' || ch == '-') return 1;
	if(ch == '*' || ch == '/') return 3;
	if(ch == '(') return 9;
	if(ch == ')') return 0;
	if(ch == '^') return 6;
	return 7;
}


int SPV( char ch){
	if(ch == '+' || ch == '-') return 2;
	if(ch == '*' || ch == '/') return 4;
	if(ch == '(') return 0;
	if(ch == '^') return 5;
	if(ch == '#') return -1;
	return 8;
}

int main(){
	char infix[100],post[100],s[100],ch;
	int i,j=0,top= -1;

	printf(" Enter the valid infix expression \n");
	scanf("%s",infix);

	push(s,&top, '#');

	for(i=0;i<strlen(infix);i++)
	{
		ch = infix[i];
		while(IPV(ch) < SPV(s[top]) ){
			post[j++] = pop(s, &top);
		}
		    
		if(IPV(ch) > SPV(s[top]) ){
			push(s, &top, ch);
		}
		else{
		    pop(s, &top);
		}
	}
	while(s[top] != '#'){
		post[j++] = pop(s, &top);
	}
	post[j] = '\0';
	printf(" The Converted postfix expression is %s \n", post);
}






