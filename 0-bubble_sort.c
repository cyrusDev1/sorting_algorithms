#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to sorted
 * @size: size of array
 * Return: No return
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	unsigned int temp;
	bool stop;

	if (array == NULL || size < 2)
		return;

	while (stop == false)
	{
		stop = true;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				stop = false;
				print_array(array, size);
			}
		}
	}
}
