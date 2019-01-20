/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:35:03 by fwuensch          #+#    #+#             */
/*   Updated: 2019/01/20 17:57:40 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grid(char **grid, int grid_size)
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

int		minimal_grid_size(int n)
{
	int grid_size;

	grid_size = 2;
	while (grid_size * 2 < n * 4)
	{
		grid_size++;
	}
	return (grid_size);
}

char		**create_grid(void)
{
	char	**grid;
	int i;

	grid = (char**)malloc(sizeof(char*) * GRID_MAX);
	if (grid == NULL)
		return (NULL);
	i = 0;
	while (i < GRID_MAX)
	{
		grid[i] = (char*)malloc(sizeof(char) * GRID_MAX);
		if (grid[1] == NULL)
			return (NULL);
	}
	return (grid);
}

void		reset_grid(char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < GRID_MAX)
	{
		j = 0;
		while (j < GRID_MAX)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		set_piece(char **grid, int i, int j, t_piece piece, char chr)
{
	int		x;

	x = 0;
	while (x < 4)
	{
		grid[i + piece.coord[x][0]][j + piece.coord[x][1]] = chr;
	}
}

int		place_piece(char **grid, t_piece piece, int i, int j)
{
	int x;

	x = 0;
	while (x < 4)
	{
		if (grid[i + piece.coord[x][0]][j + piece.coord[x][1]] != '.')
			return (0);
	}
	set_piece(grid, i, j, piece, piece.letter);
	return (1);
}
