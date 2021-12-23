#include "sort.h"

/**
 * bubble_sort - sorts an array.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, swap;
	
	int s = (int)size;
	for (i = 0; i < s - 1; i++)
	{
		for (j = 0; j < (s - 1) - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
	}
}