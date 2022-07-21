/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:51:20 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:56:51 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	load_texture(t_cub3d *cub, char *path, t_texture *texture)
{
	texture->img = mlx_xpm_file_to_image(cub->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
		free_and_exit(cub, "Error: invalid texture.\n");
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->data || texture->width != texture->height
		|| texture->height > 100)
		free_and_exit(cub, "Error: invalid texture.\n");
}

void	load_all_texture(t_cub3d *cub, t_file *file)
{
	load_texture(cub, file->west, &cub->texture[WEST]);
	load_texture(cub, file->east, &cub->texture[EAST]);
	load_texture(cub, file->north, &cub->texture[NORTH]);
	load_texture(cub, file->south, &cub->texture[SOUTH]);
}
