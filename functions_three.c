#include "monty.h"
/**
 * _queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *x;

	x = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (x)
	{
		while (x->next)
			x = x->next;
	}
	if (!x)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		x->next = new_node;
		new_node->prev = x;
	}
}

/**
  *_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *x;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	x = (*head)->next;
	x->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = x;
}
