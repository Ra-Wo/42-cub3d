/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:12:09 by akremcht          #+#    #+#             */
/*   Updated: 2021/11/16 10:39:31 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_found(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*check_malloc(int endlen, int startlen)
{
	if (endlen < 0)
		return (malloc (1));
	else
		return (malloc ((endlen - startlen + 2) * sizeof(char)));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		startlen;
	int		endlen;
	char	*str;

	if (!s1)
		return (0);
	startlen = 0;
	endlen = ft_strlen(s1) - 1;
	while (is_found(s1[startlen], set) && s1[startlen])
		startlen++;
	while (is_found(s1[endlen], set) && endlen >= 0)
		endlen--;
	str = check_malloc(endlen, startlen);
	if (!str)
		return (0);
	i = -1;
	while (s1[++i + startlen] && i < (endlen - startlen + 1))
		str[i] = s1[i + startlen];
	str[i] = '\0';
	return (str);
}
