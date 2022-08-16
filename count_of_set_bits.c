// C++ program to implement simple approach to sort
// an array according to count of set bits.
#include <stdio.h>
int countBits(int a)
{
	int count = 0;
	while (a)
	{
		if (a & 1 )
			count+= 1;
		a = a>>1;
	}
	return count;
}

void swap(int* a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[],int aux[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(aux[i]<aux[j]){
                swap(&aux[i],&aux[j]);
                swap(&arr[i],&arr[j]);
            }
        }
    }
}

void insertionSort(int arr[],int aux[], int n)
{
	for (int i = 1; i < n; i++)
	{
		// use 2 keys because we need to sort both
		// arrays simultaneously
		int key1 = aux[i];
		int key2 = arr[i];
		int j = i-1;

		/* Move elements of arr[0..i-1] and aux[0..i-1],
		such that elements of aux[0..i-1] are
		greater than key1, to one position ahead
		of their current position */
		while (j >= 0 && aux[j] < key1)
		{
			aux[j+1] = aux[j];
			arr[j+1] = arr[j];
			j = j-1;
		}
		aux[j+1] = key1;
		arr[j+1] = key2;
	}
}

// Function to sort according to bit count using
// an auxiliary array
void sortBySetBitCount(int arr[],int n)
{
	// Create an array and store count of
	// set bits in it.
	int aux[n];
	for (int i=0; i<n; i++)
		aux[i] = countBits(arr[i]);

	// Sort arr[] according to values in aux[]
	bubbleSort(arr, aux, n);
}

// Utility function to print an array
void printArr(int arr[], int n)
{
	for (int i=0; i<n; i++)
		printf("%d ",arr[i]);
}

// Driver Code
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	sortBySetBitCount(arr, n);
	printArr(arr, n);
	return 0;
}
