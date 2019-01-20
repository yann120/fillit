/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:04:17 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/20 18:04:39 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(char *filepath)
{
	char	*line;
	int		fd;
	int		i;
	char	*filetext;

	filetext = (char *)malloc(sizeof(char) * (26 * 21 + 1 + 1));
	i = 0;
	line = NULL;
	fd = open(filepath, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && i < 548)
	{
		filetext = ft_strcat(filetext, line);
		filetext = ft_strcat(filetext, "\n");
		ft_memdel((void **)&line);
		i++;
	}
	free(line);
	return (filetext);
}
