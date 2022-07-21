/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:23:24 by akremcht          #+#    #+#             */
/*   Updated: 2022/03/02 19:59:16 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordslen_space(char const *s, char c)
{
	int	i;
	int	wdslen;

	i = 0;
	wdslen = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wdslen++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (wdslen);
}

static int	check_for_splits_space(char const *s, char c, char **arr)
{
	int		i;
	int		arrlen;
	int		last;

	i = 0;
	arrlen = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			last = i;
			while (s[i] != c && s[i])
				i++;
			arr[arrlen] = malloc(i - last + 1);
			if (!arr[arrlen])
				return (0);
			ft_strlcpy(arr[arrlen++], s + last, i - last + 1);
		}
		else
			i++;
	}
	arr[arrlen] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (wordslen_space(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!check_for_splits_space(s, c, arr))
	{
		i = -1;
		while (arr[++i])
			free(arr[i]);
		free(arr);
		return (NULL);
	}
	return (arr);
}
