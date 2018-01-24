/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:56:40 by anazar            #+#    #+#             */
/*   Updated: 2017/10/28 00:48:48 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		save_piece(char *str, t_piece *piece, t_map map)
{
	piece->x_len = get_board_x(str);
	piece->y_len = get_board_y(str);
	piece->map = get_piece(piece->x_len);
	piece->indices = get_indices(piece->map, piece->y_len, map.y_len);
	piece->num_indices = int_arr_len(piece->indices);
	place_piece(&map, *piece);
}
