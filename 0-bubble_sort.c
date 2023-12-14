#include "sort.h"

/**
  * bubble_sort - a function that sorts an array of integers in ascending order
  * using the Bubble sort algorithm.
  * @array: array ok integers.
  * @size: the size of the array.
  * Return: void.
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int sort, hold = 0;

	for (i = 0; i < size; i++)
	{
		sort = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				hold = array[j + 1];
				array[j + 1] = array[j];
				array[j] = hold;
				sort = 1;
				print_array(array, size);
			}
		}
		if (!sort)
			break;
	}

}
