/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:25:39 by akremcht          #+#    #+#             */
/*   Updated: 2022/06/04 20:44:49 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	check_objects(char c, int check_everything)
{
	int	is_player;

	is_player = (c == 'N' || c == 'S' || c == 'W' || c == 'E');
	if (check_everything)
		return (!is_player
			&& (c != ' ' && c != '\n' && c != '0' && c != '1'));
	return (is_player);
}

static int	is_exist(char **map, int y, int x)
{
	if (y >= arr_len(map) || (size_t)x >= ft_strlen(map[y]))
		return (0);
	return (map[y][x] == ' ' || map[y][x] == '\n');
}

static int	check_borders(char **map, int y, int x)
{
	return (y == 0 || y == arr_len(map) - 1
		|| is_exist(map, y + 1, x) || is_exist(map, y - 1, x)
		|| is_exist(map, y, x + 1) || is_exist(map, y, x - 1)
		|| is_exist(map, y + 1, x + 1) || is_exist(map, y - 1, x - 1)
		|| is_exist(map, y - 1, x + 1) || is_exist(map, y + 1, x - 1));
}

static int	assign_player(t_file *file, int x, int y)
{
	if (file->dir)
		return (0);
	file->pos_x = (float)x;
	file->pos_y = (float)y;
	file->dir = file->map[y][x];
	return (1);
}

int	check_map(t_file *file)
{
	int	y;
	int	x;

	y = -1;
	while (file->map && file->map[++y])
	{
		x = -1;
		while (file->map[y][++x])
		{
			if (check_objects(file->map[y][x], 1))
				return (print_errors(6), 0);
			if ((file->map[y][x] == '0' || check_objects(file->map[y][x], 0))
				&& check_borders(file->map, y, x))
				return (print_errors(7), 0);
			if (check_objects(file->map[y][x], 0) && !assign_player(file, x, y))
				return (print_errors(8), 0);
		}
	}
	if (!file->dir)
		return (print_errors(9), 0);
	return (1);
}
