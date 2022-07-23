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
 * hoare - partition an array into two parts based on a
 * given condition
 * @array: array to sorted
 * @size: size of array
 * @start: first element of array
 * @end: last element of array
 * Return: indice of pivot
 */

int hoare(int *array, int size, int start, int end)
{
	int pivot_value = array[start];
	int i, j;

	for (i = start - 1, j = end + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot_value);
		do {
			j--;
		} while (array[j] > pivot_value);

		if (i < j)
		{
			swap_value(array + j,  array + i);
			print_array(array, size);
		}
	}
	return (j);
}

/**
 * hoare_sort - sort an array with algorithm through recursion.
 * @array: array to sorted
 * @size: size of array
 * @start: indice to first element of array
 * @end: indice to last element of array
 * Return: no return
 */

void hoare_sort(int *array, size_t size, int start, int end)
{
	int pivot;

	if (start < end)
	{
		pivot = hoare(array, size, start, end);
		hoare_sort(array, size, start, pivot - 1);
		hoare_sort(array, size, pivot + 1, end);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: array to sorted
 * @size: size of array
 * Return: No return
 */

void quick_sort_hoare(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
