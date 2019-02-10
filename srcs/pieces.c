/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:00:03 by fwuensch          #+#    #+#             */
/*   Updated: 2019/02/10 19:06:09 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_pieces_from_file(t_piece *pieces, char *filetext)
{
	int		i;
	int		piece_index;
	char	blocks[26][20];

	i = 0;
	piece_index = -1;
	while (filetext[i])
	{
		if (i % 21 == 0)
		{
			piece_index++;
			blocks[piece_index][(i % 21) - 1] = '\0';
		}
		else
			blocks[piece_index][(i % 21) - 1] = filetext[i - 1];
		i++;
	}
	i = 0;
	while (i <= piece_index)
	{
		pieces[i] = create_piece_from_block(blocks[i], i, -1, 0);
		i++;
	}
	return (piece_index + 1);
}

t_piece		create_piece_from_block(char *block, int piece_index, int i, int j)
{
	t_piece	piece;
	int		i_diff;
	int		j_diff;
	int		coord_index;

	piece.letter = 'A' + piece_index;
	coord_index = 0;
	while (++i < 4)
	{
		j = -1;
		while (j < 3)
		{
			if (block[i * 5 + ++j] == '#')
			{
				if (coord_index == 0 && (i_diff = 0 - i) == 0 - i)
					j_diff = 0 - j;
				piece.coord[coord_index][0] = i + i_diff;
				piece.coord[coord_index++][1] = j + j_diff;
			}
		}
	}
	piece.height = calculate_height(piece);
	piece.width = calculate_width(piece);
	return (piece);
}

int			calculate_height(t_piece piece)
{
	int		max;
	int		min;
	int		i;

	i = 0;
	min = 10;
	max = -10;
	while (i < 4)
	{
		if (piece.coord[i][0] < min)
			min = piece.coord[i][0];
		if (piece.coord[i][0] > max)
			max = piece.coord[i][0];
		i++;
	}
	return (max - min + 1);
}

int			calculate_width(t_piece piece)
{
	int		max;
	int		min;
	int		i;

	i = 0;
	min = 10;
	max = -10;
	while (i < 4)
	{
		if (piece.coord[i][1] < min)
			min = piece.coord[i][1];
		if (piece.coord[i][1] > max)
			max = piece.coord[i][1];
		i++;
	}
	return (max - min + 1);
}
