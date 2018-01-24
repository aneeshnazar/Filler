/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:52:48 by anazar            #+#    #+#             */
/*   Updated: 2017/10/28 00:54:19 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	place_piece(t_map *map, t_piece piece)
{
	int		*arr;
	int		target;
	int		start;

	arr = find_placements(map, piece);
	if (*arr != -1)
	{
		target = seal(map);
		start = best_start(map, arr, target);
		ft_putnbr(get_row(*map, start));
		ft_putchar(' ');
		ft_putnbr(get_col(*map, start));
		ft_putchar('\n');
	}
	else
		negative_place(map, piece);
	free(arr);
}
