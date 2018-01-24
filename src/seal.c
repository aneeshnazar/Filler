/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:52:29 by anazar            #+#    #+#             */
/*   Updated: 2017/10/28 00:54:16 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		second_highest(int *arr)
{
	int max;
	int s_max;
	int	i;

	max = 0;
	i = 0;
	s_max = 0;
	while (i < 4)
	{
		if (arr[max] < arr[i])
		{
			s_max = max;
			max = i;
		}
		else if (arr[i] > arr[s_max] && arr[i] != arr[max])
			s_max = i;
		++i;
	}
	return (s_max);
}

int		cutoff(t_map *map)
{
	int	q;
	int q_pos;
	int	x;
	int	y;

	q = second_highest(map->start_q);
	x = ((q / 2) ? map->x_len / 4 : -map->x_len / 4);
	y = ((q % 2) ? map->y_len / 4 : -map->y_len / 4);
	q_pos = pos_from_xy(map, map->x_midpoint + x, map->y_midpoint + y);
	return (q_pos);
}

int		sealed(t_map *map)
{
	int	i;
	int	pos;
	int	c;

	i = 0;
	c = '.';
	pos = map->indices[0];
	while (get_row(*map, pos) < map->x_len - 1)
	{
		if (map->map[pos_from_xy(map, get_row(*map, pos) + 1,
					get_col(*map, pos) + 1)] != c)
			pos = pos_from_xy(map, get_row(*map, pos) + 1,
					get_col(*map, pos) + 1);
		else if (map->map[pos_from_xy(map, get_row(*map, pos),
					get_col(*map, pos) + 1)] != c)
			pos = pos_from_xy(map, get_row(*map, pos),
					get_col(*map, pos) + 1);
		else if (map->map[pos_from_xy(map, get_row(*map, pos) + 1,
					get_col(*map, pos))] != c)
			pos = pos_from_xy(map, get_row(*map, pos) + 1,
					get_col(*map, pos));
		else
			return (0);
	}
	return (1);
}

int		seal(t_map *map)
{
	if (!sealed(map))
	{
		if (get_row(*map, map->indices[0]) != 0)
			return (0);
		else
			return (map->enem_s_pos);
	}
	else
		return (cutoff(map));
}
