#include "sort.h"
/**
 * swap - swaps the position of two elements.
 * @a: pointer to the first element.
 * @b: pointer to the second element.
 * Return: None.
 */
void swap(int *a, int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - builds a max heap and maintains heap property.
 * @arr: array to be heapified.
 * @N: size of the heap.
 * @i: index to start heapify.
 * @size: size of the array.
 * Return: None.
 */
void heapify(int arr[], int N, int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < N && arr[left] > arr[largest])
		largest = left;

	if (right < N && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{

		swap(&arr[i], &arr[largest]);
		if (1)
		{
			print_array(arr, size);
		}
		heapify(arr, N, largest, size);
	}
}
/**
 * heap_sort - sorts an array using the heap sort algorithm.
 *
 * @array: array to be sorted.
 * @size: size of the array.
 * Return: None.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{

		heapify(array, size, i, size);
	}
	for (i = size - 1; i >= 0; i--)
	{

		swap(&array[0], &array[i]);
		print_array(array, size);

		heapify(array, i, 0, size);
	}
}
