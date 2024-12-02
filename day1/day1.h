#ifndef DAY1_H
# define DAY1_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_stack
{
	int	left;
	int	rigth;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int l, int r);
t_stack	*end(t_stack *stack);
void	stack_fill(t_stack **stack, t_stack *new);
void	fill(t_stack **stack, char *str);
void	free_stack(t_stack **stack);
void	orden_l(t_stack **stack);
void	orden_r(t_stack **stack);
int	sscore(t_stack *stack, t_stack *stack1);
#endif
