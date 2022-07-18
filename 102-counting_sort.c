#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the counting sort algorithm
 * @array: array to sorted_array
 * @size: size of array
 * Return: No return
 */

void counting_sort(int *array, size_t size)
{
	size_t i = 0;
	int *counting_array, *sorted_array, max = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counting_array = malloc(sizeof(int) * max + 1);
	sorted_array = malloc(sizeof(array[0]) * size);
	if (counting_array == NULL || sorted_array == NULL)
	{
		free(counting_array), free(sorted_array);
		return;
	}

	for (i = 0; i < size; i++)
		counting_array[array[i]] += 1;
	for (i = 0; (int)i < max + 1; i++)
		counting_array[i] += counting_array[i - 1];
	print_array(counting_array, max + 1);

	for (i = 0; i < size; i++)
	{
		sorted_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(sorted_array), free(counting_array);
}
