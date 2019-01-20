/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:53:14 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/20 15:57:44 by ypetitje         ###   ########.fr       */
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
	t_piece pieces[26];

	filetext = read_file(argv[1]);
	if (argc == 2)
	{
		if (file_is_valid(argv[1]))
		{
			read_pieces_from_file(pieces, filetext);
			fillit(pieces);
		}
		else
		{
			print_error(0);
			return (-1);
		}
	}
	else
	{
		print_error(1);
	}
	return (0);
}
