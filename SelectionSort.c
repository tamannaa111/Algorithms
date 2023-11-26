// C program for implementation of selection sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min;

   
    for (i = 0; i < n-1; i++) //last value emnitei sorted
    {
        
        min = i; //initially
        
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min])
            min = j;     // jokhn min er theke j er value choto hobe tkhn min==j hobe
            
        if(min != i)    //min value and i value is not same now ,,, karon min value update hoyeche
            swap(&arr[min], &arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);    //to calculate the number of elements in an array
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
