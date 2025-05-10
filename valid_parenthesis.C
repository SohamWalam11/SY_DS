#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 1000

int isValid(char s[]) {
    char stack[MAX];
    char topChar;
    int top = -1;
    int i;

    for(i = 0; s[i] != '\0'; i++) {
	char c = s[i];

	// Push opening brackets
	if(c == '(' || c == '{' || c == '[') {
	    stack[++top] = c;
	}
	// Check for matching closing brackets
	else {
	    if(top == -1)
		return 0;

	    topChar = stack[top--];

            if((c == ')' && topChar != '(') ||
               (c == '}' && topChar != '{') ||
               (c == ']' && topChar != '['))
                return 0;
        }
    }

    // If stack is empty at the end, it's valid
    return top == -1;
}

void main() {
    char s[MAX];

    clrscr();

    printf("Enter a bracket string: ");
    scanf("%s", s);

    if(isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    getch();
}
