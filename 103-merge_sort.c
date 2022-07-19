#include "sort.h"


/**
 * merge - merge to array
 * @array: array to sorted
 * @size: size of main array
 * @left: left index
 * @middle: middle
 * @right: right index
 * Return: No return
 */

void merge(int *array, size_t size, int left, int middle, int right)
{
	(void)array;
	(void)size;
	(void)left;
	(void)middle;
	(void)right;
}

/**
 * divide - divide array
 * @array: array to sorted
 * @size: size of array
 * @left: left index
 * @right: right index
 * Return: No return
 */

void divide(int *array, size_t size, int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = left + (right - left) / 2;
		divide(array, size, left, middle);
		divide(array, size, middle + 1, right);
		merge(array, size, left, middle, right);
	}
}


/**
 * merge_sort - sorts an array of integers in ascending order
 * using the merge sort algorithm
 * @array: array to sorted_array
 * @size: size of array
 * Return: No return
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	divide(array, size, 0, size - 1);
}
