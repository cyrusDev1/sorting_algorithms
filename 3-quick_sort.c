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
 * lomuto - partition an array into two parts based on a
 * given condition
 * @array: array to sorted
 * @size: size of array
 * @start: first element of array
 * @end: last element of array
 * Return: indice of pivot
 */

int lomuto(int *array, int size, int start, int end)
{
	int pivot_value = array[end];
	int i = start, j = 0;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot_value)
		{
			if (i < j)
			{
				swap_value(array + i, array + j);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > array[end])
	{
		swap_value(array + i, array + end);
		print_array(array, size);
	}

	return (i);
}

/**
 * lomuto_sort - sort an array with algorithm through recursion.
 * @array: array to sorted
 * @size: size of array
 * @start: indice to first element of array
 * @end: indice to last element of array
 * Return: no return
 */

void lomuto_sort(int *array, size_t size, int start, int end)
{
	int pivot;

	if (start < end)
	{
		pivot = lomuto(array, size, start, end);
		lomuto_sort(array, size, start, pivot - 1);
		lomuto_sort(array, size, pivot + 1, end);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: array to sorted
 * @size: size of array
 * Return: No return
 */

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size <= 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
