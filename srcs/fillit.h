/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:50:09 by ypetitje          #+#    #+#             */
/*   Updated: 2019/02/10 17:11:38 by fwuensch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

# define MAX_CHARS 548
# define MAX_LINES 26 * 4
# define GRID_MAX 30

typedef	struct		s_piece {
	int				coord[4][2];
	char			letter;
	int				height;
	int				width;
}					t_piece;

int					file_is_valid(char **lines);
void				print_error(int error_number);
void				run_program(t_piece *pieces, char *filetext, char **lines);
void				free_lines_and_print_error(char **lines);
void				free_stuff(char *filetext, char **lines, int print_msg);

char				*read_file(char *filepath, char **lines, int i, int chrs);
void				free_lines(char **lines);
void				free_super_grid(char **grid);
void				reset_grid(char **grid);
int					minimal_grid_size(int n);

int					has_at_least_five_lines(char **lines);
int					valid_number_of_lines(char **lines);
int					valid_chars_and_empty_lines(char **lines, int curr_line);
int					valid_width(char **lines);
int					valid_number_of_chars(char **lines, int curr, int p, int h);
int					valid_shapes(char **lines, int i, int j, int b);
int					number_of_neighbors(int cur_bl, int i, int j, char **lines);

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
int					place_piece(char **grid, t_piece p, int *pos, int s);

#endif
