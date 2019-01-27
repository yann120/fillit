/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:02:28 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/27 17:25:59 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// OK
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

// OK
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

// OK
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

// OK
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

// OK
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

// OK
int			valid_shapes(char **lines)
{
	int curr_block;
	int hashtag_with_two_neighbors;
	int i;
	int j;

	curr_block = 0;
	while (lines[curr_block * 5] != NULL)
	{
		hashtag_with_two_neighbors = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (lines[curr_block * 5 + i][j] == '#')
				{
					if (number_of_neighbors(curr_block, i, j, lines) == 2)
						hashtag_with_two_neighbors++;
					if (number_of_neighbors(curr_block, i, j, lines) == 3)
						return (1);
				}
				j++;
			}
			i++;
		}
		if (hashtag_with_two_neighbors < 2)
			return (0);
		curr_block++;
	}
	return (1);
}

int			number_of_neighbors(int curr_block, int i, int j, char **lines)
{
	int number_of_neighbors;

	number_of_neighbors = 0;
	// gauche
	if (j - 1 >= 0 && lines[curr_block * 5 + i][j - 1] == '#')
		number_of_neighbors++;
	// droite
	if (j + 1 <= 3 && lines[curr_block * 5 + i][j + 1] == '#')
		number_of_neighbors++;
	// haut
	if (i - 1 >= 0 && lines[curr_block * 5 + i - 1][j] == '#')
		number_of_neighbors++;
	// bas
	if (i + 1 <= 3 && lines[curr_block * 5 + i + 1][j] == '#')
		number_of_neighbors++;
	return (number_of_neighbors);
}