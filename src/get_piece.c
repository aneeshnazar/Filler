/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:51:05 by anazar            #+#    #+#             */
/*   Updated: 2017/10/23 18:51:24 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

char		*get_piece(int num_rows)
{
	char	*str;
	char	*out;
	int		i;

	i = 0;
	out = ft_strnew(0);
	while (i < num_rows)
	{
		get_next_line(0, &str);
		str = ft_strjoinfree(str, ft_strdup("\n"));
		out = ft_strjoinfree(out, str);
		++i;
	}
	return (out);
}
