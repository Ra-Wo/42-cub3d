/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:21:09 by akremcht          #+#    #+#             */
/*   Updated: 2022/02/19 20:28:03 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (!needle || !haystack)
		return (0);
	if (needle[i] && len == 0)
		return (0);
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		x = 0;
		while (needle[x] == haystack[i + x] && needle[x] && i + x < len)
			x++;
		if (!needle[x])
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
