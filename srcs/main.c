/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:53:14 by ypetitje          #+#    #+#             */
/*   Updated: 2019/02/10 16:46:39 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			file_is_valid(char **lines)
{
	int		is_valid;

	is_valid = (has_at_least_five_lines(lines) &&
		valid_number_of_lines(lines) &&
		valid_chars_and_empty_lines(lines, 0) &&
		valid_width(lines) &&
		valid_number_of_chars(lines, 0, 0, 0) &&
		valid_shapes(lines, 0, 0, 0));
	return (is_valid);
}

void		print_error(int error_number)
{
	if (error_number == 0)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit source_file\n");
}

void		free_stuff(char *filetext, char **lines, int print_error_msg)
{
	if (print_error_msg == 1)
		print_error(0);
	free(filetext);
	free_lines(lines);
}

void		run_program(t_piece *pieces, char *filetext, char **lines)
{
	read_pieces_from_file(pieces, filetext);
	fillit(pieces);
	free_stuff(filetext, lines, 0);
}

int			main(int argc, char **argv)
{
	char	*filetext;
	char	*lines[MAX_CHARS];
	t_piece	pieces[26 * 21 + 1 + 1];

	filetext = read_file(argv[1], lines, 0, 0);
	if (argc == 2)
	{
		if (filetext != NULL && filetext[0] != '\0' && file_is_valid(lines))
			run_program(pieces, filetext, lines);
		else
		{
			if (filetext == NULL)
				print_error(0);
			else if (filetext[0] == '\0')
				free_lines_and_print_error(lines);
			else
				free_stuff(filetext, lines, 1);
			return (-1);
		}
	}
	else
		print_error(1);
	return (0);
}
