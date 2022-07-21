/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:02:09 by akremcht          #+#    #+#             */
/*   Updated: 2022/02/19 17:15:29 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_parm_lst *lst, void (*f)(void *))
{
	while (lst)
	{
		if (f)
			f(lst->content);
		lst = lst->next;
	}
}
