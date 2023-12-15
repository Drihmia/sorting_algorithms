#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * Return: None.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min = 0;
	int holder;

	if (!array || !size || size == 1)
		return;
	while (i < size)
	{
		j = i;
		min = i;
		while (j < size)
		{
			if (array[min] > array[j])
				min = j;
			j++;
		}
		if (min != i)
		{
			holder = array[min];
			array[min] = array[i];
			array[i] = holder;
			print_array(array, size);
		}
		i++;
	}
}
