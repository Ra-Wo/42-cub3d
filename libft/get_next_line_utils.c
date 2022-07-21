/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:04:51 by akremcht          #+#    #+#             */
/*   Updated: 2022/05/23 19:08:33 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char *saved)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	if (!saved[0] || !saved)
		return (NULL);
	while (saved[len] && saved[len] != '\n')
		len++;
	if (saved[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = saved[i];
	line[len] = '\0';
	return (line);
}

char	*get_rest(char *saved)
{
	int		start;
	int		i;
	char	*rest;

	start = 0;
	if (!saved)
		return (NULL);
	while (saved[start] && saved[start] != '\n')
			start++;
	if (saved[start] == '\n')
		start++;
	if (!saved[start])
		return (free(saved), NULL);
	rest = malloc(sizeof(char) * (ft_strlen(saved) - start + 1));
	if (!rest)
		return (free(saved), NULL);
	i = -1;
	while (saved[++i + start])
		rest[i] = saved[start + i];
	rest[i] = '\0';
	return (free(saved), rest);
}
