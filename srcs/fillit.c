/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:07:37 by ypetitje          #+#    #+#             */
/*   Updated: 2019/02/10 20:03:57 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(t_piece *pieces, int nb_pieces)
{
	int		grid_size;
	char	**grid;

	grid_size = minimal_grid_size(nb_pieces);
	grid = create_grid();
	reset_grid(grid);
	while (!fit_pieces_inside_grid(grid, pieces, grid_size, 0, nb_pieces))
	{
		grid_size += 1;
		reset_grid(grid);
	}
	print_grid(grid, grid_size);
	free_super_grid(grid);
}

int		fit_pieces_inside_grid(char **grid, t_piece *pieces, int size, int idx, int nb_pieces)
{
	int		i;
	int		j;
	int		pos[2];
	t_piece piece;

	piece = pieces[idx];
	if (idx >= nb_pieces)
		return (1);
	i = -1;
	while (++i < size && (j = -1) == -1)
	{
		while (++j < size)
		{
			pos[0] = i;
			pos[1] = j;
			if (place_piece(grid, piece, pos, size))
			{
				if (fit_pieces_inside_grid(grid, pieces, size, idx + 1, nb_pieces))
					return (1);
				else
					remove_piece(grid, i, j, piece);
			}
		}
	}
	return (0);
}
