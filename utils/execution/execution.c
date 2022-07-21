/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:44:36 by roudouch          #+#    #+#             */
/*   Updated: 2022/06/08 10:35:14 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	execution(t_file *file)
{
	t_cub3d		cub3d;

	init_screen(&cub3d, "Cube3D");
	init(&cub3d, file);
	mlx_loop_hook(cub3d.mlx, render, &cub3d);
	mlx_hook(cub3d.mlx_win, 17, 0, close_window, &cub3d);
	mlx_hook(cub3d.mlx_win, 3, 2, key_release, &cub3d);
	mlx_hook(cub3d.mlx_win, 2, 1, key_press, &cub3d);
	mlx_loop(cub3d.mlx);
	return (0);
}
