// Stacks and its operations

#include<stdio.h>
#include<stdlib.h>

int max, *a, top = -1;

void push(int ele);
int pop();
void display();

void main() {
    int choice, ele;

    printf("Enter the size of the stacks: ");
    scanf("%d", &max);

    a = (int *) malloc (sizeof(int) * max);

    while(1) {
        printf("\nEnter your choice: ");
        printf("\n1: Push\t2: Pop\t3: Display\t4: Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter the element to insert: "); scanf("%d", &ele); push(ele); break;

            case 2: ele = pop(); if(ele == -99) printf("Deleted element is: %d", ele); break; 

            case 3: display(); break;

            case 4: free(a); exit(0);

            default: printf("Invalid input");
        }
    }
}

void push(int ele) {
    if(top == max-1) {
        printf("Stack Overflow");
        printf("\tDoubling the size...");
        a = realloc(a, 2 * max * sizeof(int));
    }

    top++;
    a[top] = ele;
}

int pop() {
    int ele;
    if(top == -1) {
        printf("Stack Underflow");
        return -99;
    }

    else {
        ele = a[top];
        top--;

        return ele;
    }
}

void display() {
    int i;
    if(top == -1) {
        printf("Stack Underflow");
    }

    else {
        printf("\nThe Stack elements are: \n");
        for(i = top; i >= 0; i--) {
            printf("%d", a[i]);
        }
    }
}