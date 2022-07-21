/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:01:47 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:30:39 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	up(t_cub3d *cube3d, float ms)
{
	if (cube3d->map[(int)cube3d->player->pos_y]
		[(int)(cube3d->player->pos_x + cube3d->player->dir_x * 0.5)] != '1')
			cube3d->player->pos_x += cube3d->player->dir_x * ms;
	if (cube3d->map[(int)(cube3d->player->pos_y + cube3d->player->dir_y * 1)]
		[(int)cube3d->player->pos_x] != '1')
		cube3d->player->pos_y += cube3d->player->dir_y * ms;
}

static void	down(t_cub3d *cube3d, float ms)
{
	if (cube3d->map[(int)cube3d->player->pos_y]
		[(int)(cube3d->player->pos_x - cube3d->player->dir_x * 0.5)] != '1')
			cube3d->player->pos_x -= cube3d->player->dir_x * ms;
	if (cube3d->map[(int)(cube3d->player->pos_y - cube3d->player->dir_y * 1)]
		[(int)cube3d->player->pos_x] != '1')
		cube3d->player->pos_y -= cube3d->player->dir_y * ms;
}

static void	left(t_cub3d *cube3d, float ms)
{
	if (cube3d->map[(int)cube3d->player->pos_y]
		[(int)(cube3d->player->pos_x - cube3d->player->plane_x * 0.5)] != '1')
			cube3d->player->pos_x -= cube3d->player->plane_x * ms;
	if (cube3d->map[(int)(cube3d->player->pos_y - cube3d->player->plane_y * ms)]
		[(int)cube3d->player->pos_x] != '1')
		cube3d->player->pos_y -= cube3d->player->plane_y * ms;
}

static void	right(t_cub3d *cube3d, float ms)
{
	if (cube3d->map[(int)cube3d->player->pos_y]
		[(int)(cube3d->player->pos_x + cube3d->player->plane_x * 0.5)] != '1')
			cube3d->player->pos_x += cube3d->player->plane_x * ms;
	if (cube3d->map[(int)(cube3d->player->pos_y + cube3d->player->plane_y * ms)]
		[(int)cube3d->player->pos_x] != '1')
		cube3d->player->pos_y += cube3d->player->plane_y * ms;
}

void	handle_player_movement(t_cub3d *cube3d)
{
	float	move_speed;

	move_speed = cube3d->player->move_speed;
	if (cube3d->keys->w == 1)
		up(cube3d, move_speed);
	if (cube3d->keys->s == 1)
		down(cube3d, move_speed);
	if (cube3d->keys->a == 1)
		left(cube3d, move_speed);
	if (cube3d->keys->d == 1)
		right(cube3d, move_speed);
}
