#include "sort.h"

/**
  * counting_sort - a function that sorts an array of integers in ascending
  * order using the Counting sort algorithm
  * @array: array ok integers.
  * @size: the size of the array.
  * Return: void.
  */
void counting_sort(int *array, size_t size)
{
	int *count_array = NULL, *tmp_array = NULL, m_val = 0, i = 1;

	if (!array || size < 2)
		return;
	m_val = array[0];
	while (i < (signed int)size) /* searching the max value : m_val */
	{
		if (array[i] > m_val)
			m_val = array[i];
		i++;
	};
	count_array = malloc(sizeof(int) * (m_val + 1)); /* allocation */
	if (!count_array)
		return;

	for (i = 0; i <= m_val; i++) /* initiliazing the counting array */
		count_array[i] = 0;
	i = 0;
	while (i < (signed int)size) /* setting the counting array */
	{
		if (!count_array[array[i]])
			count_array[array[i]] = 1, i++;
		else
			count_array[array[i]] += 1, i++;
	} i = 1;
	while (i <= m_val) /* doing the prefix sum or cumulative sum */
		count_array[i] += count_array[i - 1], i++;
	print_array(count_array, m_val + 1), i = size - 1;

	tmp_array = malloc(sizeof(int) * (size + 1)); /* allocation */
	if (!tmp_array)
		return;
	while (i >= 0) /* placing each number at right position */
	{
		tmp_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--, i--;
	} i = 0;
	while (i < (signed int)size) /* copie the tmp array into array given */
		array[i] = tmp_array[i], i++;
	free(tmp_array), free(count_array);
}

