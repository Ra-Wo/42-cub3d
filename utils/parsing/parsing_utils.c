/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:30:09 by akremcht          #+#    #+#             */
/*   Updated: 2022/06/04 12:57:38 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	count_c_in_str(char *str, char c)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == c)
			count++;
	return (count);
}

int	rmf_spcs_i(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

int	rml_spcs_i(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 0)
		return (0);
	while (i >= 0 && str[i] && (ft_isspace(str[i]) || str[i] == '\n'))
		i--;
	return (i);
}
