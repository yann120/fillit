/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:35:03 by fwuensch          #+#    #+#             */
/*   Updated: 2019/01/19 18:44:00 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grid(char **grid, int grid_size)
{
	int		i;
	int		j;

	while (i < grid_size)
	{
		while (j < grid_size)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		minimal_grid_size(n)
{
	int grid_size;

	grid_size = 2;
	while (grid_size ** 2 < n * 4)
	{
		grid_size++;
	}
	return (grid_size);
}

char		**create_grid(void)
{
	char	**grid;

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

	while (i < GRID_MAX)
	{
		while (j < GRID_MAX)
		{
			grid[i][j] = '.'
			j++;
		}
		i++;
	}
}
