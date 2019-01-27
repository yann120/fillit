/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:04:17 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/27 17:28:23 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** TODO: Review leaks on last line (\0)
*/

char		*read_file(char *filepath, char **lines)
{
	char	*line;
	int		fd;
	int		i;
	char	*filetext;

	i = 0;
	line = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	filetext = (char *)malloc(sizeof(char) * (26 * 21 + 1 + 1));
	while (get_next_line(fd, &line) > 0 && i < MAX_LINES)
	{
		lines[i] = ft_strdup(line);
		filetext = ft_strcat(filetext, line);
		filetext = ft_strcat(filetext, "\n");
		free(line);
		i++;
	}
	lines[i] = NULL;
	free(line);
	return (filetext);
}

void		free_lines(char **lines)
{
	int		i;

	i = 0;
	while (lines[i] != NULL)
		free(lines[i++]);
}

void		free_super_grid(char **grid)
{
	int		i;

	i = 0;
	while (i < GRID_MAX)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
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

int			minimal_grid_size(int n)
{
	int		grid_size;

	grid_size = 2;
	while (grid_size * grid_size < n * 4)
	{
		grid_size++;
	}
	return (grid_size);
}
