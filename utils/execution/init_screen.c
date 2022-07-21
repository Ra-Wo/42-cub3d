/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:17 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:56:02 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	init_screen(t_cub3d *cub3d, char *title)
{
	cub3d->mlx = mlx_init();
	cub3d->mlx_win = mlx_new_window(cub3d->mlx,
			SCREENWIDTH, SCREENHEIGHT, title);
	cub3d->img = mlx_new_image(cub3d->mlx, SCREENWIDTH, SCREENHEIGHT);
	cub3d->addr = mlx_get_data_addr(cub3d->img,
			&cub3d->bits_per_pixel, &cub3d->line_length, &cub3d->endian);
}
