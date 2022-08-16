#include <stdio.h>
#define size 7

int arr[size]; //[1,2,9865456798,34942]

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int n, int i)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(n, largest);
    }
}

void read_array()
{
    printf("Enter %d array elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void print_array()
{
    printf("Array elements are ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void build_heap()
{
    int index = (size / 2) - 1;
    for (int i = index; i >= 0; i--)
    {
        heapify(size, i);
    }
}

void heapSort(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
}

int main()
{
    read_array();
    print_array();
    build_heap();
    print_array();
    heapSort(size);
    print_array();
}