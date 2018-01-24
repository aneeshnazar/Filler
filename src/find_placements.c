/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_placements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 00:41:48 by anazar            #+#    #+#             */
/*   Updated: 2017/10/26 00:51:44 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		exactly_one(t_map map, t_piece piece)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (i < map.num_indices)
	{
		j = 0;
		while (j < piece.num_indices)
		{
			if (map.indices[i] == piece.indices[j])
				++count;
			if (count > 1)
				return (0);
			++j;
		}
		++i;
	}
	return (count == 1);
}

int		valid(t_map map, t_piece piece, int start)
{
	int		i;
	int		j;

	i = 0;
	j = start;
	while (j < piece.y_len + start)
	{
		if (map.map[j] == '\n')
			return (0);
		++j;
	}
	while (i < piece.num_indices)
	{
		if (ft_tolower(map.map[piece.indices[i]]) ==
				(map.player == 1 ? 'x' : 'o'))
			return (0);
		++i;
	}
	return (1);
}

int		in_map(t_map map, t_piece piece)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(map.map);
	return (piece.indices[piece.num_indices - 1] < len - 1);
}

int		*find_placements(t_map *map, t_piece piece)
{
	int		i;
	int		len;
	int		*arr;
	int		arr_it;

	i = 0;
	arr_it = 0;
	len = ft_strlen(map->map);
	arr = (int *)malloc(sizeof(int) * (len + 1));
	while (in_map(*map, piece))
	{
		if (exactly_one(*map, piece) && valid(*map, piece, i))
		{
			arr[arr_it] = i;
			++arr_it;
		}
		piece_adjust(&piece, 1);
		++i;
	}
	piece_adjust(&piece, -i);
	arr[arr_it] = -1;
	return (arr);
}
