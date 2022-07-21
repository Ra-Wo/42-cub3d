/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:48:15 by akremcht          #+#    #+#             */
/*   Updated: 2021/11/16 11:33:23 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlencpy;
	size_t	srclen;
	size_t	destlen;

	dstlencpy = ft_strlen(dest);
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (dstsize <= destlen)
		return (dstsize + srclen);
	i = -1;
	while (src[++i] && dstlencpy < dstsize - 1)
		dest[dstlencpy++] = src[i];
	dest[dstlencpy] = '\0';
	return (destlen + srclen);
}
