/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:04:56 by akremcht          #+#    #+#             */
/*   Updated: 2022/05/31 01:43:07 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(char *joined, char *str)
{
	int		i;
	int		x;
	char	*temp;

	if (!joined)
	{
		joined = malloc(1 * sizeof(char));
		if (!joined)
			return (0);
		joined[0] = '\0';
	}
	temp = malloc(sizeof(char) * (ft_strlen(joined) + ft_strlen(str) + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (joined[++i])
		temp[i] = joined[i];
	x = 0;
	while (str[x] && str)
		temp[i++] = str[x++];
	temp[i] = '\0';
	return (free(joined), temp);
}

static int	has_newline(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

static char	*fill_lines(int fd, char *saved)
{
	char	*str;
	int		len;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (0);
	len = 1;
	while (len > 0 && !has_newline(saved))
	{
		len = read(fd, str, BUFFER_SIZE);
		if (len < 0)
			return (free(str), NULL);
		str[len] = '\0';
		saved = join_str(saved, str);
	}
	return (free(str), saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!has_newline(saved))
		saved = fill_lines(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line(saved);
	saved = get_rest(saved);
	return (line);
}
