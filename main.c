/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:53:14 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/24 21:49:19 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(int error_number)
{
	if (error_number == 0)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit source_file\n");
}

int		main(int argc, char **argv)
{
	char	*filetext;
	char    *tab[MAX_LINES];
	t_piece pieces[26 * 21 + 1 + 1];

	filetext = read_file(argv[1], tab);
	if (argc == 2)
	{
		if (file_is_valid(filetext, tab))
		{
			read_pieces_from_file(pieces, filetext);
			fillit(pieces);
		}
		else
		{
			print_error(0);
			free(filetext);
			return (-1);
		}
	}
	else
	{
		print_error(1);
	}
	free(filetext);
	free_tab(tab);
	return (0);
}
