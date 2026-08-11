#include <stdio.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int size;
} Heap;

typedef struct {
    Heap maxHeap;
    Heap minHeap;
} MedianFinder;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxPush(Heap *h, int value)
{
    int i = h->size++;
    h->data[i] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (h->data[parent] >= h->data[i])
            break;

        swap(&h->data[parent], &h->data[i]);
        i = parent;
    }
}

void minPush(Heap *h, int value)
{
    int i = h->size++;
    h->data[i] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (h->data[parent] <= h->data[i])
            break;

        swap(&h->data[parent], &h->data[i]);
        i = parent;
    }
}

int maxPop(Heap *h)
{
    int result = h->data[0];
    h->data[0] = h->data[--h->size];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < h->size && h->data[left] > h->data[largest])
            largest = left;

        if (right < h->size && h->data[right] > h->data[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&h->data[i], &h->data[largest]);
        i = largest;
    }

    return result;
}

int minPop(Heap *h)
{
    int result = h->data[0];
    h->data[0] = h->data[--h->size];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < h->size && h->data[left] < h->data[smallest])
            smallest = left;

        if (right < h->size && h->data[right] < h->data[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }

    return result;
}

void insert(MedianFinder *mf, int num)
{
    if (mf->maxHeap.size == 0 || num <= mf->maxHeap.data[0])
        maxPush(&mf->maxHeap, num);
    else
        minPush(&mf->minHeap, num);

    if (mf->maxHeap.size > mf->minHeap.size + 1)
    {
        int value = maxPop(&mf->maxHeap);
        minPush(&mf->minHeap, value);
    }
    else if (mf->minHeap.size > mf->maxHeap.size + 1)
    {
        int value = minPop(&mf->minHeap);
        maxPush(&mf->maxHeap, value);
    }
}

float getMedian(MedianFinder *mf)
{
    if (mf->maxHeap.size == 0 && mf->minHeap.size == 0)
        return 0.0f;

    if (mf->maxHeap.size == mf->minHeap.size)
        return (mf->maxHeap.data[0] + mf->minHeap.data[0]) / 2.0f;

    if (mf->maxHeap.size > mf->minHeap.size)
        return mf->maxHeap.data[0];

    return mf->minHeap.data[0];
}

int main()
{
    MedianFinder mf = {0};

    insert(&mf, 5);
    insert(&mf, 2);
    insert(&mf, 10);
    insert(&mf, 4);
    insert(&mf, 7);

    printf("%.2f\n", getMedian(&mf));

    return 0;
}
