#include "sort.h"

/**
 * bitonic_merge - a function that merges two subarrays
 * of an array in bitonic order
 * @array: The array to be sorted
 * @size: The size of the array
 * @start: The starting index of the subarray
 * @count: The number of elements in the subarray
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t count, int dir)
{
	size_t k, i, j;
	int temp;

	if (count > 1)
	{
		size_t mid = count / 2;
		for (k = start; k < start + mid; k++)
		{
			if (dir == (array[k] > array[k + mid]))
			{
				temp = array[k];
				array[k] = array[k + mid];
				array[k + mid] = temp;
			}
		}
		bitonic_merge(array, size, start, mid, dir);
		bitonic_merge(array, size, start + mid, mid, dir);
	}
	print_array(array, size);
}

/**
 * bitonic_sort_recursive - a function that recursive function for bitonic sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @start: The starting index of the subarray
 * @count: The number of elements in the subarray
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t count, int dir)
{
	size_t mid;

	if (count > 1)
	{
		mid = count / 2;
		bitonic_sort_recursive(array, size, start, mid, 1);
		bitonic_sort_recursive(array, size, start + mid, mid, 0);
		bitonic_merge(array, size, start, count, dir);
	}
}

/**
 * bitonic_sort - a function that sorts an array of integers
 * in ascending order using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sort_recursive(array, size, 0, size, 1);
}
