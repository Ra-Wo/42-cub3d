/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:58:10 by akremcht          #+#    #+#             */
/*   Updated: 2021/11/10 14:45:48 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while ((char)s[i])
	{
		if ((char)s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (!c)
		return (((char *)s + i));
	return (0);
}
