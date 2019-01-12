/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:02:28 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/12 15:40:04 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	read_file(char **table, char *filepath)
{
	char 	*line;
	int		fd;
	int		i; //counter of tetriminos
	
	i = 0;
	line = NULL;
	fd = open(filepath, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && i < 26)
	{
		table[i] = ft_strdup(line);
		ft_memdel((void **)&line);
		if (ft_strlen(table[i]) != 20)
			return (0);
		if (table[i][4] != '\n' || table[i][9] != '\n'|| table[i][14] != '\n'|| table[i][19] != '\n')
			return (0);
		i++;
	}
	if (get_next_line(fd, &line) > 0) // It means that there is more than 26 tetriminos
		return (0);
	free(line);
	return(1);
}

int		is_valid(char *filepath)
{
	//there is max 26 tetriminos
	char 	*table[26];
	
	if (read_file(table, filepath) == 0)
		return (0);
	return (1);
}
