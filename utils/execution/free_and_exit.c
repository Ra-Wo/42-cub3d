/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:55:14 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:44:12 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	free_and_exit(t_cub3d *cub3d, char *msg)
{
	free(cub3d->texture);
	free(cub3d->player);
	free(cub3d->keys);
	if (cub3d->file)
		free_file(cub3d->file);
	if (msg)
	{
		printf("%s\n", msg);
		exit(1);
	}
	else
		exit(0);
}
