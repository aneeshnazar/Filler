/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:51:43 by anazar            #+#    #+#             */
/*   Updated: 2017/10/27 23:41:12 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			main(void)
{
	t_map	map;
	t_piece	piece;
	char	*str;
	int		pos;
	int		flag;

	flag = 1;
	pos = 0;
	get_next_line(0, &str);
	map.player = get_p_num(str);
	while (get_next_line(0, &str) > 0)
	{
		if (!ft_strncmp(str, "Plateau", 7))
			save_map(str, &map, &flag);
		if (!ft_strncmp(str, "Piece", 5))
			save_piece(str, &piece, map);
	}
	return (0);
}
