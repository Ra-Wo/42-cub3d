/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:56:20 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:47:37 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	init_keys(t_cub3d *cub3d)
{
	t_keys	*keys;

	keys = malloc(sizeof(t_keys));
	if (!keys)
		free_and_exit(cub3d, "Malloc error");
	cub3d->keys = keys;
	cub3d->keys->w = 0;
	cub3d->keys->a = 0;
	cub3d->keys->s = 0;
	cub3d->keys->d = 0;
	cub3d->keys->left = 0;
	cub3d->keys->right = 0;
	cub3d->keys->esc = 0;
}

static void	init_player(t_cub3d *cub3d)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		free_and_exit(cub3d, "Malloc error");
	cub3d->player = player;
	cub3d->player->pos_x = (int)cub3d->file->pos_x + 1;
	cub3d->player->pos_y = (int)cub3d->file->pos_y + 1;
	cub3d->player->direction = cub3d->file->dir;
	cub3d->player->move_speed = 0.08;
	cub3d->player->rot_speed = 0.04;
	set_direction_of_player(cub3d);
}

static void	init_textures(t_cub3d *cub3d)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture) * 4);
	if (!texture)
		free_and_exit(cub3d, "Malloc error");
	cub3d->texture = texture;
	load_all_texture(cub3d, cub3d->file);
}

void	init(t_cub3d *cub3d, t_file *file)
{
	cub3d->player = NULL;
	cub3d->texture = NULL;
	cub3d->keys = NULL;
	cub3d->file = file;
	init_textures(cub3d);
	init_keys(cub3d);
	init_player(cub3d);
	cub3d->map = file->map;
	cub3d->floor_color = create_trgb(file->f[0], file->f[1], file->f[2]);
	cub3d->ceil_color = create_trgb(file->c[0], file->c[1], file->c[2]);
}
