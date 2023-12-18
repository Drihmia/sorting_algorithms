#include "sort.h"

/**
  * insertion_sort_list - a function that sorts a doubly linked list of
  * integers in ascending order using the Insertion sort algorithm.
  * @list: array ok integers.
  * Return: void.
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *h = NULL;

	if (!(list) || !(*list) || !((*list)->next))
		return;
	tmp = *list, h = (*list);
	while (h)
	{
		tmp = h;
		while (tmp)
		{
			if (tmp->prev && tmp->prev->n < tmp->n)
				break;
			if (tmp->prev && tmp->prev->n > tmp->n)
			{
				swap_DLL(list, &tmp);
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
		h = h->next;
	}
}
/**
  * swap_DLL - a function that swap two node in a Doubly Linked List.
  * @list: the address of doubly linked list.
  * @right_node: the right node of the 2 nodes to swap.
  * Return: None.
  */
void swap_DLL(listint_t **list, listint_t **right_node)
{
	listint_t *pv = NULL, *nt = NULL, *tmp = *right_node;

	pv = tmp->prev, nt = tmp->next;

	pv->next = tmp->next;

	if (nt)
		nt->prev = tmp->prev;

	tmp->prev = pv->prev, tmp->next = pv;

	if (pv->prev == NULL)
		(*list) = tmp;
	else
		pv->prev->next = tmp;
	pv->prev = tmp;
}
