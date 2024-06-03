/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:05:26 by ael-fagr          #+#    #+#             */
/*   Updated: 2023/11/19 05:08:07 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*start;
	int		i;

	if (lst == NULL)
		return (0);
	start = lst;
	i = 0;
	while (start != NULL)
	{
		start = start -> next;
		i++;
	}
	return (i);
}
