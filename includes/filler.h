/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:59:32 by anazar            #+#    #+#             */
/*   Updated: 2017/10/28 00:52:57 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>

typedef struct	s_piece
{
	int			x_len;
	int			y_len;
	char		*map;
	int			*indices;
	int			*corners;
	int			num_indices;
}				t_piece;

typedef struct	s_map
{
	int			player;
	int			x_len;
	int			y_len;
	char		*map;
	int			*indices;
	int			num_indices;
	int			x_midpoint;
	int			y_midpoint;
	int			start_q[4];
	int			last_q;
	int			enem_s_pos;
}				t_map;

int				int_arr_len(int *arr);
int				get_p_num(char *str);
int				get_board_x(char *str);
int				get_board_y(char *str);
char			*get_piece(int num_rows);
char			*get_board(int num_rows);
int				*get_indices(char *piece, int p_cols, int m_cols);
int				*get_corners(t_piece piece);
void			save_map(char *str, t_map *map, int *flag);
int				*get_map_indices(char *map, int player);
void			save_piece(char *str, t_piece *piece, t_map map);
void			piece_adjust(t_piece *piece, int fac);
void			place_piece(t_map *map, t_piece piece);
int				get_row(t_map map, int pos);
int				get_col(t_map map, int pos);
int				pos_from_xy(t_map *map, int x, int y);
int				*find_placements(t_map *map, t_piece piece);
int				best_start(t_map *map, int *arr, int pos);
void			negative_place(t_map *map, t_piece piece);
int				seal(t_map *map);
#endif
