/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:35:03 by fwuensch          #+#    #+#             */
/*   Updated: 2019/01/24 22:22:54 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_grid(char **grid, int grid_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char		**create_grid(void)
{
	char	**grid;
	int		i;

	grid = (char**)malloc(sizeof(char*) * GRID_MAX);
	if (grid == NULL)
		return (NULL);
	i = 0;
	while (i < GRID_MAX)
	{
		grid[i] = (char*)malloc(sizeof(char) * GRID_MAX);
		if (grid[i] == NULL)
			return (NULL);
		i++;
	}
	return (grid);
}

void		set_piece(char **grid, int i, int j, t_piece piece)
{
	int		x;

	x = 0;
	while (x < 4)
	{
		grid[i + piece.coord[x][0]][j + piece.coord[x][1]] = piece.letter;
		x++;
	}
}

void		remove_piece(char **grid, int i, int j, t_piece piece)
{
	int		x;

	x = 0;
	while (x < 4)
	{
		grid[i + piece.coord[x][0]][j + piece.coord[x][1]] = '.';
		x++;
	}
}

int			place_piece(char **grid, t_piece piece, int i, int j)
{
	int		x;

	x = 0;
	while (x < 4)
	{
		if (grid[i + piece.coord[x][0]][j + piece.coord[x][1]] != '.')
			return (0);
		x++;
	}
	set_piece(grid, i, j, piece);
	return (1);
}
