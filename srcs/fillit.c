/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:07:37 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/26 16:26:48 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(t_piece *pieces)
{
	int		grid_size;
	char	**grid;

	grid_size = minimal_grid_size(count_pieces(pieces));
	grid = create_grid();
	reset_grid(grid);
	while (!fit_pieces_inside_grid(grid, pieces, grid_size, 0))
	{
		grid_size += 1;
		reset_grid(grid);
	}
	print_grid(grid, grid_size);
	free_super_grid(grid);
}

int		fit_pieces_inside_grid(char **grid, t_piece *pieces, int size, int idx)
{
	int		i;
	int		j;
	t_piece piece;

	piece = pieces[idx];
	if (piece.height == 0)
		return (1);
	i = 0;
	while (i < size - piece.height + 1)
	{
		j = 0;
		while (j < size - piece.width + 1)
		{
			if (place_piece(grid, piece, i, j))
			{
				if (fit_pieces_inside_grid(grid, pieces, size, idx + 1))
					return (1);
				else
					remove_piece(grid, i, j, piece);
			}
			j++;
		}
		i++;
	}
	return (0);
}
