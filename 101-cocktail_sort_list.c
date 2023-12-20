#include "sort.h"

/**
  * cocktail_sort_list -  a function that sorts a doubly linked list of ints
  * in ascending order using the Cocktail shaker sort algorithm.
  * @list: array ok integers.
  * Return: void.
  */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int swaped = 1;

	if (!(list) || !(*list) || !((*list)->next))
		return;
	tmp = *list;
	while (swaped)
	{
		swaped = 0;
		while (tmp)
		{
			if (tmp->next && tmp->next->n < tmp->n)
			{
				swap_DLL(list, &tmp->next), swaped = 1;
				print_list(*list);
			}
			else
			{
				if (!tmp->next)
					break;
				tmp = tmp->next; }
		}
		if (!swaped)
			break;
		swaped = 0;
		while (tmp)
		{
			if (tmp->prev && tmp->prev->n > tmp->n)
			{
				swap_DLL(list, &tmp), swaped = 1;
				print_list(*list);
			}
			else
			{
				if (!tmp->prev)
					break;
				tmp = tmp->prev; }
		}
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
