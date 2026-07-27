#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int *ans;

void countPairs(Pair arr[], int low, int mid, int high) {
    int right = mid + 1;

    for (int left = low; left <= mid; left++) {
        while (right <= high && arr[right].value < arr[left].value) {
            right++;
        }
        ans[arr[left].index] += right - (mid + 1);
    }
}

void merge(Pair arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;

    Pair *temp = (Pair *)malloc((high - low + 1) * sizeof(Pair));
    int k = 0;

    while (left <= mid && right <= high) {
        if (arr[left].value <= arr[right].value) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    while (right <= high) {
        temp[k++] = arr[right++];
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    free(temp);
}

void mergeSort(Pair arr[], int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    countPairs(arr, low, mid, high);

    merge(arr, low, mid, high);
}

int main() {
    int n;
    scanf("%d", &n);

    Pair *arr = (Pair *)malloc(n * sizeof(Pair));
    ans = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    printf("\n");

    free(arr);
    free(ans);

    return 0;
}