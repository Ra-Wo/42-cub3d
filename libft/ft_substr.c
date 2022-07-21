/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:40:54 by akremcht          #+#    #+#             */
/*   Updated: 2022/04/07 13:01:26 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				x;
	int				i;
	char			*ptr;
	unsigned int	s_length;

	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	if (start > s_length)
		len = 0;
	if (len > s_length)
		len = s_length - start;
	i = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	x = len;
	while (x--)
	{
		ptr[i++] = *(s + start);
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
