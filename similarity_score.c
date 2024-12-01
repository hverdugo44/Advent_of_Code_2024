/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   similarity_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:16:23 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/01 16:43:10 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day1.h"

int	sscore(t_stack *stack, t_stack *stack1)
{
	int	i;
	t_stack	*temp;

	i = 0;
	temp = stack1;
	while (temp)
	{
		if (stack->left < temp->rigth)
			return (i);
		else if (stack->left == temp->rigth)
			i++;
		temp = temp->next;
	}
	return (i);
}
