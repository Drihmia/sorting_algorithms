#include "sort.h"

/**
  * h_sort_radix - helper function that sort by singl digit at
  * a specific position.
  * @array: Array of integers to be sorted.
  * @exp: the exponent used in the calculation.
  * @radix: the base / radix of the number's system.
  * @output: output array - sorted one.
  * @size: Size of the array.
  * Return: None.
  */
void h_sort_radix(int *array, int exp, int radix, int *output, size_t size)
{
	int *ar_cnt, *ar_idx, pos, i;

	/* allocate and initiliaze the indexing array */
	ar_idx = malloc(sizeof(int) * radix);
	if (!ar_idx)
		return;
	for (i = 0; i < radix; i++)
		ar_idx[i] = 0;

	/* allocate and initiliaze the contying array */
	ar_cnt = malloc(sizeof(int) * radix);
	if (!ar_cnt)
		return;
	for (i = 0; i < radix; i++)
		ar_cnt[i] = 0;
	/* set up count's array */
	for (i = 0; i < (signed int)size; i++)
		ar_cnt[digit_at_pos(array[i], exp, radix)] += 1;
	for (i = 1; i < radix; i++)
		ar_cnt[i] += ar_cnt[i - 1];
	for (i = 0; i < (signed int)size; i++)
	{
		pos = digit_at_pos(array[i], exp, radix);
		if (pos == 0)
			output[ar_idx[0]] = array[i], ar_idx[0] += 1;
		else
		{
			output[ar_cnt[pos - 1] + ar_idx[pos]] = array[i];
			ar_idx[pos] += 1;
		}
	}
	free(ar_idx), free(ar_cnt);
}
/**
  * radix_sort - a function that sorts an array of integers in ascending
  * @array: Array of integers to be sorted.
  * @size: Size of the array.
  */
void radix_sort(int *array, size_t size)
{
	int *output = NULL, i, j, m_val, len, exp = 1;

	if (!array || size < 2)
		return;
	m_val = get_m_val(array, size), len = _len(m_val);
	output = malloc(sizeof(int) * size);
	if (!output)
		return;


	for (i = 1; i <= len ; i++)
	{
		h_sort_radix(array, exp, 10, output, size);
		for (j = 0; j < (signed int)size; j++)
			array[j] = output[j];
		print_array(array, size);
		exp = exp * 10;
	}
	free(output);
}

/**
 * _len - give a length of a positive integer.
 * @n: positive integer
 * Return: number of digit in n
 */

int _len(long int n)
{
	 int i;

	i = 0;

	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}
/**
  * digit_at_pos - extract a digit from a number at certain position.
  * @n: number (dividend).
  * @exp: the exponent used in the calculation.
  * @radix: the base / radix of the number's system.
  * Return: the digit at disered position.
  */
unsigned int digit_at_pos(unsigned int n, unsigned int exp, int radix)
{
	return ((n % (exp * radix)) / (exp));
}
/**
  * get_m_val - get the nax value in the array
  * @array: Array of integers to be sorted.
  * @size: Size of the array.
  * Return: max value
  */
int get_m_val(int *array, size_t size)
{
	int m_val;
	int i;

	if (!array)
		return (-1);
	if (size == 1)
		return (array[0]);

	m_val = array[0];
	for (i = 0; i < (signed int)size; i++)
	{
		if (array[i] > m_val)
			m_val = array[i];
	}
	return (m_val);
}

