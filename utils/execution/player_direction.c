/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:28:29 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:57:40 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	east_west(t_cub3d *cub3d)
{
	if (cub3d->player->direction == 'E')
	{
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
		cub3d->player->plane_x = 0;
		cub3d->player->plane_y = 0.66;
	}
	else if (cub3d->player->direction == 'W')
	{
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
		cub3d->player->plane_x = 0;
		cub3d->player->plane_y = -0.66;
	}
}

static void	north_south(t_cub3d *cub3d)
{
	if (cub3d->player->direction == 'N')
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
		cub3d->player->plane_x = 0.66;
		cub3d->player->plane_y = 0;
	}
	else if (cub3d->player->direction == 'S')
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
		cub3d->player->plane_x = -0.66;
		cub3d->player->plane_y = 0;
	}
}

void	set_direction_of_player(t_cub3d *cub3d)
{
	east_west(cub3d);
	north_south(cub3d);
}
