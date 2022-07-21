/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:48:45 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:42:32 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

/* 
	what function does:
		- detroy the window.
		- destroy the image.
		- exit the program
	Parameters:
		- cube3d: structure of the cube3d
	return :
		- the program exit with 0. (success)
*/
int	close_window(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->mlx_win);
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	exit(0);
}
