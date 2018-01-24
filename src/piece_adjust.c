/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_adjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 00:32:10 by anazar            #+#    #+#             */
/*   Updated: 2017/10/26 00:50:52 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	add_to_all(t_piece *piece, int fac)
{
	int		i;

	i = 0;
	while (i < piece->num_indices)
	{
		piece->indices[i] += fac;
		++i;
	}
}

void	piece_adjust(t_piece *piece, int num)
{
	add_to_all(piece, num);
}
