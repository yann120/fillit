/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:07:37 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/19 18:55:49 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(t_piece *pieces)
{
	int		i;
	int		grid_size;
	char	**grid;

	grid_size = minimal_grid_size(count_pieces(pieces));
	grid = create_grid();
	reset_grid(grid);
	while (!fit_pieces_inside_grid(grid, pieces, grid_size))
	{
		grid_size += 1;
		reset_grid(grid);
	}
	print_grid(grid, grid_size)
}

int		fit_pieces_inside_grid(char **grid, t_piece *pieces, int grid_size, int starting_piece_index)
{
	int i;
	t_piece piece;

	piece = pieces[starting_piece_index];
	if (piece == NULL)
		return (1);
	while (i < grid_size - piece->height + 1)
	{
		j = 0;
		while (j < grid_size - piece->width + 1)
		{
			if (place_piece(grid, piece, i, j))
			{
				if (fit_pieces_inside_grid(grid, pieces, grid_size, starting_piece_index))
				{
					return (1);
				}
				else
				{
					set_piece(grid, i, j, piece, '.')
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
