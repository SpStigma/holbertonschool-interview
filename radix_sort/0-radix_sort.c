#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * get_max - Finds the maximum value in an array.
 * @array: The array to check.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Performs counting sort on array based on a specific digit.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The current digit's exponent (1 for units, 10 for tens, etc.).
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;
	ssize_t j;

	output = malloc(size * sizeof(int));
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using LSD Radix Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
