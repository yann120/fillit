/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:35:03 by fwuensch          #+#    #+#             */
/*   Updated: 2019/01/27 18:06:31 by ypetitje         ###   ########.fr       */
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

int			place_piece(char **grid, t_piece piece, int i, int j, int size)
{
	int		x;
	int		j2;
	int		i2;

	x = 0;
	while (x < 4)
	{
		i2 = i + piece.coord[x][0];
		j2 = j + piece.coord[x][1];
		if (i2 < 0 || i2 >= size || j2 < 0 || j2 >= size)
			return (0);
		if (grid[i2][j2] != '.')
		{
			return (0);
		}
		x++;
	}
	set_piece(grid, i, j, piece);
	return (1);
}
