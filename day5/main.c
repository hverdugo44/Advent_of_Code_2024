/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:15:03 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/07 11:38:24 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day5.h"

int	arreglo(int *arr, int start, int end, t_stack **stack);

int	arr_len(int *arr);

int	find_erro(int	*arr, t_stack **stack)
{
	t_stack	*temp;
	int	i;
	int	j;
	int	x;

	temp = *stack;
	while (temp)
	{
		j = 1;
		i = 0;
		while (arr[i + j])
		{
			if (arr[i] == temp->rigth)
			{
				while (arr[i + j])
				{
					if (arr[i + j] == temp->left)
						return (0);
					j++;
				}
			}
			i++;
			j = 1;
		}
		temp = temp->next;
	}
	printf("se ha encontrado la combinacion correcta");
	return (arr[arr_len(arr) / 2]);
}

void	swap(int *a1, int *a2)
{
	int	temp;

	temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

int	arr_len(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	find_error(int	*arr, t_stack **stack)
{
	t_stack	*temp;
	int	i;
	int	j;
	int	x;

	temp = *stack;
	printf("find error");
	while (temp)
	{
		j = 1;
		i = 0;
		while (arr[i + j])
		{
			if (arr[i] == temp->rigth)
			{
				while (arr[i + j])
				{
					if (arr[i + j] == temp->left)
						return (arreglo(arr, 0, arr_len(arr), stack));
					j++;
				}
			}
			i++;
			j = 1;
		}
		temp = temp->next;
	}
	return (0);
}

int	arreglo(int *arr, int start, int end, t_stack **stack)
{
	int	k;

	if (find_erro(arr, stack) != 0)
		return (arr[arr_len(arr) / 2]);
	else
	{
		for (int i = start; i < end; i++)
		{
			swap(&arr[start], &arr[i]);
			k = arreglo(arr, start + 1, end, stack);
			if (k != 0)
				return (k);
			swap(&arr[start], &arr[i]);
		}
	}
	return (0);
}
int	*evalstr(char *str)
{
	int	i, j;
	int	*arr;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
		printf("bucle comas ->%d \n", i);
	}
	printf("malloc");
	arr = malloc(sizeof(int) * (j + 2));
	j = 0;
	i = 0;
	printf("malloc");
	while (str[i])
	{
		printf("bucle atoi");
		arr[j] = atoi(&str[i]);
		printf("%d   ", arr[j]);
		j++;
		while (str[i] && str[i] != ',')
			i++;
		if (str[i])
			i++;
	}
	for (int k = 0; k < arr_len(arr); k++)
		printf("%d ", arr[k]);
	return (arr);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int	i, x, j;
	char	*str;
	t_stack	*stack, *temp;
	int	*arr;

	stack = NULL;
	i = 0;
	x = open(argv[1], O_RDONLY);
	str = get_next_line(x);
	while (str)
	{
		if (atoi(str) == 0)
			break ;
		fill(&stack, str);
		free(str);
		str = get_next_line(x);
		printf("bucle listas\n");
	}
	free(str);
	while (str = get_next_line(x))
	{
		printf("bucle get_next line\n");
		arr = evalstr(str);
		j = find_error(arr, &stack);
		i += j;
		free(str);
		free(arr);
		printf("%d\n%d\n", j, i);
	}
	free_stack(&stack);
	close(x);
	return (0);
}
