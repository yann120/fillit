/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:53:14 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/12 16:49:55 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_errors(int error_number)
{
	if (error_number == 0)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit source_file\n");
}
int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_valid(argv[1]))
		{
			print_errors(0);
			return (-1);
		}
		// fillit(argv[1]);
	}
	else
		print_errors(1);
	return (0);
}

// tableau = read_file(filepath)
// validate(tableau)
	// pieces = translate(tableau)
	// fillit(pieces)
// sinon
	// error