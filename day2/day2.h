/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:51:52 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/03 01:27:38 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DAY2_H
# define DAY2_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_stack
{
	int	num;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int num);
t_stack	*end(t_stack *stack);
void	stack_fill(t_stack **stack, t_stack *new);
void	fill(t_stack **stack, char *str);
void	free_stack(t_stack **stack);
t_stack	*up(t_stack **stack);
t_stack	*down(t_stack **stack);
void	free_mat(char **str);
int	eval_down(t_stack **stack);
int	eval_up(t_stack **stack);
int	eval(char *str, t_stack **stack);
void	delete_next(t_stack **stack);
int	evaluar(t_stack **stack, int i);
#endif
