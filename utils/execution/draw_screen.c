/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:57:33 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:45:48 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	draw_line(int x, int *start_end, t_cub3d *cube3d, int texture_num)
{
	int	y;

	y = 0;
	init_color(cube3d, texture_num);
	y = 0;
	while (y < SCREENHEIGHT)
	{
		if (y < start_end[0])
			my_mlx_pixel_put(cube3d, x, y, cube3d->ceil_color);
		if (y > start_end[0] && y < start_end[1])
		{
			cube3d->tex_y
				= (int)cube3d->tex_pos % cube3d->texture[texture_num].height;
			my_mlx_pixel_put(cube3d, (x), (y),
				get_color(&cube3d->texture[texture_num],
					cube3d->tex_x, cube3d->tex_y));
			cube3d->tex_pos += cube3d->step;
		}
		if (y > start_end[1])
			my_mlx_pixel_put(cube3d, x, y, cube3d->floor_color);
		y = y + 1;
	}
}

void	draw_screen(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < SCREENWIDTH)
	{
		init_vars(cub3d, i);
		init_dist(cub3d);
		wall_collision_for_ray(cub3d);
		calc_dist(cub3d);
		draw_line(i, cub3d->start_end, cub3d, cub3d->tex_n);
		i++;
	}
}
