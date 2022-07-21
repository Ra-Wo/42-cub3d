/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_texture_to_draw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:06:37 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:57:59 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	which_texture(t_cub3d *cub3d, int x_or_y)
{
	if (x_or_y)
	{
		cub3d->tex_n = 3;
		if (cub3d->ray_dir_y > 0)
			cub3d->tex_n = 2;
	}
	else
	{
		cub3d->tex_n = 0;
		if (cub3d->ray_dir_x > 0)
			cub3d->tex_n = 1;
	}
}
