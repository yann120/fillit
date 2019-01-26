/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:50:09 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/26 16:38:25 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

# define MAX_LINES 548
# define GRID_MAX 30

typedef	struct		s_piece {
	int				coord[4][2];
	char			letter;
	int				height;
	int				width;
}					t_piece;

int					file_is_valid(char **lines);
void				print_error(int error_number);
void				free_stuff(char *filetext, char **tab, int print_error_msg);

char				*read_file(char *filepath, char **tab);
void				free_tab(char **tab);
void				free_super_grid(char **grid);
void				reset_grid(char **grid);
int					minimal_grid_size(int n);

int					has_at_least_one_piece(char **lines);
int					valid_number_of_lines(char **lines);
int					valid_chars(char **lines, int curr_line);
int					valid_width(char **lines);
int					valid_number_of_chars(char **lines, int curr, int p, int h);

t_piece				*read_pieces_from_file(t_piece *pieces, char *filetext);
t_piece				create_piece_from_block(char *blk, int p_idx, int i, int j);
int					calculate_height(t_piece piece);
int					calculate_width(t_piece piece);
int					count_pieces(t_piece *pieces);

void				fillit(t_piece *pieces);
int					fit_pieces_inside_grid(char **gd, t_piece *p, int s, int i);

void				print_grid(char **grid, int grid_size);
char				**create_grid(void);
void				set_piece(char **grid, int i, int j, t_piece piece);
void				remove_piece(char **grid, int i, int j, t_piece piece);
int					place_piece(char **grid, t_piece piece, int i, int j);

#endif
