#include "day2.h"

int	stack_length(t_stack *stack)
{
	int	i;
	t_stack	*temp;

	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_stack	*up(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->num >= temp->next->num)
			return (temp);
		else if (temp->num + 3 < temp->next->num)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_stack	*down(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->num <= temp->next->num)
			return (temp);
		else if (temp->num - 3 > temp->next->num)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	free_mat(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	eval(char *str, t_stack **stack)
{
	char	**mat;
	int		i;
	int		x;
	int		j;
	t_stack	*temp;
	t_stack	*eval;
	t_stack	*eval2;

	x = 0;
	mat = ft_split(str, ' ');
	i = 0;
	while (mat[i])
	{
		stack_fill(stack, stack_new(atoi(mat[i])));
		printf("%d\n",atoi(mat[i]));
		i++;
	}
	while (1)
	{
		i = 0;
		j = evaluar(stack, x);
		if (j == 1)
		{
			free_mat(mat);
			free_stack(stack);
			return (1);
		}
		else if (j == 0)
		{
			free_mat(mat);
			free_stack(stack);
			return (0);
		}
		x++;
		free_stack(stack);
		while (mat[i])
		{
			stack_fill(stack, stack_new(atoi(mat[i])));
			i++;
		}
		printf("%d", x);
	}
	return (0);
}

int	main(void)
{
	int	x;
	char	*str;
	t_stack	*list;
	int	i;
	int	j;

	j = 1;
	i = 0;
	list = NULL;
	x = open("list.txt", O_RDONLY);
	str = get_next_line(x);
	while (str)
	{
		i += eval(str, &list);
		printf("\n%d->%d\n",j++, i);
		free(str);
		str = get_next_line(x);
	}
	close(x);
	return (0);
}
