/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:41:28 by lserrao-          #+#    #+#             */
/*   Updated: 2024/11/01 11:55:16 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_ptr;

	if (!lst)
		return ;
	lst_ptr = lst;
	while (lst_ptr != NULL)
	{
		(*f)(lst_ptr->content);
		lst_ptr = lst_ptr->next;
	}
}
