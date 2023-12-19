#include "sort.h"

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;


	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap_heap(&array[0], &array[i], size, array);
		sift_down(array, 0, i - 1, size);

	}
}
/**
 * sift_down - Performs sift-down operation in the heap and prints the array.
 *
 * @arr: Array to perform sift-down on.
 * @start: Starting index of the heap.
 * @end: Ending index of the heap.
 * @size: Size of the array.
 */
void sift_down(int arr[], size_t start, size_t end, size_t size)
{
	size_t root = start;

	while (2 * root + 1 <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap_index = root;

		if (arr[swap_index] < arr[child])
			swap_index = child;

		if (child + 1 <= end && arr[swap_index] < arr[child + 1])
			swap_index = child + 1;

		if (root != swap_index)
		{
			swap_heap(&arr[root], &arr[swap_index], size, arr);
			root = swap_index;
		}
		else
		{
			break;
		}
	}
}


/**
 * swap_heap - Swaps the position of two elements and prints the array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 * @size: Size of the array.
 * @array: Pointer to the array.
 */
void swap_heap(int *a, int *b, size_t size, int *array)
{
	int temp = *a;

	*a = *b;
	*b = temp;

	print_array(array, size);
}
