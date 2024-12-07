#ifndef DAY5_H
# define DAY5_H

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
#endif
