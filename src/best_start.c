/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 22:41:33 by anazar            #+#    #+#             */
/*   Updated: 2017/10/27 22:42:03 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		get_dist(t_map map, int p1, int p2)
{
	int		row_diff;
	int		col_diff;

	row_diff = get_row(map, p1) - get_row(map, p2);
	col_diff = get_col(map, p1) - get_col(map, p2);
	return (row_diff * row_diff + col_diff * col_diff);
}

int		best_start(t_map *map, int *arr, int pos)
{
	int		i;
	int		*dist;
	int		min;
	int		len;

	i = 0;
	len = int_arr_len(arr);
	dist = (int *)malloc(sizeof(int) * (len + 1));
	dist[len] = -1;
	while (i < len)
	{
		dist[i] = get_dist(*map, arr[i], pos);
		++i;
	}
	i = 0;
	min = 0;
	while (i < len)
	{
		if (dist[i] < dist[min])
			min = i;
		++i;
	}
	return (arr[min]);
}
