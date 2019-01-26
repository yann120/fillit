/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:53:14 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/26 16:03:56 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			file_is_valid(char *filetext, char **lines)
{
	int		is_valid;

	is_valid = (has_at_least_one_piece(lines) &&
		valid_number_of_lines(lines) &&
		valid_chars(lines, 0) &&
		valid_width(lines) &&
		valid_number_of_chars(lines, 0, 0, 0));
	filetext[0] = filetext[0];
	return (is_valid);
}

void		print_error(int error_number)
{
	if (error_number == 0)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit source_file\n");
}

void		free_stuff(char *filetext, char **tab, int print_error_msg)
{
	if (print_error_msg == 1)
		print_error(0);
	free(filetext);
	free_tab(tab);
}

int			main(int argc, char **argv)
{
	char	*filetext;
	char	*tab[MAX_LINES];
	t_piece	pieces[26 * 21 + 1 + 1];

	filetext = read_file(argv[1], tab);
	if (argc == 2)
	{
		if (filetext != NULL && file_is_valid(filetext, tab))
		{
			read_pieces_from_file(pieces, filetext);
			fillit(pieces);
		}
		else
		{
			if (filetext == NULL)
				print_error(0);
			else
				free_stuff(filetext, tab, 1);
			return (-1);
		}
	}
	else
		print_error(1);
	free_stuff(filetext, tab, 0);
	return (0);
}
