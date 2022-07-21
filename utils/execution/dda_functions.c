/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:19:03 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:45:48 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	init_vars(t_cub3d *cub3d, int i)
{
	cub3d->camera_x = 2 * i / (float)SCREENWIDTH - 1;
	cub3d->ray_dir_x = cub3d->player->dir_x
		+ (cub3d->player->plane_x * cub3d->camera_x);
	cub3d->ray_dir_y = cub3d->player->dir_y
		+ (cub3d->player->plane_y * cub3d->camera_x);
	cub3d->map_x = (int)cub3d->player->pos_x;
	cub3d->map_y = (int)cub3d->player->pos_y;
	cub3d->delta_dist_x = fabsf(1 / cub3d->ray_dir_x);
	cub3d->delta_dist_y = fabsf(1 / cub3d->ray_dir_y);
	cub3d->hit = 0;
}

void	init_dist(t_cub3d *cub3d)
{
	if (cub3d->ray_dir_x < 0)
	{
		cub3d->step_x = -1;
		cub3d->side_dist_x
			= (cub3d->player->pos_x - cub3d->map_x) * cub3d->delta_dist_x;
	}
	else
	{
		cub3d->step_x = 1;
		cub3d->side_dist_x
			= (cub3d->map_x + 1.0 - cub3d->player->pos_x) * cub3d->delta_dist_x;
	}
	if (cub3d->ray_dir_y < 0)
	{
		cub3d->step_y = -1;
		cub3d->side_dist_y
			= (cub3d->player->pos_y - cub3d->map_y) * cub3d->delta_dist_y;
	}
	else
	{
		cub3d->step_y = 1;
		cub3d->side_dist_y
			= (cub3d->map_y + 1.0 - cub3d->player->pos_y) * cub3d->delta_dist_y;
	}
}

void	wall_collision_for_ray(t_cub3d *cub3d)
{
	int	x_or_y;

	while (cub3d->hit == 0)
	{
		if (cub3d->side_dist_x < cub3d->side_dist_y)
		{
			cub3d->side_dist_x += cub3d->delta_dist_x;
			cub3d->map_x += cub3d->step_x;
			cub3d->side = 0;
			x_or_y = 0;
		}
		else
		{
			cub3d->side_dist_y += cub3d->delta_dist_y;
			cub3d->map_y += cub3d->step_y;
			cub3d->side = 1;
			x_or_y = 1;
		}
		if (cub3d->map[cub3d->map_y][cub3d->map_x] == '1')
		{
			cub3d->hit = 1;
			which_texture(cub3d, x_or_y);
		}
	}
}

void	calc_dist(t_cub3d *cub3d)
{
	if (cub3d->side == 0)
		cub3d->ray_length = (cub3d->side_dist_x - cub3d->delta_dist_x);
	else
		cub3d->ray_length = (cub3d->side_dist_y - cub3d->delta_dist_y);
	cub3d->line_height = (int)(SCREENHEIGHT / cub3d->ray_length);
	cub3d->start_end[0] = -cub3d->line_height / 2 + SCREENHEIGHT / 2;
	if (cub3d->start_end[0] < 0)
		cub3d->start_end[0] = 0;
	cub3d->start_end[1] = cub3d->line_height / 2 + SCREENHEIGHT / 2;
	if (cub3d->start_end[1] >= SCREENHEIGHT)
		cub3d->start_end[1] = SCREENHEIGHT - 1;
}
