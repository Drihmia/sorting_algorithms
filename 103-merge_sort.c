#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * merge - merges two subarrays into a single sorted array
 * and prints the steps.
 * @array: original array containing the merged result.
 * @left: pointer to the left subarray.
 * @l_size: size of the left subarray.
 * @right: pointer to the right subarray.
 * @r_size: size of the right subarray.
 */
void merge(int *array, int *left, size_t l_size, int *right, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: "), print_array(left, l_size);

	printf("[right]: "), print_array(right, r_size);

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < l_size)
		array[k++] = left[i++];

	while (j < r_size)
		array[k++] = right[j++];

	printf("[Done]: "), print_array(array, k);
}

/**
 * merge_sort - sorts an array using the merge sort algorithm
 * and prints the steps.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2, i, j = 0;
		int *left, *right;

		left = malloc(mid * (sizeof(int)));
		if (!left)
			return;
		right = malloc(mid * (sizeof(int)));
		if (!right)
		{
			free(left);
			return;
		}
		for (i = 0; i < size; i++)
		{
			if (i < mid)
				left[i] = array[i];
			else
				right[j] = array[i], j++;
		}


		merge_sort(left, mid);
		merge_sort(right, size - mid);

		merge(array, left, mid, right, size - mid);
	}
}
