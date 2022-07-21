/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:30:47 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:31:17 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	left(t_cub3d *cube3d, float rotate_speed)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = cube3d->player->dir_x;
	cube3d->player->dir_x = cube3d->player->dir_x * cos(-rotate_speed)
		- cube3d->player->dir_y * sin(-rotate_speed);
	cube3d->player->dir_y = old_dir_x * sin(-rotate_speed)
		+ cube3d->player->dir_y * cos(-rotate_speed);
	old_plane_x = cube3d->player->plane_x;
	cube3d->player->plane_x = cube3d->player->plane_x * cos(-rotate_speed)
		- cube3d->player->plane_y * sin(-rotate_speed);
	cube3d->player->plane_y = old_plane_x * sin(-rotate_speed)
		+ cube3d->player->plane_y * cos(-rotate_speed);
}

static void	right(t_cub3d *cube3d, float rotate_speed)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = cube3d->player->dir_x;
	cube3d->player->dir_x = cube3d->player->dir_x * cos(rotate_speed)
		- cube3d->player->dir_y * sin(rotate_speed);
	cube3d->player->dir_y = old_dir_x * sin(rotate_speed)
		+ cube3d->player->dir_y * cos(rotate_speed);
	old_plane_x = cube3d->player->plane_x;
	cube3d->player->plane_x = cube3d->player->plane_x * cos(rotate_speed)
		- cube3d->player->plane_y * sin(rotate_speed);
	cube3d->player->plane_y = old_plane_x * sin(rotate_speed)
		+ cube3d->player->plane_y * cos(rotate_speed);
}

void	handle_camera(t_cub3d *cube3d)
{
	float	rotate_speed;

	rotate_speed = cube3d->player->rot_speed;
	if (cube3d->keys->left == 1)
		left(cube3d, rotate_speed);
	if (cube3d->keys->right == 1)
		right(cube3d, rotate_speed);
}
