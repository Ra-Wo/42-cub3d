/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:55:04 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:45:48 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	init_color(t_cub3d *cub3d, int texture_num)
{
	if (cub3d->side == 0)
		cub3d->wall_x
			= cub3d->player->pos_y + cub3d->ray_length * cub3d->ray_dir_y;
	else
		cub3d->wall_x
			= cub3d->player->pos_x + cub3d->ray_length * cub3d->ray_dir_x;
	cub3d->wall_x -= (int)cub3d->wall_x;
	cub3d->tex_x
		= (int)(cub3d->wall_x * (float)cub3d->texture[texture_num].width);
	cub3d->step
		= (float)cub3d->texture[texture_num].height / cub3d->line_height;
	if (cub3d->line_height < SCREENHEIGHT)
		cub3d->tex_pos = 0;
	else
		cub3d->tex_pos
			= ((cub3d->line_height / 2) - (SCREENHEIGHT / 2)) * cub3d->step;
}

int	create_trgb(int r, int g, int b)
{
	return ((((r) << 16) + ((g) << 8) + (b)));
}
