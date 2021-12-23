#include "sort.h"

/**
 * bubble_sort - sorts an array.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, lowest_idx, swap;
	
	int s = (int)size;
	for (i = 0; i < s; i++)
	{
		lowest_idx = i;
		for (j = i + 1; j < s; j++)
		{
			if (array[j] < array[lowest_idx])
				lowest_idx = j;
		}
		swap = array[i];
		array[i] = array[lowest_idx];
		array[lowest_idx] = swap;
		print_array(array, size);
	}
}