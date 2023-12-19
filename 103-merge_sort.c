#include "sort.h"

/**
 * merge - merges two subarrays into a single sorted array
 * and prints the steps.
 * @array: original array containing the merged result.
 * @arr: pointer to the malloc'd array.
 * @l_idx: size of the left subarray.
 * @h_idx: size of the left subarray.
 * @mid: size of the left subarray.
 * @size: size of the right subarray.
 */
void merge(int *array, size_t l_idx, size_t mid,
		size_t h_idx, size_t size, int *arr)
{
	size_t i = l_idx, j = mid + 1, k = l_idx;

	(void) size;
	printf("Merging...\n[left]: ");
	print_array(arr + l_idx, mid - l_idx + 1);

	printf("[right]: "), print_array(arr + mid + 1, h_idx - mid);

	while (i <= mid && j <= h_idx)
	{
		if (arr[i] <= arr[j])
			array[k++] = arr[i++];
		else
			array[k++] = arr[j++];
	}

	while (i <= mid)
		array[k++] = arr[i++];

	while (j <= h_idx)
		array[k++] = arr[j++], printf("%d\n", array[k - 1]);


	printf("[Done]: "), print_array(array + l_idx, k - l_idx);
}

/**
 * merge_split - sorts an array using the merge sort algorithm
 * and prints the steps.
 * @array: original array containing the merged result.
 * @arr: pointer to the malloc'd array.
 * @l_idx: size of the left subarray.
 * @h_idx: size of the left subarray.
 * @size: size of the right subarray.
 */
void merge_split(int *array, size_t l_idx, size_t h_idx, size_t size, int *arr)
{
	size_t mid, i;

	if ((h_idx - l_idx) > 0)
	{
		mid = (h_idx + l_idx + 1) / 2;

		merge_split(array, l_idx, mid - 1, size, arr);
		merge_split(array, mid, h_idx, size, arr);

		merge(array, l_idx, mid - 1, h_idx, size, arr);
		for (i = l_idx; i <= h_idx; i++)
			arr[i] = array[i];
	}
}
/**
 * merge_sort - sorts an array using the merge sort algorithm
 * and prints the steps.
 * @array: original array containing the merged result.
 * @size: size of the right subarray.
 */
void merge_sort(int *array, size_t size)
{
	int *arr;
	size_t i;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return;

	for (i = 0; i < size; i++)
		arr[i] = array[i];

	/* i m passing an index's value and not actual size */
	merge_split(array, 0, size - 1, size, arr);
	for (i = 0; i < size; i++)
		array[i] = arr[i];
	free(arr);
}
