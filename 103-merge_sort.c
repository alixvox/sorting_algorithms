#include "sort.h"

/**
 * merge_sort - sorts the array using top-down merge sort algorithm
 * @array: pointer to the array
 * @size: size of array
*/
voice merge_srt(int *array, size_t size)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int *temp_array = malloc(sizeof(int) * (end + start - 1));
    /* check for array existence and size > 1 */
    if (!array || size < 2)
        return;
    /* begin division of array and subsquent merge */
    mergeSort(array, start, mid, temp_array);
    mergeSort(array, mid + 1, end, temp_array);
    merge(array, start, mid, end, temp_array);
    free(temp_array);
}

/**
 * mergeSort - divides the array down to single indexes and then merges up.
 * @array: pointer to the array to be merged.
 * @start: starting index.
 * @end: ending index.
 * @temp_array: the temporary array.
 */
void mergeSort(int *array, int start, int end, int *temp_array)
{
    /* determine if further division is necessary and then merge */
    if (start < end)
    {
        int mid = ((start + end - 1) / 2);

        mergeSort(array, start, mid, temp_array);
        mergeSort(array, mid + 1, end, temp_array);
        merge(array, start, mid, end, temp_array);
    }
}

/**
 * merge - performs the merge of divided arrays.
 * @array: pointer to the array to be merged.
 * @start: starting index.
 * @mid: middle index.
 * @end: ending index.
 * @temp_array: the temporary array.
 */
void merge(int *array, int start, int mid, int end, int *temp_array)
{
    int i = start, j = mid + 1, k = 0;
    int x;

    printf("Merging...\n");
    printf("[left]: ");
    for (x = i; x < j; x++)
    {
        printf("%d", array[x]);
        if (x < (j - 1))
            printf(", ");
    }
    printf("\n");
    printf("[right]: ");
    for (; x < end + 1; x++)
    {
        printf("%d", array[x]);
        if (x < end)
            printf(", ");
    }
    printf("\n");
    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
        {
            temp_array[k] = array[i], k++, i++;
        }
        else
        {
            temp_array[k] = array[j], k++, j++;
        }
    }
    while (i <= mid)
    {
        temp_array[k] = array[i], k++, i++;
    }
    while (j <= end)
    {
        temp_array[k] = array[j], k++, j++;
    }
    printf("[Done]: ");
    for (i = start; i <= end; i++)
    {
        array[i] = temp_array[i - start];
        printf("%d", array[i]);
        if (i != end)
            printf(", ");
        else
            printf("\n");
    }
}
