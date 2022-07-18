#include "sort.h"

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
	int i = start, j = 0, tmp = 0;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot_value)
		{
			if (i < j)
			{
				tmp =  array[i];
				array[i] = array[j];
				array[j] =  tmp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > array[end])
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
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
