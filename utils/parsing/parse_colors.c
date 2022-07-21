/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:27:51 by akremcht          #+#    #+#             */
/*   Updated: 2022/06/07 13:34:40 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	fill_colors(t_file *file, char *str, char **splitted)
{
	if (str[0] == 'F')
	{
		file->f[0] = ft_atoi(splitted[0]);
		file->f[1] = ft_atoi(splitted[1]);
		file->f[2] = ft_atoi(splitted[2]);
	}
	else
	{
		file->c[0] = ft_atoi(splitted[0]);
		file->c[1] = ft_atoi(splitted[1]);
		file->c[2] = ft_atoi(splitted[2]);
	}
	arr_free(splitted);
}

static int	is_valid_colors(char **arr)
{
	int	i;
	int	x;
	int	num;

	if (!arr)
		return (0);
	i = -1;
	while (arr[++i])
	{
		x = -1;
		while (arr[i][++x])
			if (!ft_isdigit(arr[i][x]) && !ft_isspace(arr[i][x]))
				return (0);
		if (ft_strlen(arr[i] + rmf_spcs_i(arr[i])) == 0)
			return (0);
		num = ft_atoi(arr[i]);
		if (!arr[i] || num > 255 || num < 0)
			return (0);
	}
	return (1);
}

int	check_colors(t_file *file, int check)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (check == 0 && (file->f[i] == -1 || file->c[i] == -1))
			return (0);
		if (check == 1 && file->f[i] == -1)
			return (0);
		if (check == 2 && file->c[i] == -1)
			return (0);
	}
	return (1);
}

int	parse_rgb_colors(t_file *file, char *str)
{
	char	**splitted;

	if (count_c_in_str(str, ',') == 2 && (str[0] == 'F' || str[0] == 'C')
		&& ft_isspace(str[1]))
	{
		if ((str[0] == 'F' && check_colors(file, 1))
			|| (str[0] == 'C' && check_colors(file, 2)))
			return (file->c[0] = -1, file->f[0] = -1, 0);
		splitted = ft_split(str + 2, ',');
		if (!splitted)
			return (0);
		if (arr_len(splitted) != 3 || !is_valid_colors(splitted))
			free(splitted);
		else
			fill_colors(file, str, splitted);
	}
	return (1);
}
