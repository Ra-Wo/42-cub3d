/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:28:18 by akremcht          #+#    #+#             */
/*   Updated: 2022/04/11 11:30:51 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_parm_lst	*ft_lstnew(char **content)
{
	t_parm_lst	*lst;

	lst = malloc(sizeof(t_parm_lst));
	if (!lst)
		return (0);
	lst->content = content;
	lst->output_redirect = NULL;
	lst->input_redirect = NULL;
	lst->next = NULL;
	return (lst);
}
