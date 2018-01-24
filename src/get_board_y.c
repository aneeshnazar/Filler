/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:48:44 by anazar            #+#    #+#             */
/*   Updated: 2017/10/23 18:48:54 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		get_board_y(char *str)
{
	int	pos;

	pos = ft_find(str, ":") - 1;
	while (ft_isdigit(str[pos]))
		--pos;
	str += pos;
	return (ft_atoi(str));
}
