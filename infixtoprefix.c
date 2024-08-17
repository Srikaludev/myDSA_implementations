#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isOperator(char c) 
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }
    return 0;
}

int precedorder(char c)
{
    if(c == '^') {
        return 3;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

void push(char c)
{
    if(top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop()
{
    if(top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

char peek() 
{
    return stack[top];
}

void reversestring(char *str) 
{
    int i, j;
    char temp;
    for(i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    int i, j;
    char c, temp[MAX_SIZE];
    reversestring(infix);
    for(i = 0, j = 0; infix[i] != '\0'; i++) {
        if(isOperator(infix[i])) {
            while(top != -1 && precedorder(peek()) >= precedorder(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        } else if(infix[i] == ')') {
            push(infix[i]);
        } else if(infix[i] == '(') {
            while((c = pop()) != ')') {
                prefix[j++] = c;
            }
        } else {
            prefix[j++] = infix[i];
        }
    }
    while(top != -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reversestring(prefix);
}

int main() 
{
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter Infix Expression: ");
    scanf("%s",infix);
    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}
