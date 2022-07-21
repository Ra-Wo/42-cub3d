/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:15:46 by akremcht          #+#    #+#             */
/*   Updated: 2022/06/04 20:43:54 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	check_parsed_file(t_file *file, int should_check)
{
	int	i;

	if (!file->north || !file->south || !file->east || !file->west)
		return (print_errors(4), 0);
	i = -1;
	while (++i < 3)
		if (file->f[i] == -1 || file->c[i] == -1)
			return (print_errors(2), 0);
	if (should_check && !file->map)
		return (print_errors(5), 0);
	if (!file->map_len)
		return (print_errors(5), 0);
	return (1);
}

void	free_file(t_file *file)
{
	int	i;

	if (!file)
		return ;
	arr_free(file->map);
	file->map = NULL;
	free(file->north);
	free(file->south);
	free(file->east);
	free(file->west);
	file->north = NULL;
	file->south = NULL;
	file->east = NULL;
	file->west = NULL;
	i = -1;
	while (++i < 3)
	{
		file->f[i] = -1;
		file->c[i] = -1;
	}
	free(file);
}

static int	alloc_map(t_file *file)
{
	file->map = ft_calloc(file->map_len + 1, sizeof(char *));
	if (!file->map)
		return (0);
	return (1);
}

static t_file	*parse_cub_file(int fd, t_file *file, int is_read, char *path)
{
	char	*str;

	if (!is_read && !alloc_map(file))
		return (free_file(file), NULL);
	while (file)
	{
		str = get_next_line(fd);
		if (!str || (is_read && (!parse_paths(file, str + rmf_spcs_i(str))
					|| !parse_rgb_colors(file, str + rmf_spcs_i(str)))))
			break ;
		if (!read_map(file, str, is_read))
			return (free_file(file), NULL);
		free(str);
	}
	if (!check_parsed_file(file, !is_read))
		return (free_file(file), NULL);
	if (file->map_len && is_read)
		return (close(fd), parse_cub_file(open(path, O_RDONLY), file, 0, path));
	if (!check_map(file))
		return (free_file(file), NULL);
	return (file);
}

t_file	*initialize_file(int fd, char *map_path)
{
	t_file	*new_file;
	int		i;

	new_file = malloc(sizeof(t_file));
	if (!new_file)
		return (print_errors(3), NULL);
	i = -1;
	while (++i < 3)
	{
		new_file->f[i] = -1;
		new_file->c[i] = -1;
	}
	new_file->north = NULL;
	new_file->south = NULL;
	new_file->west = NULL;
	new_file->east = NULL;
	new_file->map = NULL;
	new_file->map_len = 0;
	new_file->pos_x = 0;
	new_file->pos_y = 0;
	new_file->dir = '\0';
	return (parse_cub_file(fd, new_file, 1, map_path));
}
