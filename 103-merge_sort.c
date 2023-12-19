#include "sort.h"

/**
 * merge - Merges two subarrays of an array
 * @array: The array to be sorted
 * @temp: A temporary array for merging
 * @left: The starting index of the left subarray
 * @mid: The ending index of the left subarray and starting index of the right subarray
 * @right: The ending index of the right subarray
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k;
	
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);
	
	i = left;
	j = mid;
	k = 0;
	
	while (i < mid && j < right)
		{
			if (array[i] <= array[j])
			{
				temp[k] = array[i];
				i++;
			}
			else
			{
				temp[k] = array[j];
				j++;
			}
			k++;
		}

	while (i < mid)
		{
			temp[k] = array[i];
			i++;
			k++;
		}

	while (j < right)
		{
			temp[k] = array[j];
			j++;
			k++;
		}

	for (i = left, k = 0; i < right; i++, k++)
		{
			array[i] = temp[k];
		}
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursive function for merge sort
 * @array: The array to be sorted
 * @temp: A temporary array for merging
 * @left: The starting index of the subarray
 * @right: The ending index of the subarray
 */
void merge_sort_recursive(int *array, int *temp, int left, int right)
{
	int mid;

	if (right - left <= 1)
		return;

	mid = (left + right) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
