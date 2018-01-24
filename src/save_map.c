/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:56:26 by anazar            #+#    #+#             */
/*   Updated: 2017/10/27 22:36:14 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_quads(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
		map->start_q[i] = 0;
	i = -1;
	while (map->map[++i])
	{
		if (map->map[i] == '.')
		{
			if (get_row(*map, i) < map->x_midpoint &&
				get_col(*map, i) < map->y_midpoint)
				++map->start_q[0];
			if (get_row(*map, i) < map->x_midpoint &&
				get_col(*map, i) > map->y_midpoint)
				++map->start_q[1];
			if (get_row(*map, i) > map->x_midpoint &&
				get_col(*map, i) < map->y_midpoint)
				++map->start_q[2];
			if (get_row(*map, i) > map->x_midpoint &&
				get_col(*map, i) > map->y_midpoint)
				++map->start_q[3];
		}
	}
}

int		get_q(t_map *map, int player)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == (player == 1 ? 'o' : 'x'))
			break ;
		++i;
	}
	i = (2 * (get_row(*map, i) > map->x_midpoint) +
			(get_col(*map, i) > map->y_midpoint));
	return (i);
}

void	save_map(char *str, t_map *map, int *flag)
{
	if (*flag)
	{
		map->x_len = get_board_x(str);
		map->y_len = get_board_y(str);
		map->x_midpoint = map->x_len / 2;
		map->y_midpoint = map->y_len / 2;
		*flag = 0;
	}
	else
	{
		free(map->map);
		free(map->indices);
	}
	map->map = get_board(map->x_len);
	if (ft_countif(map->map, (map->player == 1 ? 'X' : 'O')) == 1)
		map->enem_s_pos = ft_find(map->map, (map->player == 1 ? "X" : "O"));
	get_quads(map);
	map->indices = get_map_indices(map->map, map->player);
	map->num_indices = int_arr_len(map->indices);
}
