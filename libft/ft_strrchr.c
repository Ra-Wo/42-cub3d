/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:03:47 by akremcht          #+#    #+#             */
/*   Updated: 2021/11/16 10:46:08 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last_found;

	i = 0;
	last_found = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_found = (char *)s + i;
		i++;
	}
	if (!c)
		return ((char *)s + i);
	return (last_found);
}
