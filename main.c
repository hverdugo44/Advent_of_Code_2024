/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:40:28 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/01 13:12:32 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day1.h"

int	resta(t_stack **stack)
{
	if ((*stack)->left > (*stack)->rigth)
		return ((*stack)->left - (*stack)->rigth);
	else
		return ((*stack)->rigth - (*stack)->left);
}

void	orden_l(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int	i;

	temp1 = *stack;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->left > temp2->left)
			{
				i = temp1->left;
				temp1->left = temp2->left;
				temp2->left = i;
				temp2 = temp1->next;
			}
			else
				temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	orden_r(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int	i;

	temp1 = *stack;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->rigth > temp2->rigth)
			{
				i = temp1->rigth;
				temp1->rigth = temp2->rigth;
				temp2->rigth = i;
				temp2 = temp1->next;
			}
			else
				temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

int	main(void)
{
	int	x;
	int	res;
	char	*str;
	t_stack	*list;
	t_stack *temp;

	res = 0;
	list = NULL;
	x = open("list.txt", O_RDONLY);
	str = get_next_line(x);
	while (str)
	{
		fill(&list, str);
		str = get_next_line(x);
	}
	temp = list;
	orden_l(&list);
	orden_r(&list);
	while (temp)
	{
		res += resta(&list);
		printf("%d\n%d\n\nSuma de los resultados = %d\n\n\n", temp->left, temp->rigth, res);
		temp = temp->next;
	}
	close(x);
	free_stack(&list);
	return (0);
}
