#include "sort.h"

/*
 * merge_sort.c
 * Sorting algorithms.
 * This file implements the merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	size_t mid = size / 2;
	int *left = malloc(mid * sizeof(int));
	int *right = malloc((size - mid) * sizeof(int));
	for (size_t i = 0; i < mid; i++)
		left[i] = array[i];
	for (size_t i = mid; i < size; i++)
		right[i - mid] = array[i];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(left, mid, right, size - mid, array);
	free(left);
	free(right);
}
