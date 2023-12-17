#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;


	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = 0; i < (size - gap); i++)
		{
			if (array[i] > array[i + gap])
			{
				swap(&array[i], &array[i + gap]);
				j = i;
				while (j >= gap)
				{
					if (array[j - gap] > array[j])
					{
						swap(&array[j], &array[j - gap]);
						j = j - gap;
					}
					else
						break;
				}
			}
		}
		gap /= 3;
		print_array(array, size);
	}
}

/**
 * swap - Swaps two integers in an array.
 * @i: Address of integer i.
 * @j: Address of integer j.
 */
void swap(int *i, int *j)
{
	int tmp = *i;

	*i = *j;
	*j = tmp;
}


