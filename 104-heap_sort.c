#include "sort.h"

/**
 * sift_down - Sifts down a node in a heap
 * @array: The array representing the heap
 * @size: Number of elements in @array
 * @root: Index of the root of the subtree
 * @end: Index of the end of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < end && array[left] > array[max])
		max = left;
	if (right < end && array[right] > array[max])
		max = right;
	if (max != root)
	{
		int temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		sift_down(array, size, max, end);
	}
}

/**
 * heapify - Converts an array into a heap
 * @array: The array to be converted
 * @size: Number of elements in @array
 */
void heapify(int *array, size_t size)
{
	size_t i;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	heapify(array, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		sift_down(array, size, 0, i);
	}
}
