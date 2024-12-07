/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:38:07 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/05 16:35:49 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day5.h"

t_stack	*stack_new(int l, int r)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->left = l;
	new->rigth = r;
	new->next = NULL;
	return (new);
}

t_stack	*end(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_fill(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = NULL;
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = end(*stack);
	last->next = new;
}

void	fill(t_stack **stack, char *str)
{
	int	l;
	int	r;
	int	i;

	i = 0;
	l = ft_atoi(str);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i++;
	r = ft_atoi(&str[i]);
	stack_fill(stack, stack_new(l, r));
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
