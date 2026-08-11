
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void generateRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (n * 10);
}

void generateAscending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void generateDescending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

int isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return 0;
    }

    return 1;
}

double measureTime(int arr[], int n)
{
    clock_t start = clock();

    heapSort(arr, n);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main()
{
    int sizes[] = {1000, 5000, 10000, 20000, 50000, 100000};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    printf("Size\tRandom\t\tAscending\tDescending\n");

    for (int i = 0; i < count; i++)
    {
        int n = sizes[i];

        int *randomArr = malloc(n * sizeof(int));
        int *ascendingArr = malloc(n * sizeof(int));
        int *descendingArr = malloc(n * sizeof(int));

        generateRandom(randomArr, n);
        generateAscending(ascendingArr, n);
        generateDescending(descendingArr, n);

        double randomTime = measureTime(randomArr, n);
        double ascendingTime = measureTime(ascendingArr, n);
        double descendingTime = measureTime(descendingArr, n);

        printf("%d\t%.6f\t%.6f\t%.6f\n",
               n, randomTime, ascendingTime, descendingTime);

        if (!isSorted(randomArr, n) ||
            !isSorted(ascendingArr, n) ||
            !isSorted(descendingArr, n))
        {
            printf("Sorting failed for n = %d\n", n);
        }

        free(randomArr);
        free(ascendingArr);
        free(descendingArr);
    }

    return 0;
}
