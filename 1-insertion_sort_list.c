#include "sort.h"


/**
 * swap_n - swap two nodes
 * @head: pointer to the head of dll
 * @node1: pointer to the first node to swap
 * @node2: second node to swap
 * Return: no return
 */

void swap_n(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else
	{
		*head = node2;
	}
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list -  sorts a doubly linked list of
 * ntegers in ascending order using the Insertion sort algorithm
 * @list: pointer to pointer
 * Return: no return
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_n(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
