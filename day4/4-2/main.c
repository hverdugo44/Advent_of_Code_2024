/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:34:46 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/04 15:29:10 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day4.h"

int	mat_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
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

int	find_xmas(char **mat, int i, int j)
{
	int	x;

	x = 0;
	if (mat[i + 1][j + 1] == 'M' && mat[i - 1][j + 1] == 'M' && mat[i - 1][j - 1] == 'S' && mat[i + 1][j - 1] == 'S')
		x++;
	if (mat[i + 1][j + 1] == 'M' && mat[i - 1][j + 1] == 'S' && mat[i - 1][j - 1] == 'S' && mat[i + 1][j - 1] == 'M')
		x++;
	if (mat[i + 1][j + 1] == 'S' && mat[i - 1][j + 1] == 'S' && mat[i - 1][j - 1] == 'M' && mat[i + 1][j - 1] == 'M')
		x++;
	if (mat[i + 1][j + 1] == 'S' && mat[i - 1][j + 1] == 'M' && mat[i - 1][j - 1] == 'M' && mat[i + 1][j - 1] == 'S')
		x++;
	return (x);
}

int	mat_eval(char **mat)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == 'A' && i + 1 < mat_len(mat) && i > 0 && j > 0 && j + 1 < ft_strlen(mat[i]))
				x += find_xmas(mat, i, j);
			j++;
		}
		i++;
	}
	return (x);
}


int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int		x;
	int		i;
	int		j;
	char	*str;
	char	*text;
	char	**mat;
	
	i = 0;
	text = NULL;
	x = open(argv[1], O_RDONLY);
	while (str = get_next_line(x))
	{
		text = ft_strjoint(text, str);
		free(str);
	}
	mat = ft_split(text, '\n');
	free(text);
	close(x);
	j = mat_eval(mat);
	printf("%d\n", j);
	free_mat(mat);
	return (0);
}
