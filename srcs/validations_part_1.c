/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_part_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:02:28 by ypetitje          #+#    #+#             */
/*   Updated: 2019/02/10 20:12:27 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			has_at_least_five_lines(char **lines)
{
	int		i;

	i = 0;
	while (lines[i] != NULL)
	{
		i++;
	}
	return (i >= 4);
}

int			valid_number_of_lines(char **lines)
{
	int		i;

	i = 0;
	while (lines[i] != NULL)
	{
		i++;
	}
	return ((i + 1) % 5 == 0);
}

int			valid_chars_and_empty_lines(char **lines, int curr_line)
{
	int		i;
	int		j;

	i = 1;
	while (lines[curr_line] != NULL)
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
		if ((j = 0) == 1 || i % 5 == 0)
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
