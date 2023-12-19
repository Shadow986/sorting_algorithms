#include "sort.h"

/**
 * heapify - a function that rearranges the elements in a max heap
 * @array: The array to be sorted
 * @size: The size of the array
 * @root: The root index of the subtree
 * @max: The maximum index of the subtree
 */
void heapify(int *array, size_t size, size_t root, size_t max)
{

	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < max && array[left] > array[largest])
		largest = left;
	if (right < max && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		int temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, largest, max);
	}
}

/**
 * heap_sort - a function that sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
		{
			int temp = array[0];
			array[0] = array[i];
			array[i] = temp;

			print_array(array, size);
			heapify(array, size, 0, i);
    }
}
