#include <stdlib.h>
#include <stdio.h>

void bubblesort(int *data, int n, int *swaptr);
void selectionSort(int *arr, int n, int *swaptr);
void swap(int *a, int *b, int *swaptr);
void printarray(int *arr, int n);
void printcountarray(int *arr, int*originalarr, int n);

int main(void)
{
    int array1A[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2A[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array1B[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2B[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arrayofcounts1A[98] = {0};
    int arrayofcounts1B[98] = {0};
    int arrayofcounts2A[91] = {0};
    int arrayofcounts2B[91] = {0};

    printf("Bubble Sort Array 1\n");
    bubblesort(array1A, 9, arrayofcounts1A);
    // printarray(array1A, 9);
    printcountarray(arrayofcounts1A, array1A, 9);

    printf("Bubble Sort Array 2\n");
    bubblesort(array2A, 9, arrayofcounts2A);
    // printarray(array2A, 9);
    printcountarray(arrayofcounts2A, array2A, 9);

    printf("Selection Sort Array 1\n");
    selectionSort(array1B, 9, arrayofcounts1B);
    // printarray(array1B, 9);
    printcountarray(arrayofcounts1B, array1B, 9);

    printf("Selection Sort Array 1\n");
    selectionSort(array2B, 9, arrayofcounts2B);
    // printarray(array2B, 9);
    printcountarray(arrayofcounts2B, array2B, 9);
}

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void printcountarray(int *arr, int*orr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
            printf("%d: %d\n", orr[i], arr[orr[i]]);
            total = total + arr[orr[i]];
    }
    printf("%d\n", total/2);
}


void bubblesort(int *data, int n, int *swaptr)
{
    int i, j;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (data[j] > data[j + 1])
                swap(&data[j], &data[j + 1], swaptr);
        }
    }
}

void selectionSort(int *arr, int n, int *swaptr)
{
    int i, j, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i == min)
            continue;
        swap(&arr[i], &arr[min], swaptr);
    }
}

void swap(int *a, int *b, int *swaptr)
{
    swaptr[*a] = swaptr[*a] + 1;
    swaptr[*b] = swaptr[*b] + 1;
    int temp = *a;
    *a = *b;
    *b = temp;
}