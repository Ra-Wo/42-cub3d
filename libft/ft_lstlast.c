/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:01:49 by akremcht          #+#    #+#             */
/*   Updated: 2022/02/19 17:16:19 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_parm_lst	*ft_lstlast(t_parm_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
