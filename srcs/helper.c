/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:04:17 by ypetitje          #+#    #+#             */
/*   Updated: 2019/02/10 16:51:02 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*read_file(char *filepath, char **lines, int i, int letters_read)
{
	char	*line;
	int		fd;
	char	*filetext;

	line = NULL;
	if ((fd = open(filepath, O_RDONLY)) < 0)
		return (NULL);
	filetext = (char *)malloc(sizeof(char) * MAX_CHARS);
	while (get_next_line(fd, &line) > 0 && i < MAX_CHARS)
	{
		letters_read += ft_strlen(line);
		if (letters_read > MAX_CHARS)
		{
			free(filetext);
			free(line);
			return ("\0");
		}
		lines[i++] = ft_strdup(line);
		filetext = ft_strcat(filetext, line);
		filetext = ft_strcat(filetext, "\n");
		free(line);
	}
	free(line);
	if (i == 0)
	{
		free(filetext);
		return (NULL);
	}
	lines[i] = NULL;
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
