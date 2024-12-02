#include "day2.h"

int	up(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->num >= temp->next->num)
			return (0);
		else if (temp->num + 3 < temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	down(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->num <= temp->next->num)
			return (0);
		else if (temp->num - 3 > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
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
	t_stack	*temp;

	i = 0;
	mat = ft_split(str, ' ');
	while (mat[i])
	{
		stack_fill(stack, stack_new(atoi(mat[i])));
		i++;
	}
	temp = *stack;
	if (temp->num > temp->next->num)
		x = down(&temp);
	else if (temp->num < temp->next->num)
		x = up(&temp);
	else
		x = 0;
	free_stack(stack);
	free_mat(mat);
	return (x);
}

int	main(void)
{
	int	x;
	char	*str;
	t_stack	*list;
	int	i;

	i = 0;
	list = NULL;
	x = open("list.txt", O_RDONLY);
	str = get_next_line(x);
	while (str)
	{
		i += eval(str, &list);
		printf("%d\n", i);
		free(str);
		str = get_next_line(x);
	}
	close(x);
	return (0);
}
