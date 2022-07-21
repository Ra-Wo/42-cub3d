/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:57:20 by akremcht          #+#    #+#             */
/*   Updated: 2021/11/16 09:53:31 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!src && !dest)
		return (0);
	if (src > dest)
		ft_memcpy(dest, src, len);
	else
		while (len--)
			((char *)dest)[len] = ((char *)src)[len];
	return (dest);
}
