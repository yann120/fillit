/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:02:28 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/26 16:26:35 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			has_at_least_one_piece(char **lines)
{
	int		i;

	i = 0;
	while (lines[i] != NULL)
	{
		i++;
	}
	return (i + 1 >= 5);
}

int			valid_number_of_lines(char **lines)
{
	int		i;

	i = 0;
	while (lines[i] != NULL)
		i++;
	return ((i + 1) % 5 == 0);
}

int			valid_chars(char **lines, int curr_line)
{
	int		i;
	int		j;

	i = 1;
	while (lines[curr_line])
	{
		if (i % 5 == 0)
		{
			if (ft_strlen(lines[curr_line]) != 0)
				return (0);
		}
		else
		{
			j = 0;
			while (lines[curr_line][j])
			{
				if (lines[curr_line][j] != '.' && lines[curr_line][j] != '#')
					return (0);
				j++;
			}
		}
		i++;
		curr_line++;
	}
	return (1);
}

int			valid_width(char **lines)
{
	int		i;
	int		curr_line;

	i = 1;
	curr_line = 0;
	while (lines[curr_line])
	{
		if (i % 5 == 0)
		{
			if (ft_strlen(lines[curr_line]) != 0)
				return (0);
		}
		else
		{
			if (ft_strlen(lines[curr_line]) != 4)
				return (0);
		}
		i++;
		curr_line++;
	}
	return (1);
}

int			valid_number_of_chars(char **lines, int curr_line, int p, int h)
{
	int		i;
	int		j;

	i = 1;
	while (lines[curr_line])
	{
		if (i % 5 == 0 || (j = 0) == 1)
		{
			h = 0;
			p = 0;
		}
		while (lines[curr_line][j])
		{
			if (lines[curr_line][j] == '#')
				h++;
			if (lines[curr_line][j++] == '.')
				p++;
		}
		if (i++ % 5 == 4)
			if ((h != 4) || (p != 12))
				return (0);
		curr_line++;
	}
	return (1);
}
