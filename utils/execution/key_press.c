/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:55:27 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:22:46 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	check_key(t_cub3d *cube3d)
{
	handle_camera(cube3d);
	handle_player_movement(cube3d);
}

int	key_press(int keycode, t_cub3d *cube3d)
{
	if (keycode == 53)
		close_window(cube3d);
	if (keycode == 13)
		cube3d->keys->w = 1;
	if (keycode == 1)
		cube3d->keys->s = 1;
	if (keycode == 0)
		cube3d->keys->a = 1;
	if (keycode == 2)
		cube3d->keys->d = 1;
	if (keycode == 123)
		cube3d->keys->left = 1;
	if (keycode == 124)
		cube3d->keys->right = 1;
	return (0);
}

int	key_release(int keycode, t_cub3d *cube3d)
{
	if (keycode == 13)
		cube3d->keys->w = 0;
	if (keycode == 1)
		cube3d->keys->s = 0;
	if (keycode == 0)
		cube3d->keys->a = 0;
	if (keycode == 2)
		cube3d->keys->d = 0;
	if (keycode == 123)
		cube3d->keys->left = 0;
	if (keycode == 124)
		cube3d->keys->right = 0;
	return (0);
}
