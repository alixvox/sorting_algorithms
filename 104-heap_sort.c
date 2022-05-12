#include "sort.h"

/**
 * heap_sort - sorts an array with the sift-down algorithm.
 * @a: pointer to the original array
 * @size: size of the array.
 */
void heap_sort(int *a, size_t size)
{
	int p;
	int len = size;

	if (!a || size < 2)
		return;

	for (p = ((size / 2) - 1); p >= 0; p--)
		heapify(a, size, p, len);
	for (p = (size - 1); p >= 0; p--)
	{
		swap(&a[0], &a[p]);
		if (p > 0)
			print_array(a, len);
		heapify(a, p, 0, len);
	}
}

/**
 * heapify - finds the children of a node in a heap tree
 * and swaps them if necessary.
 * @a: The current array
 * @p: The parent node idx
 * @size: size of the heap
 * @len: The length of the
 */
void heapify(int *a, int size, int p, int len)
{
	int largest = p;
	int l = 2 * p + 1;
	int r = 2 * p + 2;

	if (l < size && a[l] > a[largest])
		largest = l;
	if (r < size && a[r] > a[largest])
		largest = r;
	if (largest != p)
	{
		swap(&a[p], &a[largest]);
		print_array(a, len);
		heapify(a, size, largest, len);
	}
}

/**
 * swap - swaps two elements
 * @x: first element
 * @y: second element
 */
void swap(int *x, int *y)
{
	int i = *x;
	*x = *y;
	*y = i;
}
