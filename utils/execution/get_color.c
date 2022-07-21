/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:21:05 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:44:49 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

unsigned int	get_color(t_texture *t, int x, int y)
{
	char	*ptr;
	int		pixel;

	pixel = (y * t->size_line) + (x * (t->bpp / 8));
	ptr = t->data + pixel;
	return (create_trgb((unsigned char)ptr[2],
			(unsigned char)ptr[1], (unsigned char)ptr[0]));
}
