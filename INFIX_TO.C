#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void infix_to_postfix(char exp[]);
void push_stack(char c);
char pop_stack();

void infix_to_postfix(char exp[]){

	int i;
	char ch;
	char postfix[MAX] = "";
	char temp[2];
	temp[1] = '\0';


	//loop through each char in the string
	for(i=0; exp[i] != '\0'; i++){

		// If char is an operand (not operator or bracket), add to postfix
		if(exp[i] != '+' && exp[i] != '-' && exp[i] != '/' && exp[i] != '*' && exp[i] != '(' && exp[i] != ')'){
			temp[0] = exp[i];
			strcat(postfix, temp);
		}
		else {
			if(exp[i] == '('){
				push_stack(exp[i]);
			}
			else if(exp[i] == ')'){
				while((ch = pop_stack()) != '('){
					temp[0] = ch;
					strcat(postfix, temp);
				}
			}
			else {
				// If it's an operator
				while(top != -1 && stack[top] != '(' && (
					(stack[top] == '*' || stack[top] == '/') || 
					((exp[i] == '+' || exp[i] == '-') && (stack[top] == '+' || stack[top] == '-'))
				)){
					ch = pop_stack();
					temp[0] = ch;
					strcat(postfix, temp);
				}
				push_stack(exp[i]);
			}
		}
	}

	// Pop remaining operators
	while(top != -1){
		ch = pop_stack();
		temp[0] = ch;
		strcat(postfix, temp);
	}

	printf("\nPostfix expression = %s", postfix);
}

void push_stack(char c){
	if(top >= MAX-1){
		printf("\nstack overflow");
	}else{
	top = top + 1;
	stack[top] = c;
	}

}

char pop_stack(){
	if(top == -1){
		printf("\nstack underflow");
		return '\0'; // return null char on underflow
	}
	else{
		return stack[top--];
	}
}


void main(){
	char exp[MAX];

	clrscr();

	printf("Enter expression: ");
	scanf("%s", exp );

	infix_to_postfix(exp);
	getch();
}