#include<stdio.h>

int partition(int a[], int l, int h) {
    int pivot = a[l];
    int i = l, j = h;
    int temp;

    while (i < j) {
        while (a[i] <= pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[], int l, int h) {
    if (l < h) {
        int j = partition(a, l, h);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, h);
    }
}

int main() {
    int i, n, l, h;
    printf("Enter any number: ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    l = 0;
    h = n - 1;
    quicksort(a, l, h);
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    return 0;
}
