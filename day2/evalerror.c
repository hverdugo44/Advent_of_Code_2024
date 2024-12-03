#include "day2.h"

int	evaluar(t_stack **stack, int i)
{
	int	j;
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = *stack;
	j = 0;
	while (j < i)
	{
		temp = temp->next;
		j++;
		if (temp == NULL)
			return (0);
	}
	if (*stack == temp)
	{
		temp = temp->next;
		free(*stack);
		*stack = temp;
	}
	else if ((*stack)->next == temp)
	{
		free(*stack);
		*stack = temp;
	}
	else
	{
		while (temp2->next != temp)
			temp2 = temp2->next;
		temp2->next = temp->next;
		free(temp);
	}
	if (up(stack) == NULL || down(stack) == NULL)
	{
		if (up(stack) == NULL)
			printf("\nup");
		else if (down(stack) == NULL)
			printf("\ndown");
		return (1);
	}
	else
		return (2);
}
