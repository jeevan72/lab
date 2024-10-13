// Queue and its operations

#include<stdio.h>
#include<stdlib.h>

int rear = -1;
int front = 0;
int max;
int count = 0;
int *q;

void enqueue();
void dequeue();
void display();

void main() {
    int i, ele, choice;

    printf("Enter max queue size: ");
    scanf("%d", &max);

    q = (int *) malloc (sizeof(int) * max);

    while(1) {
        printf("\nEnter your choice: \n1: Enqueue\t2: Dequeue\t3: Display\t4: Exit");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: enqueue(); break;

            case 2: dequeue(); break;

            case 3: display(); break;

            case 4: free(q); exit(0);

            default: printf("Invalid input");
        }
    }
}

void enqueue() {
    int ele;

    if(count == max)
        printf("Queue Overflow");

    else {
    printf("\nEnter element to be inserted: ");
    scanf("%d", &ele);

    rear = (rear + 1) % max;
    q[rear] = ele;
    count++;
    }
}

void dequeue() {
    int ele;

    if(count == 0) {
        printf("Queue Underflow");
    }
    else {
        ele = q[front];
        
        front = (front + 1) % max;
        count--;

        printf("\nDeleted element is: %d", ele);
    }
}

void display() {
    int i, k;

    if(count == 0) {
        printf("Queue is empty");
    }
    else {
        printf("\nThe Queue elements are: \n");
        k = front;

        for(i = 0; i < count; i++) {
            printf("%d\t", q[k]);
            k = (k + 1) % max;
        }
    }
}