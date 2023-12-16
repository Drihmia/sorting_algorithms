#include "sort.h"
void quicksort(int *arr, int low_index, int high_index, size_t size);
void swap(int *i, int *j);
int partition(int *arr, int low_index, int high_index, size_t size);

/**
 * quick_sort - a function that sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: array of integers to be sorted.
 * @size: the size of the array.
 * Return: None.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

/**
  * quicksort - a recursive quick sorting funtion.
  * @arr: array to be sorted.
  * @l: the lowest index (leftmost).
  * @r: the higher index (rightmost).
  * @size: the size of the array for print_array funtion.
  * Return: None.
  */
void quicksort(int *arr, int low_index, int high_index, size_t size)
{
	if (low_index >= high_index || size < 2)
		return;

	int i = partition(arr, low_index, high_index, size);

	quicksort(arr, low_index, i - 1, size);
	quicksort(arr, i + 1, high_index, size);
}
/**
  * partition - a funtion that partition the array given.
  * @arr: array to be partitioned.
  * @l: the lowest index (leftmost).
  * @r: the higher index (rightmost).
  * @size: the size of the array for print_array funtion.
  * Return: the new pivot positin.
  */

int partition(int *arr, int low_index, int high_index, size_t size)
{
	int pivot = arr[high_index];
	int i = low_index;

	for (int j = low_index; j < high_index; ++j)
	{
		if (arr[j] < pivot)
		{
			if ( arr[j]!= arr[i])
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			++i;
		}
	}
	if (arr[i] != arr[high_index])
	{
		swap(&arr[i], &arr[high_index]);
		print_array(arr, size);
	}
	return (i);
}

/**
 * swap - a function the spaw two integer's postion in an array.
 * @i: address of integer i.
 * @j: address of integer j.
  * Return: None.
  */
void swap(int *i, int *j)
{
	int tmp = *i;

	*i = *j;
	*j = tmp;
}
