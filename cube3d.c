/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:22:10 by akremcht          #+#    #+#             */
/*   Updated: 2022/06/08 10:58:37 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static	int	check_dot_cub(char *filename)
{
	char	**splitted;
	int		i;

	splitted = ft_split(filename, '.');
	if (!splitted)
		return (0);
	i = -1;
	if (ft_strncmp(splitted[arr_len(splitted) - 1], "cub",
			ft_strlen(splitted[arr_len(splitted) - 1])))
		return (arr_free(splitted), 0);
	return (arr_free(splitted), 1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_file	*file;

	if (ac < 2 || !check_dot_cub(av[1]))
		return (print_errors(0), 2);
	fd = open(av[ac - 1], O_RDONLY);
	if (fd < 0)
		return (print_errors(1), 2);
	file = initialize_file(fd, av[ac - 1]);
	close(fd);
	if (!file)
		return (2);
	execution(file);
	return (0);
}
