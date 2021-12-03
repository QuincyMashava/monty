#include "monty.h"

/**
 * is_number - goes through each character of string to check of if it is number or digit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_number(const char *n)
{
  int i = 0;

  if (*n == '-')
    i = 1;
  for (; *(n + i) != '\0'; i++)
    {
      if (isdigit(*(n + i)) == 0)
	return (-1);
    }
  return (0);
}
/**
 * push - adds node to the start of dlinkedlist
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 */
void push(stack_t **h, unsigned int line_number, const char *n)
{
  stack_t *node = NULL;
  (void) n;

  node = malloc(sizeof(stack_t));
  if (!node)
    {
      fprintf(stderr, "Error: malloc failed\n");
      freestack(h);
      exit(EXIT_FAILURE);
    }

  node->prev = node->next = NULL;

  if (!(*h))
    (*h) = node;
  else
    {
      (*h)->prev = node;
      node->next = *h;
      *h = node;
    }
}
/**
 * pop - removes node at front of dlinkedlist
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void pop(stack_t **h, unsigned int line_number)
{
  if (h == NULL || *h == NULL)
    {
      printf("L%u: can't pop an empty stack\n", line_number);
      freestack(h);
      exit(EXIT_FAILURE);
    }
  else
    delete_end_node(h);
}
