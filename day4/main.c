/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:34:46 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/04 14:58:47 by hverdugo         ###   ########.fr       */
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
	if ((j + 3 < ft_strlen(mat[i])) && mat[i][j + 1] == 'M' && mat[i][j + 2] == 'A' && mat[i][j + 3] == 'S')
		x++;
	if ((j > 2) && mat[i][j - 1] == 'M' && mat[i][j - 2] == 'A' && mat[i][j - 3] == 'S')
		x++;
	if ((j + 3 < ft_strlen(mat[i])) && (i + 3 < mat_len(mat)) && mat[i + 1][j + 1] == 'M' && mat[i + 2][j + 2] == 'A' && mat[i + 3][j + 3] == 'S')
		x++;
	if (j > 2 && (i + 3 < mat_len(mat)) && mat[i + 1][j - 1] == 'M' && mat[i + 2][j - 2] == 'A' && mat[i + 3][j - 3] == 'S')
		x++;
	if (i > 2 && j > 2 && mat[i - 1][j - 1] == 'M' && mat[i - 2][j - 2] == 'A' && mat[i - 3][j - 3] == 'S')
		x++;
	if (i > 2 && (j + 3 < ft_strlen(mat[i])) && mat[i - 1][j + 1] == 'M' && mat[i - 2][j + 2] == 'A' && mat[i - 3][j + 3] == 'S')
		x++;
	if ((i + 3 < mat_len(mat)) && mat[i + 1][j] == 'M' && mat[i + 2][j] == 'A' && mat[i + 3][j] == 'S')
		x++;
	if (i > 2 && mat[i - 1][j] == 'M' && mat[i - 2][j] == 'A' && mat[i - 3][j] == 'S')
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
			if (mat[i][j] == 'X')
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
