/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:41:45 by akremcht          #+#    #+#             */
/*   Updated: 2022/02/19 17:15:21 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_parm_lst **lst, void (*del)(void*))
{
	t_parm_lst	*next_cpy;

	if (!lst)
		return ;
	while (*lst)
	{
		next_cpy = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_cpy;
	}
}
