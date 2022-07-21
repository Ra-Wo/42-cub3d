/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:46:01 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:15:25 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	add_pixel(int x, int y, t_cub3d *cube3d, int color)
{
	int	x_;
	int	y_;

	y_ = 0;
	while (y_ < SIZE_MINI_MAP)
	{
		x_ = 0;
		while (x_ < SIZE_MINI_MAP)
		{
			my_mlx_pixel_put(cube3d, (x + x_), (y + y_), color);
			x_++;
		}
		y_++;
	}
}

void	render_mini_map(t_cub3d *cube3d)
{
	int	x;
	int	y;

	y = 0;
	while (cube3d->map[y])
	{
		x = 0;
		while (cube3d->map[y][x])
		{
			if (cube3d->map[y][x] == '1')
				add_pixel((x * SIZE_MINI_MAP + 5), (y * SIZE_MINI_MAP + 5),
					cube3d, create_trgb(78, 8, 255));
			else if (cube3d->map[y][x] == '0' || cube3d->map[y][x] == 'W'
					|| cube3d->map[y][x] == 'E' || cube3d->map[y][x] == 'S'
					|| cube3d->map[y][x] == 'N')
				add_pixel((x * SIZE_MINI_MAP + 5),
					(y * SIZE_MINI_MAP + 5), cube3d, create_trgb(9, 0, 71));
			x++;
		}
		y++;
	}
}

void	add_player_to_map2d(t_cub3d *cub3d)
{
	add_pixel((cub3d->player->pos_x * (SIZE_MINI_MAP)) + SIZE_MINI_MAP / 2,
		(cub3d->player->pos_y * SIZE_MINI_MAP) + SIZE_MINI_MAP / 2,
		cub3d, 0xfcba03);
}
