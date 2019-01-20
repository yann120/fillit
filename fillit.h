/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:50:09 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/20 17:59:06 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line/get_next_line.h"

# define GRID_MAX 30

typedef	struct		s_piece {
	int				coord[4][2];
	char			letter;
	int				height;
	int				width;
}					t_piece;

// fillit
void	fillit(t_piece *pieces);
int		fit_pieces_inside_grid(char **grid, t_piece *pieces, int grid_size, int starting_piece_index);

// helper
char	*read_file(char *filepath);

// validation
int		file_is_valid(char *filetext);
int		has_at_least_one_piece(char **lines);
int		valid_number_of_lines(char **lines);
int		valid_chars(char **lines);
int		valid_width(char **lines);
int		valid_number_of_chars(char **lines);

// grid
void	print_grid(char **grid, int grid_size);
int		minimal_grid_size(int n);
char		**create_grid(void);
void		reset_grid(char **grid);
void		set_piece(char **grid, int i, int j, t_piece piece, char chr);
int		place_piece(char **grid, t_piece piece, int i, int j);

// pieces
t_piece		*read_pieces_from_file(t_piece *pieces, char *filetext);
t_piece		create_piece_from_block(char *block_str, int piece_index);
int			calculate_height(t_piece piece);
int			calculate_width(t_piece piece);
int		count_pieces(t_piece *pieces);

#endif
