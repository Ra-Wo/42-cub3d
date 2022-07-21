/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   everyframe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:49:48 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:58:58 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	render(t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->mlx, cub3d->mlx_win);
	draw_screen(cub3d);
	render_mini_map(cub3d);
	add_player_to_map2d(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->mlx_win, cub3d->img, 0, 0);
	check_key(cub3d);
	return (0);
}
