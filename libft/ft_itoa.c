/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:08:27 by akremcht          #+#    #+#             */
/*   Updated: 2022/03/21 16:06:06 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	calcul_len(int n)
{
	int	i;
	int	nb;

	i = 0;
	nb = n;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*convert_to_str(unsigned int nb, int len, int isnegotive)
{
	int		i;
	char	*converted;

	converted = malloc(sizeof(char) * (len + 1));
	if (!converted)
		return (0);
	i = len;
	while (--i >= 0)
	{
		if (isnegotive && i == 0)
		{
			converted[i] = '-';
			continue ;
		}
		converted[i] = (nb % 10) + 48;
		nb /= 10;
	}
	converted[len] = '\0';
	return (converted);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				len;

	nb = n;
	if (n < 0)
		nb = -n;
	len = calcul_len(nb);
	if (n <= 0)
		len++;
	return (convert_to_str(nb, len, n < 0));
}
