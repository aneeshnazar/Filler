/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:47:58 by anazar            #+#    #+#             */
/*   Updated: 2017/10/25 21:28:21 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

char		*get_board(int num_rows)
{
	char	*str;
	char	*out;
	int		i;

	get_next_line(0, &str);
	ft_strdel(&str);
	out = ft_strnew(0);
	i = 0;
	while (i < num_rows)
	{
		get_next_line(0, &str);
		str = ft_strjoin(str + 4, "\n");
		out = ft_strjoinfree(out, str);
		++i;
	}
	return (out);
}
