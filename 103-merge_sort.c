#include "sort.h"

/**
 * merge - Merges two subarrays of array[].
 * @array: The array to sort
 * @left: The left subarray
 * @right: The right subarray
 * @left_size: Number of elements in left[]
 * @right_size: Number of elements in right[]
 */
void merge(int *array, int *left, int *right, int left_size, int right_size)
{
	int i = 0, j = 0, k = 0;
	
	while (i < left_size && j < right_size)
		{
			if (left[i] <= right[j])
				array[k++] = left[i++];
			else
				array[k++] = right[j++];
		}

	while (i < left_size)
		array[k++] = left[i++];
	while (j < right_size)
		array[k++] = right[j++];
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int mid = size / 2;
	int *left = malloc(mid * sizeof(int));
	int *right = malloc((size - mid) * sizeof(int));

	for (int i = 0; i < mid; i++)
		left[i] = array[i];
	for (int i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, mid, size - mid);

	free(left);
	free(right);
}
