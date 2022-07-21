/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:48:20 by akremcht          #+#    #+#             */
/*   Updated: 2022/03/04 15:16:48 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*joined;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joined = malloc(s1len + s2len + 1);
	if (!joined)
		return (0);
	ft_memmove(joined, s1, s1len);
	ft_memmove(joined + s1len, s2, s2len);
	joined[s1len + s2len] = 0;
	return (joined);
}
