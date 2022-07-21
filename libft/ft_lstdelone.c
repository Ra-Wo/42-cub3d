/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:36:12 by akremcht          #+#    #+#             */
/*   Updated: 2022/04/11 11:30:51 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone(t_parm_lst *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
	{
		del(lst->content);
		del(lst->output_redirect);
		del(lst->input_redirect);
	}
	free(lst);
}
