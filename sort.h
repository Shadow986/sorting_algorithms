#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

/* Data Structure and Functions */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* prototypes */

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/* prototypes from task 7-12 */

void merge(int *array, int *temp, int left, int mid, int right);
void merge_sort_recursive(int *array, int *temp, int left, int right);
void merge_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t root, size_t max);
void heap_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t count, int dir);
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t count, int dir);
void bitonic_sort(int *array, size_t size);

#endif
