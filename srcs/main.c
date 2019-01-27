/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:53:14 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/27 17:17:30 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			file_is_valid(char **lines)
{
	int		is_valid;

	printf("\nhas_at_least_five_lines: %d\n", has_at_least_five_lines(lines));
	printf("valid_number_of_lines: %d\n", valid_number_of_lines(lines));
	printf("valid_chars_and_empty_lines: %d\n", valid_chars_and_empty_lines(lines, 0));
	printf("valid_width: %d\n", valid_width(lines));
	printf("valid_number_of_chars: %d\n", valid_number_of_chars(lines, 0, 0, 0));
	printf("valid_shapes: %d\n\n", valid_shapes(lines));

	is_valid = (has_at_least_five_lines(lines) &&
		valid_number_of_lines(lines) &&
		valid_chars_and_empty_lines(lines, 0) &&
		valid_width(lines) &&
		valid_number_of_chars(lines, 0, 0, 0) &&
		valid_shapes(lines));
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

int			main(int argc, char **argv)
{
	char	*filetext;
	char	*lines[MAX_LINES];
	t_piece	pieces[26 * 21 + 1 + 1];

	filetext = read_file(argv[1], lines);
	if (argc == 2)
	{
		if (filetext != NULL && file_is_valid(lines))
		{
			read_pieces_from_file(pieces, filetext);
			fillit(pieces);
			free_stuff(filetext, lines, 0);
		}
		else
		{
			if (filetext == NULL)
				print_error(0);
			else
				free_stuff(filetext, lines, 1);
			return (-1);
		}
	}
	else
		print_error(1);
	return (0);
}
