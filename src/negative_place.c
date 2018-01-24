/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 22:45:42 by anazar            #+#    #+#             */
/*   Updated: 2017/10/30 14:17:28 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <limits.h>

void		zero_piece(t_map *map, t_piece piece, int *x_diff, int *y_diff)
{
	int		i;

	i = 0;
	*x_diff = get_row(*map, piece.indices[0]);
	*y_diff = get_col(*map, piece.indices[0]);
	while (i < piece.num_indices)
	{
		if (get_row(*map, piece.indices[i]) < *x_diff)
			*x_diff = get_row(*map, piece.indices[i]);
		if (get_col(*map, piece.indices[i]) < *y_diff)
			*y_diff = get_col(*map, piece.indices[i]);
		++i;
	}
	piece_adjust(&piece, -pos_from_xy(map, *x_diff, *y_diff));
}

void		negative_place(t_map *map, t_piece piece)
{
	int		row_diff;
	int		col_diff;
	int		start;
	int		*arr;
	int		target;

	zero_piece(map, piece, &row_diff, &col_diff);
	arr = find_placements(map, piece);
	if (*arr != -1)
	{
		target = seal(map);
		start = best_start(map, arr, target);
		ft_putnbr(get_row(*map, start) - row_diff);
		ft_putchar(' ');
		ft_putnbr(get_col(*map, start) - col_diff);
		ft_putchar('\n');
	}
	else
		ft_putstr("0 0\n");
	free(arr);
}
