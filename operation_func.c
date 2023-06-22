#include "monty.h"
/**
 * _mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, x;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	x = h->next->n * h->n;
	h->next->n = x;
	*head = h->next;
	free(h);
}


/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, x;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	x = h->n + h->next->n;
	h->next->n = x;
	*head = h->next;
	free(h);
}

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *x;

	x = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (x)
		x->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}


/**
  *_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *x;
	int sus, nodes;

	x = *head;
	for (nodes = 0; x != NULL; nodes++)
		x = x->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	x = *head;
	sus = x->next->n - x->n;
	x->next->n = sus;
	*head = x->next;
	free(x);
}
