// Infix to Postfix to Infix to Numbers👍

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

char istack[20];
float stack[20];
int tos = -1;
int top = -1;

void ipush(char s)
{
    tos++;
    istack[tos] = s;
}
void push(float ele)
{
    top++;
    stack[top] = ele;
}

char ipop() {
    // int ele = istack[tos];
    // tos--;
    return istack[tos--];
}
float pop() {
    // float ele = stack[top];
    // top--;
    return stack[top--];
}

int precd(char s) {
    switch(s) {
        case '^': return 4;

        case '*': 
        case '/': 
        case '%': return 3;

        case '+':
        case '-': return 2;

        case '(':
        case ')':
        case '#': return 1;
    }

    return 0;
}

void convertip(char infix[20], char postfix[20]) {
    int i, j = 0;
    char symbol;
    ipush('#');

    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        switch (symbol)
        {
        case '(': ipush(symbol);
            break;

        case ')':
            while(istack[tos] != '(')
                postfix[j++] = ipop();
                
                ipop();
                break;

        case '^':
        case '*':
        case '/':
        case '%':
        case '+':
        case '-':
            while(precd(symbol) <= precd(istack[tos]))
            postfix[j++] = ipop();

            ipush(symbol);
            break;
        
        default: postfix[j++] = symbol;
        }
    }

    while(istack[tos] != '#')
    postfix[j++] = ipop();

    postfix[j] = '\0';
}

void evaluate(char postfix[50]) {
    int i;
    char symbol;

    float op1, op2, result, x;

    for(i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];

        if(isalpha(symbol)) {
            printf("Enter the value for %c: \t", symbol);
            scanf("%f", &x);
            push(x);
        }

        else {
            op2 = pop();
            op1 = pop();

            switch(symbol) {
                case '+':
                push(op1+op2); break;

                case '-': 
                push(op1-op2); break;

                case '*':
                push(op1*op2); break;

                case '/': 
                push(op1/op2); break;

                case '%':
                push((int)op1/(int)op2); break;

                case '^':
                push(pow(op1, op2)); break;

                default: printf("Invalid postfix expression.");
                exit(0);
            }
        }
    }

    result = pop();
    printf("The result is: %f", result);
}

void main() {
    char infix[20], postfix[20];

    printf("Enter infix expression: ");
    gets(infix);

    convertip(infix, postfix);
    printf("Postfix expression is: %s", postfix);

    evaluate(postfix);
}