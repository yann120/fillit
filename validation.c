/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:02:28 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/20 18:15:34 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		file_is_valid(char *filetext)
{
	int		is_valid;
	char	**lines;

	lines = ft_strsplit(filetext, '\n');
	is_valid = has_at_least_one_piece(lines) &&
		valid_number_of_lines(lines) &&
		valid_chars(lines) &&
		valid_width(lines) &&
		valid_number_of_chars(lines);
		// valid_shapes(filetext);
	return (is_valid);
}

int		has_at_least_one_piece(char **lines)
{
	int		i;

	i = 0;
	while (lines[i] != NULL)
	{
		i++;
	}
	return (i + 1 >= 5);
}

int		valid_number_of_lines(char **lines)
{
	int		i;

	i = 0;
	while (lines[i] != NULL)
	{
		i++;
	}
	return ((i + 1) % 5 == 0);
}

int		valid_chars(char **lines)
{
	int		i;
	int		j;
	int		curr_line;

	i = 1;
	curr_line = 0;
	while(lines[curr_line])
	{
		if (i % 5 == 0)
		{
			if (ft_strcmp(lines[curr_line], "\n") != 0)
				return (0);
		}
		else
		{
			j = 0;
			while (lines[curr_line][j])
			{
				if (lines[curr_line][j] != '\n' && lines[curr_line][j] != '.' && lines[curr_line][j] != '#')
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int		valid_width(char **lines)
{
	int		i;
	int		curr_line;

	i = 1;
	curr_line = 0;
	while(lines[curr_line])
	{
		if (i % 5 == 0)
		{
			if (ft_strlen(lines[curr_line]) != 1)
				return (0);
		}
		else
		{
			if (ft_strlen(lines[curr_line]) != 5)
				return (0);
		}
		i++;
	}
	return (1);
}

int		valid_number_of_chars(char **lines)
{
	int		i;
	int		j;
	int		hashtags;
	int		points;
	int		curr_line;

	i = 1;
	hashtags = 0;
	points = 0;
	curr_line = 0;
	while(lines[curr_line])
	{
		if (i % 5 == 0)
		{
			hashtags = 0;
			points = 0;
		}
		j = 0;
		while (lines[curr_line][j])
		{
			if (lines[curr_line][j] == '#')
				hashtags++;
			if (lines[curr_line][j] == '.')
				points++;
		}
		if (i % 5 == 4)
		{
			if ((hashtags != 4) || (points != 12))
				return (0);
		}
		i++;
	}
	return (1);
}

// int		valid_shapes(char **lines)
// {
// 	int		block;
// 	int		i;
// 	int		j;
// 	int		hashtag_with_two_neighbors;

// 	block = 0;
// 	while (lines[block * 5])
// 	{
// 		i = 0;
// 		while (i < 4)
// 		{
// 			while (j < 4)
// 			{
// 				if (lines[i][j] == '#')
// 					if (number_of_neighbors(block))
// 						hashtag_with_two_neighbors++;
// 				j++;
// 			}
// 			i++;
// 		}


// 	}

// }
