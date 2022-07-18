#include "sort.h"

/**
 * swap_value - swap tow values
 * @val1: first value to swap
 * @val2: second value to swap
 * Return no return
 */

void swap_value(int *val1, int *val2)
{
	int tmp;

	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the shell sort algorithm using the Knuth sequence
 * @array: array to sorted
 * @size: size of array
 * Return: No return
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j, i;

	if (array == NULL || size <= 2)
		return;

	while (gap < size)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
			{
				swap_value(array + j, array + (j - gap));
			}
		}
		if (gap <= size)
			print_array(array, size);
	}
}
