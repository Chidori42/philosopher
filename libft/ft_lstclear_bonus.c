/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:21:08 by ael-fagr          #+#    #+#             */
/*   Updated: 2023/11/19 06:34:14 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*index;
	t_list	*temp;

	if (!lst || !del)
		return ;
	index = (*lst);
	while (index)
	{
		temp = index->next;
		ft_lstdelone(index, del);
		index = temp;
	}
	*lst = NULL;
}
