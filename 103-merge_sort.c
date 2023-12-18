#include "sort.h"

/**
 * merge - a function that merges two subarrays of an array
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @left: Pointer to the left subarray
 * @right: Pointer to the right subarray
 */
void merge(int *array, size_t size, int *left, int *right)
{
	int i = 0, j = 0, k = 0, n1 = size / 2, n2 = size - n1;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, n1);
	printf("[right]: ");
	print_array(right, n2);

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1)
    	{
		array[k] = left[i];
		i++;
		k++;
	}
    	while (j < n2)
	{
		array[k] = right[j];
		j++;
		k++;
	}
    	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - a function that sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int mid = size / 2;
	int i;
	int left[1000];
	int right[1000];

	if (size < 2)
		return;
	for (i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (i = mid; i < size; i++)
	{
		right[i - mid] = array[i];
	}
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, size, left, right);
}
