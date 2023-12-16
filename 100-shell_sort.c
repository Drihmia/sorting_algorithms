#include "sort.h"

/**
  * shell_sort - a function that sorts an array of integers in ascending order
  * using the Shell sort algorithm, using the Knuth sequence.
  * @array: array of integers to be sorted.
  * @size: the size of the array.
  * Return: None.
  */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	printf("gap %lu\n", gap);
	while (gap > 0)
	{
		for (i = 0; i < (size - gap); i++)
		{
			if (array[i] > array[i + gap])
			{
				swap(&array[i], &array[i + gap]);
			}
		}
		for (; i >= gap; i--)
		{
			if (array[i - gap] > array[i])
			{
				swap(&array[i], &array[i - gap]);
			}
		}
		gap /= 3;
		print_array(array, size);
	}
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
