/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:56:21 by hverdugo          #+#    #+#             */
/*   Updated: 2024/12/03 18:27:59 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day3.h"

//int	dont(
int	eval(char *str)
{
	int	i;
	int	j;

	i = 4;
	j = 0;
	while (str[i] <= '9' && str[i] >= '0' && i < 8)
		i++;
	if (str[i] == ',')
		i++;
	else
		return (0);
	while (str[i + j] >= '0' && str[i + j] <= '9' && j < 4)
		j++;
	if (str[i + j] != ')')
		return (0);
	return (atoi(&str[4]) * atoi(&str[i]));
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*text;
	char	*temp;
	char	*si;
	char	*no;
	int		x;
	int		res;
	int		y;
	int		j;
	
	if (argc != 2)
		return (0);
	y = 1;
	res = 0;
	text = NULL;
	x = open(argv[1], O_RDONLY);
	while (str = get_next_line(x))
	{
		text = ft_strjoint(text, str);
		free(str);
	}
	temp = strstr(text, "mul(");
	si = text;
	while (1)
	{
		no = strstr(si, "don't()");
		if (no)
			si = strstr(no, "do()");
		j = 1;
		while (temp && (&*temp < &*no) || (!no && temp))
		{
			res += eval(temp);
			printf("%d	---->%d\n",j++, res);
			*temp++;
			if (!temp)
				break ;
			temp = strstr(temp, "mul(");
		}
		printf("\n----->%d\n", y++);
		if (!si || !temp)
			break ;
		temp = strstr(si, "mul(");
		if (temp == NULL)
			break ;
	}
	free(text);
	close(x);
	return (0);
}
