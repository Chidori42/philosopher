/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:17:13 by ael-fagr          #+#    #+#             */
/*   Updated: 2023/11/19 05:42:54 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*start;
	int		i;

	if (lst == NULL)
		return (0);
	start = lst;
	i = 0;
	while (start -> next != NULL)
	{
		start = start -> next;
		i++;
	}
	return (start);
}
