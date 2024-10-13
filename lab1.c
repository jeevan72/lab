// Selection sort with dynamic memory allocation

#include<stdio.h>
#include<stdlib.h>

void selectionsort(int a[], int n) {
    int i, j, temp, pos;

    for(i = 0; i < n; i++) {
        pos = i;

        for(j = i+1; j < n; j++) {

            if(a[j] < a[pos]) {
                pos = j;
            }

            if(i != pos) {
                temp = a[i];
                a[i] = a[pos];
                a[pos] = temp;
            }
        }
    }
}

void main() {
    int i, n, *a;

    printf("Enter the array size: ");
    scanf("%d", &n);

    a = (int *) malloc (sizeof(int) * n);

    printf("\nEnter the array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionsort(a, n);

    printf("\nThe sorted array is: ");
    for(i = 0; i < n; i++) 
        printf("%d\n", a[i]);
}