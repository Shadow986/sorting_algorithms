#include "sort.h"

/**
 * quick_sort_hoare - a function that sorts an array 
 * of integers in ascending order using the Quick
 * sort algorithm with Hoare partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_partition(array, 0, size - 1, size);
}

/**
 * hoare_partition - a function that partitions the array
 * using the Hoare partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in the array
 * Return: The index of the pivot element
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
		{
			i++;
		}
		while (array[i] < pivot);
		do
		{
			j--;
		}
		while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * swap - a function that swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
