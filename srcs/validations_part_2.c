/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_part_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:22:49 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/27 18:28:55 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			valid_shapes(char **lines, int i, int j, int curr_block)
{
	int hashtag_with_two_neighbors;

	while (lines[curr_block * 5] != NULL && (i = 0) == 0)
	{
		hashtag_with_two_neighbors = 0;
		while (i < 4 && (j = 0) == 0)
		{
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
	if (j - 1 >= 0 && lines[curr_block * 5 + i][j - 1] == '#')
		number_of_neighbors++;
	if (j + 1 <= 3 && lines[curr_block * 5 + i][j + 1] == '#')
		number_of_neighbors++;
	if (i - 1 >= 0 && lines[curr_block * 5 + i - 1][j] == '#')
		number_of_neighbors++;
	if (i + 1 <= 3 && lines[curr_block * 5 + i + 1][j] == '#')
		number_of_neighbors++;
	return (number_of_neighbors);
}
