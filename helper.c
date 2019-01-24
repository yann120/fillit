/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:04:17 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/24 21:57:30 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(char *filepath, char **tab)
{
	char	*line;
	int		fd;
	int		i;
	char	*filetext;

	filetext = (char *)malloc(sizeof(char) * (26 * 21 + 1 + 1));
	i = 0;
	line = NULL;
	fd = open(filepath, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && i < MAX_LINES)
	{
		tab[i] = ft_strdup(line);
		filetext = ft_strcat(filetext, line);
		filetext = ft_strcat(filetext, "\n");
		free(line);
		i++;
	}
	free(line);
	return (filetext);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
}

void	free_super_grid(char **grid)
{
	int i;

	i = 0;
	while (i < GRID_MAX)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
