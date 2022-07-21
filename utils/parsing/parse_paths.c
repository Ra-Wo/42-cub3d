/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:39:12 by akremcht          #+#    #+#             */
/*   Updated: 2022/06/04 12:57:46 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	is_texture(char *str)
{
	if (str[0] == 'N' && str[1] == 'O' )
		return (1);
	else if (str[0] == 'S' && str[1] == 'O')
		return (2);
	else if (str[0] == 'W' && str[1] == 'E')
		return (3);
	else if (str[0] == 'E' && str[1] == 'A')
		return (4);
	return (0);
}

static int	fill_textures(t_file *file, char *str, int start)
{
	char	*path;

	path = ft_substr(str, start, rml_spcs_i(str + start) + 1);
	if (!path)
		return (0);
	if (is_texture(str) == 1)
		file->north = path;
	else if (is_texture(str) == 2)
		file->south = path;
	else if (is_texture(str) == 3)
		file->west = path;
	else if (is_texture(str) == 4)
		file->east = path;
	return (1);
}

int	parse_paths(t_file *file, char *str)
{
	int		start;

	if (str[0] && str[0] != '\n' && str[0] != 'F' && str[0] != 'C'
		&& !is_texture(str) && !file->north && !file->south
		&& !file->west && !file->east)
		return (0);
	if (ft_strlen(str) > 3 && is_texture(str) && ft_isspace(str[2]))
	{
		start = rmf_spcs_i(str + 2) + 2;
		if (ft_strlen(str + start) > 1)
		{
			if ((is_texture(str) == 1 && file->north)
				|| (is_texture(str) == 2 && file->south)
				|| (is_texture(str) == 3 && file->west)
				|| (is_texture(str) == 4 && file->east))
				return (0);
			return (fill_textures(file, str, start));
		}
	}
	return (1);
}

int	read_map(t_file *file, char *str, int is_read)
{
	int	i;

	if (!file->south || !file->west || !file->east
		|| !file->north || !check_colors(file, 0))
		return (1);
	if (ft_strlen(str + rmf_spcs_i(str)) == 0
		|| ((str + rmf_spcs_i(str))[0] != '1'
		&& (str + rmf_spcs_i(str))[0] != '0'))
	{
		if (is_read && file->map_len != 0)
			return (print_errors(5), 0);
		return (1);
	}
	if (is_read)
		return (file->map_len++, 1);
	i = 0;
	while (file->map[i])
		i++;
	file->map[i] = ft_strdup(str);
	if (!file->map[i])
		return (print_errors(3), 0);
	file->map[i + 1] = NULL;
	return (1);
}
